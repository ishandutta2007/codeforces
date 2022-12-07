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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    
    ll table[n][m];
    ll dp[n][m];
    
    ForA1(n)
    {
        ForA2(m)
        {
            cin>>table[i][j];
        }
    }
    ForA2(m)
    {
        dp[0][j]=0;
    }
    
    ForN1(n-1)
    {
        ForA2(m)
        {
            if(table[i][j]>=table[i-1][j])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j]=i;
        }
    }
    
    ForN1(n-1)
    {
        ll min = n+10;
        ForA2(m)
        {
            if(dp[i][j]<min)
                min=dp[i][j];
        }
        dp[i][0] = min;
    }
    
    ll k;
    cin>>k;
    ll l,r;
    ForA1(k)
    {
        cin>>l>>r;
        l--;r--;
        if(dp[r][0]<=l)
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}