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
  int a,b,c,n;
  cin >> a >> b >> c >> n;
    
  int mn = max(a,b);
   mn = max(mn,c);
    
  int req = 3*mn - a -b - c;
    
  if(n >= req && (n-req)%3 == 0) cout <<"YES\n";
    else cout <<"NO\n";
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}