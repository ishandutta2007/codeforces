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

int encode(string & s)
{
    int res = 1;
    
    for(auto x : s) 
    {
        res*=300;
        res+=x;
    }
    
    return res;
}

const int N = 1e5 + 10;
vi g[N];
int vis[N];
vi res;

void dfs(int node)
{
    vis[node] = 1;
    
    for(auto x : g[node])
    {
        if(vis[x] == 1)
        {
            cout << "NO";
            exit(0);
        }
        else if(vis[x] == 0) dfs(x);
    }  
    
    res.pb(node);
    
    vis[node] = 2;
}

void solve()
{
   int n,m,k;
    cin >> n >> m >> k;
    
   string a[n],b[m];
   int c[m];
    
   f(i,n) cin >> a[i];
   f(i,m) cin >> b[i] >> c[i];  
   f(i,m) c[i]--;
    
   unordered_map<int,int> mp;
   f(i,n) mp[encode(a[i])] = i; 
    
   f(i,m)
   {
       int val = encode(b[i]);
       
       int flag = 1;
       
       f(v,k) 
           if(a[c[i]][v] != '_' && b[i][v] != a[c[i]][v]) flag = 0;
           
       if(!flag)
       {
           cout <<"NO";
           return;
       }
       
       f(j,(1<<k)) 
       {
           string temp = b[i];
           
           f(v,k) if(j & (1<<v)) temp[v] = '_';
               
           int vv = encode(temp);
           
           if(mp.find(vv) != mp.end())
           {
               int idx = mp[vv];
               if(idx != c[i]) g[idx].pb(c[i]);
           }
       }
   }
    
   f(i,n) if(!vis[i]) dfs(i);
   cout <<"YES\n";
   for(auto x : res) cout << x + 1 << ' ';    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}