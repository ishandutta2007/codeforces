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

int cnt[100007];
int l[57],r[57],w[57];
int DP[57][100007];
int P[57][100007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        for(int k=1;k<=m;k++)
        {
            bool nie=0;
            int s=0;
            for(int i=1;i<=n;i++)
            {
                int L=l[i]+(k-l[i]%k)%k;
                if(L>r[i]) nie=1;
                s+=L;
                w[i]=(r[i]-L)/k;
            }
            int M=m-s;
            if(M<0) nie=1;
            if(nie) continue;
            M/=k;
            DP[0][1]=1;
            for(int j=0;j<=M;j++) P[0][j+1]=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=M;j++)
                {
                    DP[i][j+1]=(P[i-1][j+1]-P[i-1][max(0LL,j-w[i])]+mod)%mod;
                    P[i][j+1]=(P[i][j]+DP[i][j+1])%mod;
                }
            }
            cnt[k]=P[n][M+1];
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=M;j++)
                {
                    DP[i][j+1]=0;
                    P[i][j+1]=0;
                }
            }
        }
        for(int k=m;k>0;k--)
        {
            for(int l=2*k;l<=m;l+=k) cnt[k]=(cnt[k]-cnt[l]+mod)%mod;
        }
        cout<<cnt[1];
    }

    return 0;
}