#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Node
{
    ll x;
    int y;
    Node *left, *right;
    int sz;
    ll minn;
    Node(ll x):
        x(x),
        y(((rand() << 15) | rand())),
        left(0),
        right(0),
        sz(1),
        minn(x) {}
};

const ll INF = 1e13;

int sz(Node *v)
{
    return (v ? v->sz : 0);
}

ll minn(Node *v)
{
    return (v ? v->minn : INF);
}

void upd(Node *v)
{
    if (!v)
        return;
    v->sz = 1 + sz(v->right) + sz(v->left);
    v->minn = min(v->x, min(minn(v->left), minn(v->right)));
}

pair<Node*, Node*> split(Node *v, int k)
{
    if (!k)
        return {nullptr, v};
    if (sz(v->left) < k)
    {
        auto a = split(v->right, k - sz(v->left) - 1);
        v->right = a.first;
        upd(v);
        return {v, a.second};
    }
    auto a = split(v->left, k);
    v->left = a.second;
    upd(v);
    return {a.first, v};
}

Node* merge(Node *l, Node *r)
{
    if (!l || !r)
        return (l ? l : r);
    if (l->y < r->y)
    {
        r->left = merge(l, r->left);
        upd(r);
        return r;
    }
    l->right = merge(l->right, r);
    upd(l);
    return l;
}

const int N = 100001;

ll a[N], b[N];

int n;

void greedy(ll curans)
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
         int type, l, r;
        ll x;
        cin >> type >> l >> r >> x;
        l--;
        r--;
        if (type == 1)
        {
            ll ans = 0;
            if (l == 0)
            {
                curans -= abs(b[0]);
                ans = max(ans, curans + abs(b[0] -  x));
                curans += abs(b[0]);
                l++;
            }
            if (r == n - 1)
            {
                curans -= abs(b[n - 2]);
                ans = max(ans, curans + abs(b[n - 2] + x));
                curans += abs(b[n - 2]);
                r--;
            }
            for (int j = max(0, l - 1); j < r; j++)
            {
                curans -= abs(b[j]);
                curans -= abs(b[j + 1]);
                ans = max(ans, curans + abs(b[j] + x) + abs(b[j + 1] - x));
                curans += abs(b[j]);
                curans += abs(b[j + 1]);
            }
            cout << ans << "\n";
        }
        else
        {
            if (l)
            {
                curans -= abs(b[l - 1]);
                b[l - 1] += x;
                curans += abs(b[l - 1]);
            }
            if (r < n - 1)
            {
                curans -= abs(b[r]);
                b[r] -= x;
                curans += abs(b[r]);
            }

        }
    }
    cout << endl;
}


//int verygood = 0;

//set<ll> minpl;

//set<ll> plpl;

ll curans = 0;

Node *minpl = nullptr, *plpl = nullptr, *best = nullptr;

Node* upd(Node *v, int pos, ll val)
{
    auto a = split(v, pos);
    auto b = split(a.second, 1);
    v = merge(a.first, merge(new Node(val), b.second));
    return v;
}


void del(int ind)
{
  //  if (b[ind] >= 0 && b[ind + 1] <= 0)
    {
     //   verygood--;
        best = upd(best, ind, INF);
    }
 //   else if (b[ind] < 0 && b[ind + 1] > 0)
    {
        minpl = upd(minpl, ind, INF);
        //minpl.erase(abs(b[ind]) + abs(b[ind + 1]));
    }
  //  else if (b[ind] >= 0 && b[ind + 1] >= 0)
    {
        plpl = upd(plpl, ind, INF);
//        plpl.erase(b[ind + 1]);
    }
  //  else if (b[ind] <= 0 && b[ind + 1] <= 0)
    {
  //      plpl = upd(plpl, ind, INF);
        //plpl.erase(-b[ind + 1]);
    }

}

void push(int ind)
{
    if (b[ind] >= 0 && b[ind + 1] <= 0)
    {
   //     verygood++;
        best = upd(best, ind, 0);
    }
    else if (b[ind] < 0 && b[ind + 1] > 0)
    {
        minpl = upd(minpl, ind, abs(b[ind]) + abs(b[ind + 1]));
        //minpl.erase(abs(b[ind]) + abs(b[ind + 1]));
    }
    else if (b[ind] >= 0 && b[ind + 1] >= 0)
    {
        plpl = upd(plpl, ind, b[ind + 1]);
//        plpl.erase(b[ind + 1]);
    }
    else if (b[ind] <= 0 && b[ind + 1] <= 0)
    {
        plpl = upd(plpl, ind, -b[ind]);
        //plpl.erase(-b[ind + 1]);
    }

}


void upd(int ind, ll x)
{
    if (ind + 1 < n - 1)
        del(ind);
    if (ind)
        del(ind - 1);
    curans -= abs(b[ind]);
    b[ind] += x;
    curans += abs(b[ind]);
    if (ind + 1 < n - 1)
        push(ind);
    if (ind)
        push(ind - 1);
}

Node* findmin(Node *v, int l, int r, ll &ans)
{
    if (r == n - 1)
        r--;
    auto a = split(v, r + 1);
    auto b = split(a.first, l);
    ans = minn(b.second);
    v = merge(merge(b.first, b.second), a.second);
    return v;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i + 1 < n; i++)
    {
        b[i] = a[i + 1] - a[i];
       /* if (i)
        {
            if (b[i - 1] >= 0 && b[i] <= 0)
                best
            if (i && b[i - 1] < 0 && b[i]
        }*/
        minpl = merge(minpl, new Node(INF));
        plpl = merge(plpl, new Node(INF));
        best = merge(best, new Node(INF));
        curans += abs(b[i]);
    }
   // cout << curans << endl;
    if (1 && n < 10)
    {
        greedy(curans);
        return 0;
    }
    for (int i = 0; i + 2 < n; i++)
        push(i);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, l, r;
        ll x;
        cin >> type >> l >> r >> x;
        l--;
        r--;
        if (type == 1)
        {
            if (r - l < 10)
            {
                ll ans = 0;
                if (l == 0)
                {
                    curans -= abs(b[0]);
                    ans = max(ans, curans + abs(b[0] -  x));
                    curans += abs(b[0]);
                    l++;
                }
                if (r == n - 1)
                {
                    curans -= abs(b[n - 2]);
                    ans = max(ans, curans + abs(b[n - 2] + x));
                    curans += abs(b[n - 2]);
                    r--;
                }
                for (int j = max(0, l - 1); j < r; j++)
                {
                    curans -= abs(b[j]);
                    curans -= abs(b[j + 1]);
                    ans = max(ans, curans + abs(b[j] + x) + abs(b[j + 1] - x));
                    curans += abs(b[j]);
                    curans += abs(b[j + 1]);
                }
                cout << ans << "\n";
                continue;
            }
            ll ans = curans;
            if (l == 0)
            {
                curans -= abs(b[0]);
                ans = max(ans, curans + abs(b[0] -  x));
                curans += abs(b[0]);
                l++;
            }
            if (r == n - 1)
            {
                curans -= abs(b[n - 2]);
                ans = max(ans, curans + abs(b[n - 2] + x));
                curans += abs(b[n - 2]);
                r--;
            }
            l--;
            r--;
            if (l <= r)
            {
                ll kek = 0;
                best = findmin(best, l, r, kek);
                if (kek < INF)
                    ans = max(ans, curans + 2LL * x);

                plpl = findmin(plpl, l, r, kek);
                ans = max(ans, curans + 2LL * (x - kek));

                minpl = findmin(minpl, l, r, kek);
                ans = max(ans, curans + 2LL * (x - kek));
            }
            cout << ans << "\n";
        }
        else
        {
            if (l)
                upd(l - 1, x);
            if (r < n - 1)
                upd(r, -x);
        }
    }
    return 0;
}