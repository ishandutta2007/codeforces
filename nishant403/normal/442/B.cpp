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

void solve()
{
  int n;
  cin >> n;
    
  double p[n];
  f(i,n) cin >> p[i];
    
 sort(p,p+n);
    
   int l = 0;
   int r = n-1;
   double ans = p[n-1];
    
   if(ans == 1.0000000000)
   {
       cout <<  ans;
       return;
   }
    
   f(mid,n)
   {
       double sum = 0.00000000;
       double inv = 1.00000000;
       for(int j=mid;j<n;j++) sum+=p[j]/(1-p[j]),inv*=(1-p[j]);
       ans = max(ans,sum*inv);
   }
    
    cout << fixed << setprecision(9) << ans;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}