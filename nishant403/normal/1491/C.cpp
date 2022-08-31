#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>

void solve()
{
   int n,res = 0;
   cin >> n;
    
   vi a(n),done(n,0); 
    
   f(i,n) cin >> a[i];
    
   f(i,n)
   {
       res += max((int)0,a[i] - 1 - done[i]);
       for(int j=i+2;j<=min(i+a[i],n-1);j++) done[j]++;
       if(i < n-1) done[i+1] += max((int)0,done[i] - a[i] + 1);
   }
    
   cout << res << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}