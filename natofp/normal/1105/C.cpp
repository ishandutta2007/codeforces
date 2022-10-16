#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long long int mod=1e9+7;
ll dp[333333][3];

int main()
{
    ll n,l,r;
    cin>>n>>l>>r;
    ll ile[3];
    ile[0]=ile[1]=ile[2]=(r-l+1)/3;
    int t=r-l+1-(ile[0])*3;
    while(t>0)
    {
        t--;
        ile[r%3]++;
        r--;
    }
    //cout<<ile[0]<<" "<<ile[1]<<" "<<ile[2]<<endl;
    memset(dp,0LL,sizeof dp);
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                dp[i][j]+=dp[i-1][(j+3-k)%3]*ile[k];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][0];
    return 0;
}