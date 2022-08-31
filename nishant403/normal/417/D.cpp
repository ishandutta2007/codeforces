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

const int BT = 20;
const int inf = (long long)2e18;
const int N = (1LL<<BT);
int dp[N];
int n,b,m,x,y;
bitset<BT> can[100];
pair<pii,int> dat[100];

void solve()
{
  cin >> n >> m >> b;   
    
  f(i,n)
  {
      cin >> dat[i].F.S >> dat[i].F.F;
      dat[i].S = i;
      
      cin >> x;
      
      while(x--)
      {
          cin >> y;
          can[i][--y] = 1;
      }
  }
    
  sort(dat,dat+n);   
 
  int res = inf;  
   
  f(j,(1<<m)) dp[j] = inf;
  dp[0] = 0;
    
  f(i,n) f(j,(1<<m))
  {
      int cost = dat[i].F.S;
      int mnt = dat[i].F.F;
      int fmask = (j|can[dat[i].S].to_ullong());
      
      dp[fmask] = min(dp[fmask],dp[j] + cost);
      
      if(fmask == (1LL<<m) - 1) res = min(res,dp[fmask] + (b*mnt)); 
  }
    
  if(dp[(1LL<<m)-1] == inf) cout<<-1;  
  else cout << res; 
}

signed main()
{
    fast;
    solve();
}