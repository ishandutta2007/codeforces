#include <iostream>
#include <algorithm>
using namespace std;
 
const long long mod=1000000007;
#define ll int
long long dp[1<<24];
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    int b[k];
    for(ll i=0;i<k;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<(1<<n);i++)
    {
        int j=__builtin_ctz(i);
        dp[i]=dp[i^(1<<j)]+a[j];
    }
    for(ll i=1;i<(1<<n);i++)
    {
        for(ll j=0;j<k;j++)
        {
            if(b[j]==dp[i])
            {
                dp[i]=-1;
                break;
            }
        }
    }
    dp[0]=1;
    for(ll i=1;i<(1<<n);i++)
    {
        if(dp[i]<0)
            dp[i]=0;
        else
        {
            dp[i]=0;
            for(ll j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    dp[i]+=dp[i^(1<<j)];
                }
            }
            dp[i]%=mod;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}