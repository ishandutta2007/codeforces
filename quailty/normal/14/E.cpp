#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[25][15][15][5][5];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            dp[2][0][0][i][j]=(i!=j);
    for(int i=2;i<n;i++)
        for(int j=0;j<=t;j++)
            for(int k=0;k<=t-1;k++)
                for(int l=1;l<=4;l++)
                    for(int m=1;m<=4;m++)
                        if(l!=m)for(int r=1;r<=4;r++)
                            if(r!=m)
                            {
                                if(l<m && m>r)dp[i+1][j+1][k][m][r]+=dp[i][j][k][l][m];
                                else if(l>m && m<r)dp[i+1][j][k+1][m][r]+=dp[i][j][k][l][m];
                                else dp[i+1][j][k][m][r]+=dp[i][j][k][l][m];
                            }
    ll res=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            res+=dp[n][t][t-1][i][j];
    printf("%I64d",res);
    return 0;
}