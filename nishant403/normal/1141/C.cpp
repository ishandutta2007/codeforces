#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
int main()
{
 fast;   
 int n,k,an=0;
 string s;
    int i,j;
 
 cin >> n;
  int a[n-1];
    
  f(i,n-1) cin >> a[i];
    
    ll z=1000000;
    
  vector<int> ans;
   ans.pb(1000000);
   
    
    int ma=z,mi=z;
        
   f(i,n-1)
   {
       
    ans.pb(z+a[i]);   
    z=ans[i+1]; 
       
   
    if(z > ma) ma =z;
       if(z < mi ) mi = z;
       
      if(ma - z >= n || z - mi >= n) 
      {
        cout << -1;
          return 0;
      }
       
   }
    
   vector<bool> ch(n,false);
    
  f(i,n)
  {
      ch[ans[i]-mi]=true;
   }
 
    
   f(i,n) if( ch[i] == false )
   {
    cout << "-1";
       return 0;
   }
    
    f(i,n) cout << ans[i] - mi + 1 << " ";
    
    return 0;
}