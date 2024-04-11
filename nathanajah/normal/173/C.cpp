#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <deque>
using namespace std;

int n,m;
int arr[1000][1000];
int prevv[1000][1000];
int now[1000][1000];
int sum[1000][1000];
int i,j,k;
int maxi;
int tmpsum;

int getsum(int x, int y, int r)
{
    int ret=0;
    ret=sum[x+r-1][y+r-1];
    if (x>0)
        ret-=sum[x-1][y+r-1];
    if (y>0)
        ret-=sum[x+r-1][y-1];
    if (x>0 && y>0)
        ret+=sum[x-1][y-1];
    return ret;
}
int main()
{
    maxi=-2000000000;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;++i)
        for (j=0;j<m;++j)
        {
            scanf("%d",&arr[i][j]);
            prevv[i][j]=arr[i][j];
        }
    sum[0][0]=arr[0][0];
    for (i=1;i<n;++i)
        sum[i][0]=arr[i][0]+sum[i-1][0];
    for (i=1;i<m;++i)
        sum[0][i]=arr[0][i]+sum[0][i-1];
    for (i=1;i<n;++i)
        for (j=1;j<m;++j)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
    for (k=3;k<=min(n,m);k+=2)
    {
        for (i=0;i<n-k+1;++i)
            for (j=0;j<m-k+1;++j)
            {
                now[i][j]=getsum(i,j,k)-prevv[i+1][j+1]-arr[i+1][j];
                if (now[i][j]>maxi)
                {
                    maxi=now[i][j];
                }
            }
        for (i=0;i<n-k+1;++i)
            for (j=0;j<m-k+1;++j)
                prevv[i][j]=now[i][j];
    }
    printf("%d\n",maxi);
}