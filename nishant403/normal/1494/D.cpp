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

const int N = 504;
const int M = 2e3 + 10;

int a[N][N];
int n;
int val[M];
vector<int> g[M];

void go(int id,vector<int> & nd)
{
    vector<bool> vis(M,0);
    
    while(!nd.empty())
    {
        int mx = -1;
        
        int nt = -1;
        int nt2 = -1;
        
        for(auto x : nd) if(!vis[x])
            for(auto y : nd) if(!vis[y])
               if(x != y && a[x][y] != val[id])
        {
            mx = max(mx,a[x][y]);
            if(mx == a[x][y]) nt = x , nt2 = y;
        }
         
        if(mx == -1)
        {
            for(auto x : nd) 
                if(!vis[x]) g[x].pb(id);
            return;
        }
            
        val[++n] = mx;     
          
        vector<int> go2;
        
        
        for(auto x : nd) 
                if(a[x][nt2] == mx) 
        {
            if(!vis[x]) 
            {
                vis[x] = 1;
                go2.pb(x);
            }
        }
        
        for(auto x : nd) 
                if(a[x][nt] == mx) 
        {
            if(!vis[x]) 
            {
                vis[x] = 1;
                go2.pb(x);
            }
        }
        
        g[n].pb(id);
        go(n,go2);
    }   
}

void solve()
{
   cin >> n;
   f(i,n) f(j,n) cin >> a[i][j];
   f(i,n) val[i] = a[i][i]; 
  
   int mx = 0;
   f(i,n) f(j,n) mx = max(mx,a[i][j]);
   val[n] = mx;  
    
   vector<int> nodes;
   f(i,n) nodes.push_back(i);
   int nn = n; 
    
   go(n,nodes);
    
   n++; 
   cout << n  << '\n';
    
   f(i,n) cout << val[i] << ' ';
   cout << '\n';
    
   cout << nn + 1 << '\n';
   
   f(i,n) for(auto x : g[i])
       cout << i + 1 << ' ' << x + 1 << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}