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

#define modder 998244353
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
    
    ll counter[100005] = {0};
    ll dp[100005][2];
    
    ll num;
    ForA1(n)
    {
        cin>>num;
        counter[num]++;
    }    
    
    dp[0][0] = 0;
    dp[0][1]= 0;
    dp[1][0]=0;
    dp[1][1] = counter[1];
    
    for(ll i=2;i<=100001;i++)
    {
        if(counter[i]!=0)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + (counter[i]*i);
        }
        else
        {
            dp[i][0] = dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        }
    }
    
    // for(ll i=0;i<6;i++)
    // {
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0;i<6;i++)
    // {
    //     cout<<dp[i][1]<<" ";
    // }
    // cout<<endl;
    
    cout<<dp[100001][0]<<endl;
    
    return 0;
}