#include <bits/stdc++.h>
//Qingyu Laji
using namespace std;
int n;
int a[4005];
int dp[2105][105][105][2];
int e[2105][105][105][2];
int tinh(int vt,int gt,int kc,int luot)
{
    if (e[vt][gt][kc][luot]==1) return dp[vt][gt][kc][luot];
    e[vt][gt][kc][luot]=1;
    if (luot==0)
    {
         int tam=n-vt-vt-kc;
         if (tam<gt) dp[vt][gt][kc][luot]=0;
         else
         {
            dp[vt][gt][kc][luot]=-1e9;
            if (tam>=gt) dp[vt][gt][kc][luot]=max(dp[vt][gt][kc][luot],a[vt+gt]-a[vt]-tinh(vt+kc,gt,gt-kc,1-luot));
            if (tam>gt) dp[vt][gt][kc][luot]=max(dp[vt][gt][kc][luot],a[vt+gt+1]-a[vt]-tinh(vt+kc,gt+1,gt+1-kc,1-luot));
         }
         return dp[vt][gt][kc][luot];
    }
    else
    {
        int tam=n-vt-vt-kc;
        if (tam<gt) dp[vt][gt][kc][luot]=0;
        else
        {
            dp[vt][gt][kc][luot]=-1e9;
            if (tam>=gt) dp[vt][gt][kc][luot]=max(dp[vt][gt][kc][luot],a[n-vt]-a[n-vt-gt]-tinh(vt+kc,gt,gt-kc,1-luot));
            if (tam>gt) dp[vt][gt][kc][luot]=max(dp[vt][gt][kc][luot],a[n-vt]-a[n-vt-gt-1]-tinh(vt+kc,gt+1,gt+1-kc,1-luot));
        }
        return dp[vt][gt][kc][luot];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i-1]+a[i];
    }
    cout<<tinh(0,1,0,0);
    return 0;
}