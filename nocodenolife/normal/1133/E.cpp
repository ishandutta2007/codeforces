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

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin>>n>>k;
    
    ll val[n];
    ForA1(n)
    {
        cin>>val[i];
    }
    sort(val,val+n);
    
    ll dp[n+1][k+1];
    ll temp,count;
    
    ForA1(k+1)
    {
        dp[n][i] = 0;
    }
    ll val2[n];
    for(ll i=n-1;i>=0;i--)
    {
        temp = i;
        count=1;
        for(ll j=temp+1;j<n;j++)
        {
            if(val[j]>val[temp]+5)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        dp[i][1] = count;
        val2[i] = count;
        dp[i][1] = max(dp[i][1],dp[i+1][1]);
    }
    
    
    for(ll i=2;i<=k;i++)
    {
        for(ll j=n-1;j>=0;j--)
        {
            temp = val2[j];
            dp[j][i] = max(dp[j+1][i], temp + dp[j+temp][i-1]);
        }
    }
    
    cout<<dp[0][k]<<endl;
    return 0;
}