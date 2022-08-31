
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>

signed main()
{    
    Fast;
     int n,k;
    
    cin >> n >> k;
    
    vector<int> a(n);
    vector<int> pref(n+1);
    
    f(i,n) cin >> a[i];
    
    pref[0] = 0;
    
    f(i,n) pref[i+1] = pref[i] + a[i];
    
    int ans = 0;
    int l = n-1;
    
  priority_queue<pii,vector<pii>,greater<pii> > PQ;
     
  for(int i=n-1;i>=k-1;i--) PQ.push({pref[i],i});  
    
  for(int i=0;i<k-1;i++)  
  { 
    pii x;
      
    
         x=PQ.top();
         PQ.pop();
         
      
      
    ans+=(k-i)*(pref[l+1] - x.F);  
      
    l = x.S-1;  
      
      PQ.push({pref[k-i-2],k-i-2});  
  } 
    
  for(;l>=0;l--) ans+=a[l];  
    cout << ans;
}