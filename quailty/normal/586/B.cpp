#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int a[2][55],b[55];
int cost[55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<2;i++)
        for(int j=1;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            cost[i]+=a[0][j];
        cost[i]+=b[i];
        for(int j=i;j<n;j++)
            cost[i]+=a[1][j];
    }
    sort(cost+1,cost+n+1);
    printf("%d\n",cost[1]+cost[2]);
    return 0;
}