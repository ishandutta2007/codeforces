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
    
    ll n;
    cin>>n;
    ll arr[n+1];
    ForN1(n)
    {
        cin>>arr[i];
    }
    ll dp[n+1][4] = {{0}};
    
    ForN1(n)
    {
        if(arr[i]==1)
        {
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = max(dp[i-1][1]+1, dp[i-1][2]+1);
            dp[i][3] = dp[i-1][3];
        }
        else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]+1);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = max(dp[i-1][2]+1, dp[i-1][3]+1);
        }
    }
    
    cout<<max(max(dp[n][0],dp[n][1]), max(dp[n][2],dp[n][3]))<<endl;

    return 0;
}