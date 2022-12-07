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
    
    ll arr[n];
    ForA1(n)
    {
        cin>>arr[i];
    }
    ll dp[n][5];
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 100;
    
    for(ll i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            ll max = 0;
            for(ll j=0;j<5;j++)
            {
                if(dp[i-1][j]!=-1)
                    max=j;
            }
            for(ll j=0;j<max;j++)
            {
                dp[i][j] = max;
            }
            for(ll j=max;j<5;j++)
            {
                dp[i][j] = -1;
            }
        }
        else if(arr[i]>arr[i-1])
        {
            ll min = 4;
            for(ll j=4;j>=0;j--)
            {
                if(dp[i-1][j]!=-1)
                    min=j;
            }
            for(ll j=4;j>min;j--)
            {
                dp[i][j] = min;
            }
            for(ll j=min;j>=0;j--)
            {
                dp[i][j] = -1;
            }
        }
        else
        {
            ll min = 4;
            for(ll j=4;j>=0;j--)
            {
                if(dp[i-1][j]!=-1)
                    min=j;
            }
            for(ll j=0;j<5;j++)
            {
                dp[i][j] = min;
            }
            dp[i][min]=-1;
            for(ll j=0;j<5;j++)
            {
                if(j!=min && dp[i-1][j]!=-1)
                    dp[i][min] = j;
            }
        }
        ll temp = -1;
        for(ll j=0;j<5;j++)
        {
            if(dp[i][j]!=-1)
                temp = j;
        }
        if(temp==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    ll answer[n];
    answer[n-1] = -10;
    for(ll i=0;i<5;i++)
    {
        if(dp[n-1][i]!=-1)
            answer[n-1]=i;
    }
    
    // for(ll j=0;j<5;j++)
    // {
    //     for(ll i=0;i<n;i++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(ll i=n-1;i>0;i--)
    {
        answer[i-1] = dp[i][answer[i]];
    }
    
    for(ll i=0;i<n;i++)
    {
        cout<<answer[i]+1<<" ";
    }
    cout<<endl;
    
    return 0;
}