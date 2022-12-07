#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 998244353 
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    
    ll dp[1005][2005][4] = {{{0}}};
    
    dp[1][1][0]++; dp[1][2][1]++; dp[1][2][2]++; dp[1][1][3]++;
    
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<2004;j++)
        {
            dp[i][j][0]%=mod;dp[i][j][1]%=mod;dp[i][j][2]%=mod;dp[i][j][3]%=mod;
            
            
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][0] += dp[i][j][1];
            dp[i+1][j][0] += dp[i][j][2];
            dp[i+1][j+1][0] += dp[i][j][3];
            
            dp[i+1][j+1][1] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+2][1] += dp[i][j][2];
            dp[i+1][j+1][1] += dp[i][j][3];
            
            dp[i+1][j+1][2] += dp[i][j][0];
            dp[i+1][j+2][2] += dp[i][j][1];
            dp[i+1][j][2] += dp[i][j][2];
            dp[i+1][j+1][2] += dp[i][j][3];
            
            dp[i+1][j+1][3] += dp[i][j][0];
            dp[i+1][j][3] += dp[i][j][1];
            dp[i+1][j][3] += dp[i][j][2];
            dp[i+1][j][3] += dp[i][j][3];
        }
    }
    ll ans = dp[n][k][0]+ dp[n][k][1]+ dp[n][k][2]+ dp[n][k][3];
    ans%=mod;
    cout<<ans<<endl;

    return 0;
}