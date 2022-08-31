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

const int M = 1e9+7;

const int N = 1e3+10;

int r[N],c[N];
int grid[N][N];

void solve()
{
  int h,w;
    cin >> h >> w;
    
  f(i,h) cin >> r[i];
  f(i,w) cin >> c[i];
    
  f(i,h)
  {
      f(j,r[i]) grid[i][j] = 1;
      if(r[i] < w) grid[i][r[i]] = -1;
      for(int j=r[i]+1;j<w;j++) grid[i][j] = 0;
  }
    
  f(i,w)
  {
    f(j,c[i]) 
    {
        if(grid[j][i] == -1) { cout<<0; return; } 
        else grid[j][i] = 1;
    }
      
    if(c[i] < h && grid[c[i]][i] == 1)
    {cout << 0; return; }
      
    grid[c[i]][i] = -1;  
       
  }
    
    
    int cn = 0;
    
    f(i,h) f(j,w) if(grid[i][j] == 0) cn++;
        
    int ans = 1;
    
    f(i,cn) ans=(ans*2)%M;
    
    cout<<ans;    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}