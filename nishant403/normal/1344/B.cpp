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

const int N = 1e3 + 10;
string a[N];
int vis[N][N];

int r[N];
int c[N];
int n,m;

void check_interval()
{
    f(i,n)
    {
        int ps = 0;
        
        f(j,m-1)
            if(a[i][j+1] == '#' && a[i][j] == '.') ps++;
            
        if(a[i][0] == '#') ps++;    
         
        if(ps > 1)
        {
            cout << -1;
            exit(0);
        }
    }
    
    f(j,m)
    {
        int ps = 0;
        
        f(i,n-1)
            if(a[i+1][j] == '#' && a[i][j] == '.') ps++;
            
        if(a[0][j] == '#') ps++;    
         
        if(ps > 1)
        {
            cout << -1;
            exit(0);
        }
    }
    
}

void dfs(int i,int j)
{
    if(i < 0) return;
    if(j < 0) return;
    if(i >= n) return;
    if(j >= m) return;
    
    if(vis[i][j] == 1) return;
    if(a[i][j] == '.') return;
    
    vis[i][j] = 1;
    
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);        
}

void solve()
{
    cin >> n >> m;
    
   f(i,n) cin >> a[i];
    
   check_interval(); 
   
   f(i,n) f(j,m) if(a[i][j] == '#') r[i] = c[j] = 1; 
  
   int rr = 0;
   int cc = 0;
    
   f(i,n)
   {
       int ff = 1;
       
       f(j,m) if(a[i][j] == '#') ff = 0;
       rr+=ff;
   }
   
   f(j,m)
   {
       int ff = 1;
       
       f(i,n) if(a[i][j] == '#') ff = 0;
       cc+=ff;
   }
   
   if(cc == 0 && rr > 0)
   {
       cout << -1;
       return;
   }
    
   if(cc > 0 && rr == 0)
   {
       cout << -1;
       return;
   }
       
   int res = 0;
    
   f(i,n) f(j,m) if(vis[i][j] == 0 && a[i][j] == '#')
   {
       res++;
       dfs(i,j);
       
   }
    
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}