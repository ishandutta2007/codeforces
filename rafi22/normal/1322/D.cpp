#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=2007;

int DP[N][N];
int l[N];
int s[N];
int c[2*N];
int last[N][N];
int P[N];

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
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>l[i];
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n+m;i++) cin>>c[i];
        for(int i=1;i<=n;i++) s[i]-=c[l[i]];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) last[i][j]=last[i-1][j];
            last[i][l[i]]=i;
        }
        for(int i=1;i<=n+1;i++) for(int j=0;j<=n;j++) DP[i][j]=-inf;
        for(int i=n+1;i>0;i--)
        {
            DP[i][0]=P[l[i]];
            for(int j=n;j>0;j--) DP[i][j]=max(DP[i][j],DP[i][j-1]-s[i]);
            for(int j=0;j<=n;j++)
            {
                //cout<<DP[i][j]<<" ";
                int x=j,sum=0;
                for(int k=l[i];;k++)
                {
                    if(x==0)
                    {
                        ans=max(ans,DP[i][j]+sum);
                        if(k<=m) P[k]=max(P[k],DP[i][j]+sum);
                        break;
                    }
                    if(k<=m)
                    {
                        int z=last[i-1][k];
                        if(z>0) DP[z][x]=max(DP[z][x],DP[i][j]+sum);
                    }
                    x/=2;
                    sum+=x*c[k+1];
                }
            }
            for(int j=1;j<=m;j++) P[j]=max(P[j],P[j-1]);
        }
        cout<<ans;
    }

    return 0;
}