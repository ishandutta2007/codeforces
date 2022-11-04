#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int Mod=51123987;
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
}
char s[155];
int dp[155][55][55][55],go[155][3];
int main()
{
    int n;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
        {
            go[i][j]=n;
            for(int k=n-1;k>=i;k--)
                if(s[k]=='a'+j)go[i][j]=k;
        }
    dp[0][0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<54;j++)
            for(int k=0;k<54;k++)
                for(int l=0;l<54;l++)
                {
                    add(dp[go[i][0]][j+1][k][l],dp[i][j][k][l]);
                    add(dp[go[i][1]][j][k+1][l],dp[i][j][k][l]);
                    add(dp[go[i][2]][j][k][l+1],dp[i][j][k][l]);
                }
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<54;j++)
            for(int k=0;k<54;k++)
                for(int l=0;l<54;l++)
                    if(j+k+l==n && abs(j-k)<=1 && abs(k-l)<=1 && abs(j-l)<=1)
                        add(res,dp[i][j][k][l]);
    return 0*printf("%d",res);
}