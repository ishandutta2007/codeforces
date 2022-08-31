#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int MOD = 1e9+7;
const int N = 1e6 + 10;
const int K = 22;

int dp[N][20];
int spf[N];

void pre()
{ 
    for(int i=2;i<N;i++)
        if(spf[i] == 0)
          for(int j=i;j<N;j+=i)
            spf[j] = i;
        
    dp[0][0] = 1;    
        
    for(int i=1;i<K;i++) dp[0][i] = 2;
    
    for(int i=1;i<N;i++)
    {
        dp[i][0] = 1;
        
        for(int j=1;j<K;j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
        }
    }
}

void solve()
{
   int r,n;
    cin >> r >> n;
    
   int res = 1;
    
   while(n > 1)
   {
       int pr = spf[n];
       int pw = 0;
       
       while(n % pr == 0)
       {
           n /= pr;
           pw++;
       }
       
       res = (res*dp[r][pw])%MOD;
   }
    
   cout << res << '\n';
}

signed main()
{
    pre();
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}