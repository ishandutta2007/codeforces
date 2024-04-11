#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(a) (int)(a).size()

const int N = 200001;
vector<int> g[N];
int pr[N];
int d[N];
int lvl[N];

void dfs(int v, int level)
{
    for (int u : g[v])
        if (u != pr[v])
            dfs(u, level + 1);
    d[level]++;
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        pr[i] = x;
    }
    for (int i = 0; i < N; i++)
        d[i] = 0;
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (d[i] % 2)
            ans++;
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    for (int i = 1;; i++)
    {
        #ifndef ONLINE_JUDGE
            cerr << "Test #" << i << ":\n";
        #endif // ONLINE_JUDGE
        if (solve())
            break;
        #ifndef ONLINE_JUDGE
            cerr << "____________________________\n";
        #endif // ONLINE_JUDGE
    }
    #ifndef ONLINE_JUDGE
        cerr << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif // ONLINE_JUDGE
    return 0;
}