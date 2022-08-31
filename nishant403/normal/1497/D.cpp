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
#define all(x) x.begin(),x.end()

const int inf = 1e18;
const int N = 5e3 + 10;
int dp[N];
int tag[N];
int s[N];
int n;

void solve()
{
   cin >> n;
   
   f(i,n) cin >> tag[i];
   f(i,n) cin >> s[i];
   f(i,n) dp[i] = 0;
    
   for(int i=1;i<n;i++)
   {
       for(int j=i-1;j>=0;j--) if(tag[i] != tag[j])
       {
           int vv = abs(s[i] - s[j]);
           int v1 = dp[i];
           int v2 = dp[j];
           dp[i] = max(dp[i] , v2 + vv);
           dp[j] = max(dp[j] , v1 + vv);
       }
   }
    
   cout << *max_element(dp,dp+n) << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}