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
    
    ll n;
    cin>>n;
    
    ll ones =0;
    ll g;
    ll dp[n];
    ll arr[n];
    cin>>arr[0];
    g=arr[0];
    dp[0]=arr[0];
    if(g==1)
        ones++;
    ForN1(n-1)
    {
        cin>>arr[i];
        dp[i]=arr[i];
        g = __gcd(g,arr[i]);
        if(arr[i]==1)
            ones++;
    }
    
    if(g!=1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(ones!=0)
    {
        cout<<n-ones<<endl;
        return 0;
    }
    
    for(ll i=2;i<n;i++)
    {
        for(ll j=0;j<n-i+1;j++)
        {
            dp[j] = __gcd(dp[j],arr[j+i-1]);
            if(dp[j]==1)
            {
                cout<<i-1+n-1<<endl;
                return 0;
            }
        }
        
    }
    cout<<n+n-2<<endl;
    
    return 0;
}