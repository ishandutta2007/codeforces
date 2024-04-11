#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105][105];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(k>=2-(i==j))
            {
                a[i][j]=a[j][i]=1;
                k-=2-(i==j);
            }
    if(k>0)printf("-1");
    else for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
    return 0;
}