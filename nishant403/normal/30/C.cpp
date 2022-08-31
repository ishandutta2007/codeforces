#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<double,double>

const int N = 1e3+10;
double dp[N];

double dis(pii & a,pii & b)
{
    return sqrt(((a.F-b.F)*(a.F-b.F)) + ((a.S-b.S)*(a.S-b.S)));
}

void solve()
{
  int n;
  cin >> n;
    
  pair<pii,pii> a[n];
    
  f(i,n) cin >> a[i].S.F >> a[i].S.S >> a[i].F.F >> a[i].F.S;
    
  sort(a,a+n);
    
  f(i,n)
  {
      dp[i] = a[i].F.S;
      
      for(int j=0;j<i;j++)
          if(dis(a[i].S,a[j].S) <= (a[i].F.F-a[j].F.F)) 
             dp[i] = max(dp[i],dp[j]+a[i].F.S);          
      
  }
    
  double res = 0;
    
  f(i,n) res = max(res,dp[i]);
    
  cout << fixed << setprecision(6) << res;  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}