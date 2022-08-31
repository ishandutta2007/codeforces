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
   
 int ans = 1;
    
  for(int i=2;i<=n;i++)
  {
   ans+=((i-1)*4);   
  }
   cout << ans; 
}

signed main()
{
    fast;
    solve();
}