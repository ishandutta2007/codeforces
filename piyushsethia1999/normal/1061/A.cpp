#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

void dfs(std::vector<std::vector<int> > adj, int u, int p)
{
    for (auto v : adj[u])
        if (v != p)
        {

        }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    cout << (s / n) + (s % n ? 1 : 0);
}