#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[3][4];
const int p[4]={2,3,5};
int main()
{
    int a[3];
    scanf("%d%d",&a[0],&a[1]);
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=2;j++)
        {
            while(a[i]%p[j]==0)
            {
                a[i]/=p[j];
                cnt[i][j]++;
            }
        }
    }
    if(a[0]!=a[1])
    {
        printf("-1\n");
    }
    else
    {
        int ans=0;
        for(int j=0;j<=2;j++)
        {
            ans+=abs(cnt[0][j]-cnt[1][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}