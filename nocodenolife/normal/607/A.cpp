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
    
    ll dp[1000005];
    ll count[1000005]={0};
    ll value[1000005];
    mem(value);
    
    ll val,loc;
    ForA1(n)
    {
        cin>>loc>>val;
        value[loc] = val;
        count[loc]++;
    }
    ForN1(1000004)
    {
        count[i] += count[i-1];
    }
    ll base;
    ll addition;
    dp[0]=0;
    ForN1(1000004)
    {
        if(value[i]==-1)
        {
            dp[i]=dp[i-1];
        }
        else
        {
            val = value[i];
            addition = count[i-1];
            if(i - val <= 0)
                base =0;
            else
            {
                base =dp[ i - val -1 ];
                addition -= count[i-val-1];
            }
            dp[i] = base+addition;
        }
    }
    
    ll answer = n+1;
    
    ForA1(1000005)
    {
        if(n-count[i] + dp[i] < answer)
            answer=n-count[i] + dp[i];
    }
    cout<<answer<<endl;
    
    // ForA1(10)
    // {
    //     cout<<count[i]<<" "<<value[i]<<" "<<dp[i]<<endl;
    // }
    
    return 0;
}