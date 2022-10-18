#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>

#define sz(a) (int)((a).size())

using namespace std;

typedef long long ll;
typedef long double ld;

struct Tree
{
    Tree *left, *right;
    int val;
    Tree():
        left(0),
        right(0),
        val(0) {}
};

Tree* upd(Tree *v, int l, int r, int q, int val)
{
    if (r <= l || l > q || r <= q)
    {
        return v;
    }
    if (!v)
    {
        v = new Tree();
    }
    v->val += val;
    if (l + 1 == r)
    {
        return v;
    }
    int mid = (r + l) / 2;
    v->left = upd(v->left, l, mid, q, val);
    v->right = upd(v->right, mid, r, q, val);
    return v;
}

int find(Tree *v, int l, int r, int k)
{
    if (r <= l || r <= k || !v)
    {
        return 0;
    }
    if (l >= k)
    {
        return v->val;
    }
    int mid = (r + l) / 2;
    return find(v->left, l, mid, k) + find(v->right, mid, r, k);
}

const int N = 100001;
Tree *a[N];
vector<int> g[N], que[N], num[N];
map<int, int> q[N];
vector<int> c;
vector<int> sz;
int tree[N];
vector<int> ans;
int cnt = 0;
int n;

void dfs(int v, int pr)
{
   // cout << pr << "->" << v << endl;
    sz[v] = 1;
    int best = -1;
    for (int u : g[v])
    {
        if (u == pr)
        {
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
        if (best == -1 || sz[u] > sz[best])
        {
            best = u;
        }
    }
    if (best == -1)
    {
        tree[v] = cnt++;   
    }
    else
    {
        tree[v] = tree[best];
    }
    for (int u : g[v])
    {
        if (u != best && u != pr)
        {
            for (auto it : q[tree[u]])
            {
                int x = q[tree[v]][it.first];
                if (x)
                {
                    a[tree[v]] = upd(a[tree[v]], 1, n, x, -1);
                }
                a[tree[v]] = upd(a[tree[v]], 1, n, x + it.second, 1);
                q[tree[v]][it.first] += it.second;
            }
        }
    }
    int x = q[tree[v]][c[v]];
    if (x)
    {
        a[tree[v]] = upd(a[tree[v]], 1, n, x, -1);
    }
    a[tree[v]] = upd(a[tree[v]], 1, n, x + 1, 1);
    q[tree[v]][c[v]]++;
  //  if (v == 1)
    {
      // cout << v << ": \n";
       // for (auto it : q[tree[v]])
        {
           // cout << it.first << " " << it.second << endl;
        }
    }
    for (int i = 0; i < que[v].size(); i++)
    {
       // cout << num[v][i] << endl;
        ans[num[v][i]] = find(a[tree[v]], 1, n, que[v][i]);
    }
}

int solve()
{
    ios::sync_with_stdio(0);
    if (!(cin >> n))
    {
        return 1;
    }
    int m;
    cin >> m;
    cnt = 0;
    c.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    ans.assign(m, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        g[i].clear();
        q[i].clear();
        que[i].clear();
        num[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int v, k;
        cin >> v >> k;
        que[v].push_back(k);
        num[v].push_back(i);
    }
    dfs(1, -1);
    for (int i : ans)
    {
        cout << i << "\n";
    }
    return 0;
}

int32_t main()
{
    int T = 1;
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    for (int i = 1;; i++)
    //cin >> T; for (int i = 0; i < T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}