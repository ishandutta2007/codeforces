#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int c[105][105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&c[i][j]);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int now=1000000000;
        for(int j=0;j<m;j++)
            now=min(now,c[i][j]);
        res=max(res,now);
    }
    printf("%d\n",res);
    return 0;
}