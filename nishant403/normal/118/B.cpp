#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;

 int n;
 cin >> n;
    
    
    
  for(int i=-n;i<=n;i++)  
  {
   for(int k=1;k<=abs(i);k++) 
    cout << "  ";
    
   for(int k=0;k<=n-abs(i)-1;k++) 
    cout << k << " ";
    
   for(int k = n - abs(i) ; k > 0 ;k--)cout << k << " "; 
    
    cout << 0;
      
    cout << "\n";  
  } 
    
    
}