#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

bool dfs (int x, const vector<vector<int>> &g, vector<char> &used, vector<int> &match, vector<int> &rev_match)
{
    if (used[x])
        return false;
    used[x] = 1;

    for (int dest : g[x])
    {
        if (match[dest] == -1 || dfs(match[dest], g, used, match, rev_match))
        {
            match[dest] = x;
            rev_match[x] = dest;
            return true;
        }
    }

    return false;
}

int matching (const vector<vector<int>> &g, int left, int right)
{
    vector<char> used(left);
    vector<int> rev_match(left, -1), match(right, -1);

    while (true)
    {
        bool ok = false;
        fill(used.begin(), used.end(), 0);

        for (int i = 0; i < left; i++)
        if (rev_match[i] == -1 && !used[i])
            ok |= dfs(i, g, used, match, rev_match);

        if (!ok)
            break;
    }

    return left - count(rev_match.begin(), rev_match.end(), -1);
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m;
    cin >> n >> m;

    const int inf = int(1e9) + 1;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        g[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = g[v][u] = 1;
    }

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int s, b, k, h;
    cin >> s >> b >> k >> h;

    vector<int> pos_s(s), fuel(s), atk(s);
    vector<int> pos_b(b), def(b);
    for (int i = 0; i < s; i++)
    {
        cin >> pos_s[i] >> atk[i] >> fuel[i];
        --pos_s[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> pos_b[i] >> def[i];
        --pos_b[i];
    }

    vector<vector<int>> graph(s);
    for (int i = 0; i < s; i++)
    for (int j = 0; j < b; j++)
    if (g[pos_s[i]][pos_b[j]] <= fuel[i] && def[j] <= atk[i])
        graph[i].pb(j);

    const int len = matching(graph, s, b);

    ll ans = min((ll)len * k, (ll)s * h);
    cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}