#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int path[201010];
int a[201010], b[201010];
vector<pair<int, int>> adj[201010];
int par[201010];

void dfs(int x, int p)
{
    for(auto u : adj[x])
    {
        int i = u.first;
        if(i == p) continue;
        int c = u.second;
        par[i] = c;
        dfs(i, x);
    }
}

int f(int x)
{
    if(x == path[x]) return x;
    return path[x] = f(path[x]);
}

bool u(int x, int y)
{
    x = f(x); y = f(y);
    if(x == y) return false;
    path[x] = y;
    return true;
}

bool chk(int i, int j)
{
    if(a[i] == a[j] || a[i] == b[j] || b[i] == a[j] || b[i] == b[j]) return true;
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) path[i] = i;
    
    string s;
    s.resize(m);
    for(int i=0;i<m;i++)
    {
        cin >> a[i] >> b[i];
        if(u(a[i], b[i]))
        {
            s[i] = '0';
            adj[a[i]].push_back({b[i], i});
            adj[b[i]].push_back({a[i], i});
        }
        else s[i] = '1';
    }
    
    if(m < n+2)
    {
        cout << s << "\n";
        return;
    }
    
    vector<int> blue;
    for(int i=0;i<m;i++)
    {
        if(s[i] == '1') blue.push_back(i);
    }
    
    if(chk(blue[0], blue[1]) && chk(blue[1], blue[2]) && chk(blue[2], blue[0]))
    {
        int x = a[blue[0]], y = b[blue[0]];
        dfs(x, -1);
        s[par[y]] = '1';
        s[blue[0]] = '0';
    }
    cout << s << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}