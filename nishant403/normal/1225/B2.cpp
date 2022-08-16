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
  int n,k,d;
  cin >> n >> k >> d;
    
  int a[n];
    f(i,n) cin >> a[i];
    
  int ans = n;
    
  map<int,int> mp;
    
  for(int i=0;i<d-1;i++) mp[a[i]]++;
    
  for(int i=d-1;i<n;i++)
  {
    mp[a[i]]++;        
    ans=min(ans,(int)mp.size());
    if(mp[a[i-d+1]] == 1)
         mp.erase(a[i-d+1]);
    else mp[a[i-d+1]]--;
  }
    
  cout << ans << "\n";  
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}