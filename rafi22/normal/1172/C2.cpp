#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int M=3007,N=200007;

bool is[200007];
int w[N];

int P[M][M];
int DP0[M][M];
int DP1[M][M];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

signed main()
{
    mod=mod1;
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
        for(int i=1;i<=n;i++) cin>>is[i];
        int s0=0,s1=0;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
            if(is[i]) s1+=w[i];
            else s0+=w[i];
        }
        P[0][0]=1;
        DP0[0][0]=1;
        DP1[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int S0=s0-(i-j),S1=s1+j;
                int inv=pot((S0+S1)%mod,mod-2);
                DP1[i+1][j+1]=(DP1[i+1][j+1]+(S1+1)*inv%mod*DP1[i][j])%mod;
                DP1[i+1][j]=(DP1[i+1][j]+S0*inv%mod*DP1[i][j])%mod;
                DP0[i+1][j+1]=(DP0[i+1][j+1]+S1*inv%mod*DP0[i][j])%mod;
                DP0[i+1][j]=(DP0[i+1][j]+(S0-1+mod)*inv%mod*DP0[i][j])%mod;
            }
        }
        int c1=0,c0=0;
        int a=0;
        for(int i=0;i<=m;i++)
        {
            c1=(c1+DP1[m][i])%mod;
            c0=(c0+DP0[m][i])%mod;
        }
        for(int i=1;i<=n;i++)
        {
            if(is[i]) cout<<c1*w[i]%mod<<endl;
            else cout<<c0*w[i]%mod<<endl;
        }
    }

    return 0;
}