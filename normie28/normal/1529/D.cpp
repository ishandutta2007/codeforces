#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll dp[2000001];
ll summ[2000001],n,m,i,j,k;
int main()
{
    cin>>n;
    n*=2;
    dp[0]=1;
    summ[0]=1;
    for (i=1;i<=n;i++)
    {
        if (i>=2) dp[i]+=summ[i-2];
        dp[i]%=MOD;
        if (i>=2) summ[i]=(summ[i-2]+dp[i])%MOD;
        if (i%2==0) for (j=i*2;j<=n;j+=i) {dp[j]++; dp[j]%=MOD;}
    }
    cout<<dp[n];
}