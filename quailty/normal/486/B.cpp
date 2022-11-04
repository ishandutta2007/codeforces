#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105][105],b[105][105],c[105][105];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&b[i][j]);
            if(!b[i][j])
            {
                for(int k=1;k<=m;k++)a[k][j]=0;
                for(int k=1;k<=n;k++)a[i][k]=0;
            }
        }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)c[i][j]|=a[k][j];
            for(int k=1;k<=n;k++)c[i][j]|=a[i][k];
        }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(b[i][j]!=c[i][j])
                return 0*printf("NO");
    printf("YES\n");
    for(int i=1;i<=m;i++,printf("\n"))
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
    return 0;
}