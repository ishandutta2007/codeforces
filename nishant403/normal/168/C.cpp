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
  int n,a,d,t,v;
    
  double ans;
    
  cin >> n >> a >> d;   
    
   //time to reach distance if max velocity is not inside 
 double t2 = (2.0000000*d)/(double)a;  
  
   t2 = sqrt(t2); 
    
 double prev = -1.0000000;

  f(i,n)
  {
   cin >> t >> v;   
   
   //time to reach v
   double t1 = ((double)v/a);  
      
         
   if(t2 > t1)
   {
    double disc = (0.5000000*a*t1*t1);
    double rem = d - disc;
       
    ans = t1 + (rem/v);   
   }
   else ans = t2;       
   
   ans+=t;
      
   if(ans < prev) ans = prev;   
      
   cout << fixed << setprecision(10) << ans << "\n"; 
      
   prev = ans;   
  }
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}