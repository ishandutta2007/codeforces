#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef double ld;

const int N = 3000001;
const ll INF = 1e18;
ll c[N], a[N];
int l[N], r[N];
ll val[N];
ll dp[N];
vector<int> fin[N];
ll tree[N], push[N];



void buildtree(int v, int l, int r)
{
    if (r < l)
    {
        tree[v] = -INF;
        return;
    }
    if (l == r)
    {
        tree[v] = c[l];
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

void push1(int v)
{
    push[2 * v] += push[v];
    push[2 * v + 1] += push[v];
    tree[2 * v] += push[v];
    tree[2 * v + 1] += push[v];
    push[v] = 0;
}

void upd(int v, int l, int r, int ql, int qr, ll val)
{
    if (r < l)
        return;
    push1(v);
    if (ql > r || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tree[v] += val;
        push[v] += val;
        return;
    }
    int mid = (r + l) / 2;
    upd(2 * v, l, mid, ql, qr, val);
    upd(2 * v + 1, mid + 1, r, ql, qr, val);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

ll findmax(int v, int l, int r, int ql, int qr)
{
    if (r < l)
        return -INF;
    push1(v);
    if (ql > r || l > qr)
        return -INF;
    if (ql <= l && r <= qr)
        return tree[v];
    int mid = (r + l) / 2;
    return max(findmax(2 * v, l, mid, ql, qr), findmax(2 * v + 1, mid + 1, r, ql, qr));
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i], c[i] = a[i];
    for (int i = 1; i < n; i++)
        c[i] += c[i - 1];
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> val[i];
        l[i]--;
        r[i]--;
        fin[r[i]].push_back(i);
    }
    buildtree(1, 0, n - 1);
    ll pref = 0;
    for (int i = 0; i < n; i++)
    {
        ll now = 0;
        for (int t = 0; t < fin[i].size(); t++)
         {
            int j = fin[i][t];
            upd(1, 0, n - 1, 0, l[j] - 1, val[j]);
            if (l[j] == i)
                now += val[j];
            pref += val[j];
        }
        dp[i] = findmax(1, 0, n - 1, 0, i - 1) - c[i];
        dp[i] = max(dp[i], pref - c[i]);
        if (i)
            dp[i] = max(dp[i], dp[i - 1]);
        dp[i] = max(dp[i], 0LL);
        upd(1, 0, n - 1, i, i, dp[i] + c[i] - findmax(1, 0, n - 1, i, i));
    }
    cout << dp[n - 1];
 //   for (int i = 0; i < n; i++)
  //      cout << endl << dp[i];
    return 0;
}