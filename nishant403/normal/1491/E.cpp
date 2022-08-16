#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 2e5 + 10;
map<int,pii> mp;

set<int> g[N];

pii fnd;
int s1,s2;
int sz[N];

void dfs(int node,int par = -1)
{
    sz[node] = 1;
    
    for(auto x : g[node])
    {
        if(x != par)
        {
            dfs(x,node);
            sz[node] += sz[x];
        }
    }
    
    if(sz[node] == s1)
    {
        fnd = {node,par};
    }
    else if(sz[node] == s2)
    {
        fnd = {par,node};
    }
}

bool check(int sz,int nd)
{
    if(sz == 1) return 1;
    
    s1 = mp[sz].F;
    s2 = mp[sz].S;
    fnd = {-1,-1};
    
    dfs(nd,-1);
    
    if(fnd.F == -1) return 0;
    
    assert(fnd.S != -1);
    
    g[fnd.F].erase(fnd.S);
    g[fnd.S].erase(fnd.F);
    
    //caution !!!!!!
    //fnd and s is global variable 
    //would be changed when second function call is made
    
    int a1 = s1,a2 = fnd.F;
    int b1 = s2,b2 = fnd.S;
    
    if(check(a1,a2)) return check(b1,b2);
    
    return 0;
}

signed main()
{
    fast;
    
    int a = 1, b = 1;
    
    while(a < N)
    {
        mp[a+b] = {a,b};
        b = a + b;
        a = b - a;
    }
    
    int n;
    cin >> n;
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    if(check(n,1)) cout <<"YES\n";
    else cout <<"NO\n";
}