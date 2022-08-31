#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 

void solve()
{
  int n;
  cin >> n;
   
  int ans = 0;
  vector<pii> data;
    
  int cnt = 0;  
    
  f(i,n)
  {
      int len,x;
      pii res;
      res.F = 1e6,res.S = 0;
      
      cin >> len;
      
      vector<int> temp;
      
      f(j,len)
      {
          cin >> x;
          temp.pb(x);
          res.F = min(res.F,x);
          res.S = max(res.S,x);
      }
      
      reverse(temp.begin(),temp.end());
          
      if(is_sorted(temp.begin(),temp.end())) data.pb(res);
      else cnt++;
  }
    
  ans+=(cnt*n);
  ans+=(cnt*(n-cnt));
    
  ordered_set os;
    
  //straight
    
  f(i,data.size())
  {
    os.insert({data[i].F,i}); 
    ans+=os.order_of_key({data[i].S,-1});  
  }
    
  os.clear();  
    
  reverse(data.begin(),data.end());  
  //reverse  
  f(i,data.size())
  {
    ans+=os.order_of_key({data[i].S,-1});  
    os.insert({data[i].F,i}); 
  }
    
  cout << ans;  
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}