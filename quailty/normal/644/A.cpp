#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int res[105][105];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int cnt=0,flag=0;
    for(int i=0;i<a;i++)
    {
        if(!flag)
        {
            for(int j=0;j<b;j++)
                res[i][j]=++cnt;
        }
        else
        {
            for(int j=b-1;j>=0;j--)
                res[i][j]=++cnt;
        }
        if(~b&1)flag^=1;
    }
    if(cnt<n)printf("-1\n");
    else
    {
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
                printf("%d ",(res[i][j]>n ? 0 : res[i][j]));
            printf("\n");
        }
    }
    return 0;
}