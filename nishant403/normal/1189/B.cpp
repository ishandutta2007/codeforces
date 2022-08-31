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
    
  int a[n];
    
  f(i,n) cin >> a[i];
 
  sort(a,a+n);
    
  deque<int> ans;
    
  ans.pb(a[n-1]);
    
  ans.pb(a[n-2]);   
  ans.push_front(a[n-3]);
  
    
   for(int i=n-4;i>=0;i--)
   ans.pb(a[i]);
   
    
   
  vi g;
       
  while(!ans.empty())
  {
   auto h = ans.front();
   ans.pop_front();
      
   g.pb(h);   
  }
   
  for(int i=1;i<=n-2;i++)
  {
      if(g[i-1] + g[i+1] <= g[i] ){ cout << "NO\n"; return; }   
  }
    
  if(g[0] + g[n-2] <= g[n-1]) { cout << "NO\n"; return; }  
    if(g[1] + g[n-1] <= g[0]) { cout << "NO\n"; return; } 
    
    
    cout << "YES\n";
    
    for(auto x : g) cout << x << " ";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}