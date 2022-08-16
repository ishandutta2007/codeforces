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

const int N = 101;

int adj[N][N];

void solve()
{
    int n;
    cin >> n;
    
    string s;
    
    f(i,n)
    {
     cin >> s;
        f(j,n) adj[i][j] = (s[j]=='1');
    }
    
    int m;
    cin >> m;
    
    int a[m];
    f(i,m) cin >> a[i];
    
    int dis[n][n];
    
    f(i,n) f(j,n) dis[i][j] = 1e10;
    
    f(i,n) dis[i][i] = 0;
    
    f(i,n) f(j,n) if(adj[i][j]) dis[i][j] = 1;
    
    f(k,n)
    {
        f(i,n)
            f(j,n)
              if(dis[i][k] < 1e10 && dis[k][j] < 1e10)
                  dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    
     vi ans;
                     
     ans.pb(a[0]);                
                
                  
    int last = 0;           
                 
    for(int i=1;i<m;i++)
    {
      if(dis[ans.back()-1][a[i]-1] != (i-last))
      {
       ans.pb(a[i-1]); last = i-1;
      }
                         
    }
            
   ans.pb(a[m-1]);
                     
    cout << ans.size() << "\n";
                     
    for(auto x : ans) cout << x <<" ";              
                   
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}