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

const int MOD = 1e9+7;

const int N = 1e2 + 10;
vi g[N];

void dfs(int node,int par,int dd,vector<int> & fre)
{
    fre[dd]++;
    
    for(auto x : g[node])
        if(x != par) dfs(x,node,dd + 1,fre);
}

int n,k;

//product of k-subsets
int get(vector<int> & arr)
{
    vector<int> cur(k+1,0);
    cur[0] = 1;
    
    for(auto x : arr)
    {
        for(int i=k;i>=1;i--) 
        {
            cur[i] += cur[i-1]*x;
            cur[i] %= MOD;
        }
    }
    
    return cur[k];
}

int solve(int x)
{
    int sz = g[x].size();
    
    vector<vi> go(sz,vi(n+1,0));
    
    for(int i=0;i<sz;i++) dfs(g[x][i],x,1,go[i]);
    
    int res = 0;
    
    for(int i=1;i<=n;i++)
    {
        vector<int> arr;
        for(auto v : go) arr.pb(v[i]);
        res += get(arr);
        res %= MOD;
    }
    
    return res;
}

void solve()
{
   cin >> n >> k;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   int res = 0;
    
   if(k == 2)
   {
       res = (n*(n-1))/2;
       res %= MOD;
   }
   else 
   {
       for(int i=1;i<=n;i++)
       {
           res += solve(i);
           res %= MOD;
       }
   }
   
   cout << res << '\n'; 
    
   for(int i=1;i<=n;i++) g[i].clear(); 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}