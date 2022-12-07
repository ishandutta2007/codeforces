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
    
    ll c[n];
    ForA1(n)
    {
        cin>>c[i];
    }
    
    string s[n][2];
    ForA1(n)
    {
        cin>>s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    
    ll dp[n][2];
    dp[0][0] =0;
    dp[0][1] = c[0];
    
    ForN1(n-1)
    {
        dp[i][0] = dp[i][1] = -1;
        if(dp[i-1][0]>=0 && s[i][0]>=s[i-1][0])
        {
            dp[i][0] = dp[i-1][0];
        }
        if(dp[i-1][1]>=0 && s[i][0]>=s[i-1][1])
        {
            if(dp[i][0]==-1)
                dp[i][0] = dp[i-1][1];
            else
                dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }
        
        if(dp[i-1][0]>=0 && s[i][1]>=s[i-1][0])
        {
            dp[i][1] = dp[i-1][0]+c[i];
        }
        if(dp[i-1][1]>=0 && s[i][1]>=s[i-1][1])
        {
            if(dp[i][1]==-1)
                dp[i][1] = dp[i-1][1]+c[i];
            else
                dp[i][1] = min(dp[i][1],dp[i-1][1]+c[i]);
        }
        
        if(dp[i][0]==-1 && dp[i][1]==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    
    ll answer;
    if(dp[n-1][0]==-1)
        answer = dp[n-1][1];
    else
    {
        if(dp[n-1][1]==-1)
            answer = dp[n-1][0];
        else
            answer = min(dp[n-1][0],dp[n-1][1]);
    }
    
    cout<<answer<<endl;
    
    return 0;
}