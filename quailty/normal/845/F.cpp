#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    x+=y;
    x=(x>=Mod ? x-Mod : x);
}
char s[255][255],t[255][255];
int dp[2][(1<<15)+5][2][2];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    if(n<m)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                t[j][i]=s[i][j];
        memcpy(s,t,sizeof(t));
        swap(n,m);
    }
    int now=0,la=1;
    dp[now][0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            swap(now,la);
            memset(dp[now],0,(1<<m)*sizeof(dp[now][0]));
            for(int mask=0;mask<(1<<m);mask++)
                for(int k=0;k<2;k++)
                    for(int l=0;l<2;l++)
                    {
                        if(s[i][j]=='x')
                            add(dp[now][mask&(~0^(1<<j))][0][l],dp[la][mask][k][l]);
                        else
                        {
                            int gg=(~mask>>j&1) && (k==0 || j==0);
                            if(gg+l<2)add(dp[now][mask][k&(j>0)][gg+l],dp[la][mask][k][l]);
                            add(dp[now][mask|(1<<j)][1][l],dp[la][mask][k][l]);
                        }
                    }
        }
    int res=0;
    for(int mask=0;mask<(1<<m);mask++)
        for(int k=0;k<2;k++)
            for(int l=0;l<2;l++)
                add(res,dp[now][mask][k][l]);
    return 0*printf("%d\n",res);
}