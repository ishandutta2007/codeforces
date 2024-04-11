#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1000000, LOG = 21;
const int N = 200007;

ll a[N], tree[M], push[M];
int st[N], fin[N], used[N], tin[N], tout[N], logs[M], timer = 0, bin[LOG][M], firlca[N];
vector<int> eul, g[N], lca;

int min1(int v, int u)
{
    return (tin[v] < tin[u] ? v : u);
}

int flca(int v, int u)
{
    v = firlca[v];
    u = firlca[u];
    if (v > u)
        swap(v, u);
    int x = logs[u - v + 1];
    return min1(bin[x][v], bin[x][u - (1 << x) + 1]);
}

void dfs(int v)
{
    used[v] = 1;
    tin[v] = ++timer;
    firlca[v] = lca.size();
    st[v] = eul.size();
    lca.push_back(v);
    eul.push_back(v);
    for (int u : g[v])
        if (!used[u])
        {
            dfs(u);
            lca.push_back(v);
        }
    fin[v] = (int)eul.size() - 1;
    tout[v] = ++timer;
}

void push1(int v, int l, int r)
{
    if (r < l)
        return;
    int mid = (r + l) / 2;
    tree[2 * v] += (ll)(mid - l + 1) * push[v];
    tree[2 * v + 1] += (ll)(r - mid) * push[v];
    push[2 * v] += push[v];
    push[2 * v + 1] += push[v];
    push[v] = 0;
}

void buildtree(int v, int l, int r)
{
    if (r < l)
        return;
    if (l == r)
    {
        tree[v] = a[eul[l]];
        return;
    }
    int mid = (r + l) / 2;
    buildtree(2 * v, l, mid);
    buildtree(2 * v + 1, mid + 1, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

void tu(int v, int l, int r, int ql, int qr, ll val)
{
    push1(v, l, r);
    if (r < l || ql > r || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        push[v] = val;
        tree[v] += (ll)(r - l + 1) * (ll)val;
        push1(v, l, r);
        return;
    }
    int mid = (r + l) / 2;
    tu(2 * v, l, mid, ql, qr, val);
    tu(2 * v + 1, mid + 1, r, ql, qr, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

ll tf(int v, int l, int r, int ql, int qr)
{
    push1(v, l, r);
    if (r < l || ql > r || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v];
    int mid = (r + l) / 2;
    ll ans = tf(2 * v, l, mid, ql, qr) + tf(2 * v + 1, mid + 1, r, ql, qr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    return ans;
}

bool parent(int p, int v)
{
    return (tin[p] <= tin[v] && tout[p] >= tout[v]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int cur = 0;
    for (int i = 0; i < N; i++)
    {
        if ((1 << (cur + 1)) == i)
            cur++;
        logs[i] = cur;
    }
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
//    return 0;
    eul.assign(1, -1);
    dfs(1);
//    return 0;
  //  cout << 
    buildtree(1, 1, n);
  //  return 0;
    for (int i = 0; i < lca.size(); i++)
        bin[0][i] = lca[i];
    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < lca.size(); j++)
            bin[i][j] = min1(bin[i - 1][j], bin[i - 1][min((int)lca.size() - 1, j + (1 << (i - 1)))]);
//    return 0;
    int root = 1;
    for (int v = 2; v <= n; v++)
    {
        int u = 0;
        while (!parent(g[v][u], v))
            u++;
        for (int i = u - 1; i >= 0; i--)
            swap(g[v][i], g[v][i + 1]);
    }
//    return 0;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
      //  cout << "lol " << tf(1, 1, n, 1, n) << endl;
      //  cout << "mem " << i + 1 << endl;
        if (x == 1)
        {
            int v;
            cin >> v;
            root = v;
        }
        else if (x == 2)
        {
            int u, v, del;
            cin >> u >> v >> del;
            int t = flca(u, v);
            if (!parent(t, root))
                tu(1, 1, n, st[t], fin[t], del);
            else if (root == t)
                tu(1, 1, n, 1, n, del);
            else
            {
                if (parent(root, u))
                    swap(u, v);
                if (parent(root, v))
                {
                    tu(1, 1, n, 1, n, del);
                    continue;
                }
                int t1 = flca(v, root);
                int t2 = flca(u, root);
                if (t1 == t)
                    t1 = t2;
            /*    if (parent(u, root))
                    swap(u, v);
                if (parent(v, root))
                    t1 = v;*/
                int l = 0, r = g[t1].size();
                while (r - l > 1)
                {
                    int mid = (r + l) / 2;
                    if (tin[g[t1][mid]] <= tin[root])
                        l = mid;
                    else
                        r = mid;
                }
                int kek = g[t1][l];
              //  cout << t1 << " " << kek << " " << st[kek] << " " << fin[kek] << endl;
                tu(1, 1, n, 1, n, del);
                tu(1, 1, n, st[kek], fin[kek], -del);
            }
        }
        else
        {
        //    cout << "ans: ";
            int v;
            cin >> v;
            if (!parent(v, root))
                cout << tf(1, 1, n, st[v], fin[v]) << "\n";
            else if (root == v)
                cout << tf(1, 1, n, 1, n) << "\n";
            else
            {
                int l = 0, r = g[v].size();
                while (r - l > 1)
                {
                    int mid = (r + l) / 2;
                    if (tin[g[v][mid]] <= tin[root])
                        l = mid;
                   else
                        r = mid;
                }
                int kek = g[v][l];
             //   cout << kek << endl;
                cout << tf(1, 1, n, 1, n) - tf(1, 1, n, st[kek], fin[kek]) << "\n";
            }
        }
  //      cout << "lol" << endl;
    }
    return 0; 
}