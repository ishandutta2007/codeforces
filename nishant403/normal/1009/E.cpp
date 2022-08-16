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

const int M = 998244353;
const int N = 1e6+10;
int a[N],p2[N];

void solve()
{
  int n;
  cin >> n;
    
  f(i,n) cin >> a[i];
    
  p2[0] = 1;
  for(int i=1;i<=n;i++) p2[i] = (p2[i-1] + p2[i-1])%M;
    
  int res = 0; 
  //1and then i zeros.
    
  for(int i=0;i<n;i++)
  {
      int ways = (n-(i+1));
      
      ways = (ways*p2[n-1-(i+1)])%M;
      ways = (ways + p2[n-1-i])%M;
      
      res +=(ways*a[i])%M;
      res%=M;
  }
    
  cout << res;
}

signed main()
{
    fast;
    solve();
}