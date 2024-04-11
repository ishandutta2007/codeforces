#include<bits/stdc++.h>
#define ll long long int
#define N 500010
using namespace std;
int mod=1e9+7;
int main()
{
    int r,g,i,dp[N],j,h;
    cin>>r>>g;
    for(i=0;i<=r+g;i++) dp[i]=0;
    h=0;
    while(h*(h+1)/2 <= r+g) h++;
    h--;
    dp[0]=1;
    for(i=1;i<=h;i++)
    for(j=r+g;j>=i;j--) dp[j]=(dp[j]+dp[j-i])%mod;
    int cnt=0;
    for(i=0;i<=r;i++) if(g+i >= h*(h+1)/2) cnt=(cnt+dp[i])%mod;
    cout<<cnt;
}