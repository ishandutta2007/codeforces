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
   int n,m;
    cin >> n >> m;
    
   pii a[m];
   f(i,m) cin >> a[i].F >> a[i].S;
   sort(a,a+m);
  
   int pref[m];
   f(i,m) pref[i] = a[i].F;
   f(i,m-1) pref[i+1]+=pref[i];
    
   int val[m];
   f(i,m) val[i] = a[i].F;
    
   int res = 0; 
    
   f(i,m)
   {
      int temp = 0;
       
      //first integer greater than or equal to a[i].S in a[i].F
       
      int id = lower_bound(val,val+m,a[i].S) - val;
     
      int terms = m - id;
      int nn = n;
      int inc = 0; 
       
      if(nn >= terms)
      {
          nn-=terms;
          temp+=pref[m-1];
          if(id > 0) temp-=pref[id-1];
          if(a[i].F >= a[i].S) inc = 1;
      }
      else
      {
         temp = pref[m-1];
          
         if(nn != m)
             temp-=pref[m-nn-1];
         
         nn = 0;
      }
       
      if(nn > 0 && inc == 0) temp+=a[i].F,nn--;
      temp+=a[i].S*nn;
       
      res = max(res,temp); 
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