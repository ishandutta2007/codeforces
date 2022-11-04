#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[105][105];
int cnt[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++)
    {
        int loc=INF,Max=0;
        for(int j=n;j>=1;j--)
        {
            if(Max<=a[i][j])
            {
                Max=a[i][j];
                loc=j;
            }
        }
        cnt[loc]++;
    }
    int loc=INF,Max=0;
    for(int i=n;i>=1;i--)
    {
        if(Max<=cnt[i])
        {
            Max=cnt[i];
            loc=i;
        }
    }
    printf("%d\n",loc);
    return 0;
}