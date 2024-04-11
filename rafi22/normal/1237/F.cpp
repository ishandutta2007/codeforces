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

const bool multi=0;

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

int silnia[4007];
int inv[4007];
int DP[3607][3607];
int DP1[3607][3607];
bool X[3607];
bool Y[3607];

int m(int i,int j)
{
    if(i>j) return 0;
    return silnia[j]*inv[j-i]%mod;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        mod=mod1;
        silnia[0]=1;
        inv[0]=1;
        for(int i=1;i<=3600;i++)
        {
            silnia[i]=silnia[i-1]*i%mod;
            inv[i]=pot(silnia[i],mod-2);
        }
        int h,w,n;
        cin>>h>>w>>n;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            X[x]=1;
            Y[y]=1;
            cin>>x>>y;
            X[x]=1;
            Y[y]=1;
        }
        int bX=0,bY=0;
        DP[0][0]=1;
        for(int i=1;i<=h;i++)
        {
            if(X[i]) bX++;
            for(int j=0;j<=h;j++)
            {
                DP[i][j]=DP[i-1][j];
                if(j>0&&i>1&&!X[i]&&!X[i-1]) DP[i][j]=(DP[i][j]+DP[i-2][j-1])%mod;
            }
        }
        DP1[0][0]=1;
        for(int i=1;i<=w;i++)
        {
            if(Y[i]) bY++;
            for(int j=0;j<=w;j++)
            {
                DP1[i][j]=DP1[i-1][j];
                if(j>0&&i>1&&!Y[i]&&!Y[i-1]) DP1[i][j]=(DP1[i][j]+DP1[i-2][j-1])%mod;
            }
        }
        int ans=0;
        for(int i=0;i<=h;i++)
        {
            for(int j=0;j<=w;j++)
            {
               // cout<<i<<" "<<j<<" "<<DP[h][i]*DP1[w][j]<<endl;
                ans=(ans+DP[h][i]*DP1[w][j]%mod*m(i,w-bY-2*j)%mod*m(j,h-bX-2*i)%mod)%mod;
            }
        }
        cout<<ans;
    }

    return 0;
}