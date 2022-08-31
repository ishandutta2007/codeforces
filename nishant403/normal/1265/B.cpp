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
    
  vi ans(n+1,0);
    
  int mx = 1,l,r,sz = 1;
    
  int p[n];
  f(i,n) cin >> p[i];
    
  f(i,n) if(p[i] == 1) l = r = i;  
    
  ans[1] =  1;
    
  while(sz < n)
  {
    if(l == 0) mx=max(mx,p[++r]);  
    else if(r == n-1) mx=max(mx,p[--l]);
    else if(p[r+1] < p[l-1]) mx = max(mx,p[++r]);
    else mx = max(mx,p[--l]);
    
      
    sz++;
      
    if(mx == sz) ans[sz] = 1; 
  }
      
  f(i,n) cout << ans[i+1]; cout<<'\n';    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}