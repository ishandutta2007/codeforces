#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;

vector <int> ans;

int par[N];
int n,m;

int getpar(int u)
{
    return (par[u] < 0) ? (u) : (par[u] = getpar(par[u]));
}

bool join(int u, int v)
{
    u = getpar(u);
    v = getpar(v);
    if (u == v)
        return false;
    if (par[u] > par[v])
        swap(u, v);

    par[u] += par[v];
    par[v] = u;
    return true;
}

int binpow(int n, int k)
{
    int res = 1;

    while (k > 0)
    {
        if (k & 1)
            res = (long long) res * n % mod;

        n = (long long) n * n % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
    {
        par[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int x;
            cin >> x;
            if (join(x, 0))
                ans.push_back(i);
        } else {
            int u,v;
            cin >> u >> v;
            if (join(u, v))
                ans.push_back(i);
        }
    }
    cout << binpow(2, (int) ans.size()) << " " << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    return 0;
}