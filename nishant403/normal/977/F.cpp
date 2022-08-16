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
 int n,ans,idd;
    
 cin >> n;
    
 int a[n];
    
 f(i,n) cin >> a[i];
    
 map<int,int> mp;   
     
 ans = 1;
 idd = 0;    
    
  for(int i=0;i<n;i++)  
  {     
   if(mp.find(a[i]-1) != mp.end())
    mp[a[i]] = mp[a[i]-1] +1;
    
   else mp[a[i]] = 1;
   
      
  if(mp[a[i]] > ans)
   {
     ans = mp[a[i]];
     idd = i;
   }
    
  }
    
  cout << ans << '\n';
    
  int tmp = a[idd];
    
  vi x;  
    
  for(int i=idd;i>=0;i--)
  {
  	if(a[i] == tmp) {
  		x.pb(i);
  		tmp--;
  	}
  }
  
  reverse(x.begin(),x.end());
    
  for(auto z : x) cout << z+1 <<" ";
}

signed main()
{
    fast;
    solve();
}