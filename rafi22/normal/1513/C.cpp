#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int ile[10][200007];
int cnt[10],ncnt[10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++) cnt[j]=0;
        cnt[i]=1;
        for(int j=1;j<=200000;j++)
        {
            for(int l=0;l<=9;l++) ncnt[l]=0;
            for(int l=0;l<=8;l++) ncnt[l+1]=cnt[l];
            ncnt[0]=(ncnt[0]+cnt[9])%mod;
            ncnt[1]=(ncnt[1]+cnt[9])%mod;
            for(int l=0;l<=9;l++)
            {
                cnt[l]=ncnt[l];
                ile[i][j]=(ile[i][j]+cnt[l])%mod;
            }
        }
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,ans=0;
        cin>>n>>m;
        while(n>0)
        {
            ans=(ans+ile[n%10][m])%mod;
            n/=10;
        }
        cout<<ans<<endl;
    }

    return 0;
}