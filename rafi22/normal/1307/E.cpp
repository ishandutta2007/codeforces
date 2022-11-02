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

int s[5007];
vector<int>posL[5007];
vector<int>posR[5007];
int L[5007];
int R[5007];
int f[5007];
int h[5007];
int r[5007];
int X[5007];
int Y[5007];
int Z[5007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++) posL[s[i]].pb(i);
        for(int i=n;i>0;i--) posR[s[i]].pb(i);
        for(int i=1;i<=m;i++)
        {
            cin>>f[i]>>h[i];
            if(sz(posL[f[i]])>=h[i])
            {
                L[i]=posL[f[i]][h[i]-1];
                R[i]=posR[f[i]][h[i]-1];
                //cout<<L[i]<<" "<<R[i]<<endl;
                r[R[i]]=i;
            }
            else
            {
                L[i]=inf;
                R[i]=-inf;
            }
        }
        int a1=0,a2=1;
        for(int i=1;i<=n;i++)
        {
            if(r[i]==0) continue;
           // cout<<i<<endl;
            memset(X,0,sizeof X);
            memset(Y,0,sizeof Y);
            memset(Z,0,sizeof Z);
            for(int j=1;j<=m;j++)
            {
                if(j==r[i]) continue;
                if(L[j]<i&&R[j]>i) Z[f[j]]++;
                else if(L[j]<i) X[f[j]]++;
                else if(R[j]>i) Y[f[j]]++;
            }
            int b1=1,b2=1;
            for(int j=1;j<=n;j++)
            {
                //cout<<X[j]<<" "<<Z[j]<<" "<<Y[j]<<endl;
                if(j==s[i])
                {
                    if(X[j]+Z[j]>0)
                    {
                        b1++;
                        b2=b2*(X[j]+Z[j])%mod;
                    }
                }
                else
                {
                    if(X[j]+Y[j]+Z[j]==0) ;
                    else if(X[j]>0&&Y[j]+Z[j]==0)
                    {
                        b1++;
                        b2=b2*X[j]%mod;
                    }
                    else if(Y[j]>0&&X[j]+Z[j]==0)
                    {
                        b1++;
                        b2=b2*Y[j]%mod;
                    }
                    else if(Z[j]==1&&X[j]+Y[j]==0)
                    {
                        b1++;
                        b2=b2*2%mod;
                    }
                    else
                    {
                        b1+=2;
                        int ways=X[j]*Y[j]+Z[j]*Y[j]+X[j]*Z[j]+Z[j]*(Z[j]-1);
                        b2=b2*ways%mod;
                    }
                }
            }
           // cout<<b1<<" "<<b2<<endl;
            if(b1>a1)
            {
                a1=b1;
                a2=b2;
            }
            else if(b1==a1) a2=(a2+b2)%mod;
        }
        memset(X,0,sizeof X);
        for(int j=1;j<=m;j++)
        {
            if(L[j]!=inf) X[f[j]]++;
        }
        int b1=0,b2=1;
        for(int i=1;i<=n;i++)
        {
            if(X[i])
            {
                b1++;
                b2=b2*X[i]%mod;
            }
        }
        if(b1>a1)
        {
            a1=b1;
            a2=b2;
        }
        else if(b1>0&&b1==a1) a2=(a2+b2)%mod;
        cout<<a1<<" "<<a2<<endl;
    }

    return 0;
}