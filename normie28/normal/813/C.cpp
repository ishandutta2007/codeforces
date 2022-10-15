#include <bits/stdc++.h>
#define ll  long long
#define ld  long double
#define inf  1e18
 
using namespace std;
int N = 234569;
vector < vector <int> > gr(N);
void dfs(int v, int prev, vector <int> &deep)
{
    for (auto to : gr[v])
    {
        if (to != prev)
        {
            deep[to] = deep[v] + 1;
            dfs(to, v, deep);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector <int> deep(N), deep1(N);
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        v--; u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, -1, deep);
    dfs(x - 1, -1, deep1);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (deep[i] > deep1[i])
        {
            ans = max(ans, (ll)deep[i]);
        }
    }
    cout << 2 * ans;
}