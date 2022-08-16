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
  int n,k;
  cin >> n >> k;
    
  string s;
  cin >> s;  
      
  // O(n) approach
    
  vector<int> mark(n,0);
  int len = (n-2*k+2)/2; 
    
  f(i,k-1) mark[2*i] = 1;   
  for(int i=2*k-2;i<2*k-2+len;i++) mark[i] = 1; 
    
  vi id;
    
  f(i,n) if(s[i] == '(' && mark[i] == 0) id.pb(i); 
    
  vector<pii> ans;  
    
  int l = 0; 
    
  f(i,n)
  {
    if(mark[i] == 0) continue; 
      
    if(s[i] == '(') continue;
        
    int a = min(i,id[l]);
    int b = max(i,id[l]);
      
    l++;
      
    ans.pb({a,b});
      
    if(a+1 == b) continue;
        
    ans.pb({a+1,b-1});  
  }
    
  cout << ans.size() << '\n';
    
  for(auto x : ans) cout << x.F+1 <<" "<<x.S+1 <<'\n';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}