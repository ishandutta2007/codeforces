#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,r;
int i,j,k,l;
int jarak[70][70][70];
int jmin[70][70];
int dp[70][70][70];
int s,t,kk;

int hitung(int s, int t,int k)
{
    if (k>60)
        k=60;
    int &ret=dp[s][t][k];
    if (ret>=0)
        return ret;
    int i,j;
    ret=2000000000;
    for (i=0;i<m;++i)
    {
        ret=min(jarak[i][s][t],ret);
    }
    if (k>0)
    {
        for (j=0;j<n;++j)
            ret=min(jmin[s][j]+hitung(j,t,k-1),ret);
    }
//    printf("%d %d %d\n",s,k,ret);
    return ret;
}
int main()
{
    scanf("%d %d %d",&n,&m,&r);
    for (l=0;l<m;++l)
    {
        for (i=0;i<n;++i)
            for (j=0;j<n;++j)
                scanf("%d",&jarak[l][i][j]);
        for (k=0;k<n;++k)
            for (i=0;i<n;++i)
                for (j=0;j<n;++j)
                    jarak[l][i][j]=min(jarak[l][i][j],jarak[l][i][k]+jarak[l][k][j]);
/*        printf("DEBUG\n");
        for (i=0;i<n;++i)
        {
            for (j=0;j<n;++j)
                printf("%d ",jarak[l][i][j]);
            printf("\n");
        }
        printf("DEBUG\n");*/
    }
    for (i=0;i<n;++i)
        for (j=0;j<n;++j)
        {
            jmin[i][j]=2000000000;
            for (k=0;k<m;++k)
                jmin[i][j]=min(jmin[i][j],jarak[k][i][j]);
        }
    memset(dp,-1,sizeof(dp));
    for (i=0;i<r;++i)
    {
        scanf("%d %d %d",&s,&t,&kk);
        --s;
        --t;
        printf("%d\n",hitung(s,t,kk));
    }
}