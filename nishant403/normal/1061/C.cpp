#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int> 
#define pii pair<int,int>

const int N = 1e6+1;
const int M = 1e9+7;

vi divisors[N];
vi dp(N,0);

void sieve()
{
  for(int i=N;i>=1;i--)
   for(int j=i;j<=N-1;j+=i) divisors[j].pb(i);   
}

void solve()
{
    int a,n,ans = 0;
    cin >> n;
   
    dp[0] = 1;
    
    f(i,n)
    {
      cin >> a;
      for(auto x : divisors[a]) dp[x]= (dp[x] + dp[x-1])%M;      
    }
    
    for(int i=1;i<=n;i++) ans=(ans+dp[i])%M;
    
    cout << ans;
}

signed main()
{
 Fast;
 sieve();
 solve();
}