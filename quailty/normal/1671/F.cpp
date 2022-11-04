#include<bits/stdc++.h>
using namespace std;
const int MAXN=12;
const int MAXK=11;
const int MAXX=11;
const int MAXL=22;
const int Mod=998244353;
inline void add(int& x,int y) { (x+=y)>=Mod && (x-=Mod); }
int dp[MAXN+1][MAXN+1][MAXN+1][MAXK+2][MAXX+2];
int fp[MAXK+2][MAXL+1][MAXK+2][MAXX+2],inv[MAXK+2];
void init()
{
    for(int i=(inv[1]=1)+1;i<=MAXK;i++)
        inv[i]=(Mod-1LL*Mod/i*inv[Mod%i]%Mod)%Mod;

    dp[1][0][1][0][0]=1;
    for(int n=1;n<MAXN;n++)
    for(int m=0;m<n;m++)
    for(int f=1;f<=n;f++)
    for(int k=0;k<=MAXK;k++)
    for(int x=0;x<=MAXX;x++)
    {
        if(!dp[n][m][f][k][x])continue;
        for(int g=1;g<=n+1;g++)
        {
            int tm=(g>m+1 ? 0 : m+1),tk=k+g-1,tx=x+(g>f);
            if(tk<=MAXK && tx<=MAXX)
                add(dp[n+1][tm][g][tk][tx],dp[n][m][f][k][x]);
        }
    }
    for(int n=1;n<=MAXN;n++)
    for(int f=1;f<=n;f++)
    for(int k=0;k<=MAXK;k++)
    for(int x=0;x<=MAXX;x++)
        add(dp[n][0][0][k][x],dp[n][0][f][k][x]);

    fp[0][0][0][0]=1;
    for(int s=0;s<MAXK;s++)
    for(int n=0;n<=MAXL;n++)
    for(int k=0;k<=MAXK;k++)
    for(int x=0;x<=MAXX;x++)
    for(int tn=2;tn<=MAXN && n+tn<=MAXL;tn++)
    for(int tk=0;k+tk<=MAXK;tk++)
    for(int tx=0;x+tx<=MAXX;tx++)
        add(fp[s+1][n+tn][k+tk][x+tx],1LL*fp[s][n][k][x]*dp[tn][0][0][tk][tx]%Mod);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,x,res=0;
        scanf("%d%d%d",&n,&k,&x);
        for(int j=0;j<=MAXL && j<=n;j++)
        {
            int coef=1;
            for(int i=0;i<=MAXK;i++)
            {
                add(res,1LL*coef*fp[i][j][k][x]%Mod);
                coef=1LL*coef*(n-j+i+1)%Mod*inv[i+1]%Mod;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}