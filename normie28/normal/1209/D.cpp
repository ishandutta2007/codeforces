#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;
void dfs(ll i, vector<ll> graph[], ll visited[])
{
    visited[i] = 1;
    for (ll j = 0; j < graph[i].size(); j++)
    {
        if (!visited[graph[i][j]])
            dfs(graph[i][j], graph, visited);
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> graph[n + 1];
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    ll concomp = 0;
    ll visited[n + 1] = {0};
    for (ll i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            concomp++;
            dfs(i, graph, visited);
        }
    }
    cout << (k - (n - concomp)) << "\n";
}