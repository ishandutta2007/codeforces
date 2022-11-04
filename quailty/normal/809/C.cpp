#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
}
int dp[35][35],fp[35][35];
void solve(int c[])
{
    memset(dp,0,sizeof(dp));
    memset(fp,0,sizeof(fp));
    dp[0][31]=1;
    for(int i=1;i<=31;i++)
    {
        int now[5];
        for(int k=0;k<5;k++)
            now[k]=c[k]>>(31-i)&1;
        for(int j=0;j<32;j++)
        {
            int st[5];
            for(int k=0;k<5;k++)
                st[k]=j>>k&1;
            for(int nx=0;nx<2;nx++)
                for(int ny=0;ny<2;ny++)
                {
                    if(st[0] && nx<now[0])continue;
                    if(st[1] && ny<now[1])continue;
                    if(st[2] && nx>now[2])continue;
                    if(st[3] && ny>now[3])continue;
                    if(st[4] && (nx^ny)>now[4])continue;
                    int nxt[5];
                    nxt[0]=(st[0] && nx==now[0]);
                    nxt[1]=(st[1] && ny==now[1]);
                    nxt[2]=(st[2] && nx==now[2]);
                    nxt[3]=(st[3] && ny==now[3]);
                    nxt[4]=(st[4] && (nx^ny)==now[4]);
                    int go=0;
                    for(int k=0;k<5;k++)
                        go|=(nxt[k]<<k);
                    add(dp[i][go],dp[i-1][j]);
                    add(fp[i][go],(fp[i-1][j]+1LL*dp[i-1][j]*((nx^ny)<<(31-i)))%Mod);
                }
        }
    }
    int res=0;
    for(int j=0;j<32;j++)
        add(res,dp[31][j]),add(res,fp[31][j]);
    printf("%d\n",res);
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int c[5];
        for(int i=0;i<5;i++)
            scanf("%d",&c[i]),c[i]--;
        solve(c);
    }
    return 0;
}