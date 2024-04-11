#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1;j++)
            a[i][j]=((i+j)%(n-1)==0 ? n-1 : (i+j)%(n-1));
    for(int i=0;i<n;i++)
        a[i][n-1]=a[n-1][i]=a[i][i];
    for(int i=0;i<n;i++)
        a[i][i]=0;
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<n;j++)
            printf("%s%d",(j==0 ? "" : " "),a[i][j]);
    return 0;
}