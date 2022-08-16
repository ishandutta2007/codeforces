#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(n) for(int i=0;i<n;i++)

int M = 998244353;

signed main()
{
   int n;
    cin >> n ;
    
  int upper[n],lower[n];
    
  f(n) cin >> upper[i];
  f(n) cin >> lower[i];
    
  f(n) upper[i] = (upper[i]*(i+1)*(n-i));
      
  sort(upper,upper+n);
  sort(lower,lower+n);
    
  f(n) upper[i]%=M;  
    
  reverse(lower,lower+n);
    
    
  int ans = 0;
    
  f(n) ans = (ans + upper[i]*lower[i]%M ) % M;
      
      cout << ans;
}