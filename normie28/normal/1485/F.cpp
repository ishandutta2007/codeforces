#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> indsum; ll tot;
ll arr[200001];
ll dp[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
const ll MOD=1000000007;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        indsum.clear();
        for (i=1;i<=n;i++)
        {
            cin>>u;
            arr[i]=arr[i-1]+u;
            dp[i]=0;
        }
        dp[0]=1;
        indsum[0]=1;
        tot=1;
        for (i=1;i<=n;i++)
        {
            if (i==n) dp[i]=tot; else
            dp[i]=tot-indsum[arr[i]]+MOD;
            dp[i]%=MOD;
            indsum[arr[i]]+=dp[i];
            indsum[arr[i]]%=MOD;
            tot+=dp[i];
            tot%=MOD;
        }
        cout<<dp[n]<<endl;
    }
}