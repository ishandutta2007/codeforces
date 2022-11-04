#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[2000005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int in;
        scanf("%d",&in);
        cnt[in]++;
    }
    for(int i=0;i<2000000;i++)
    {
        cnt[i+1]+=cnt[i]/2;
        cnt[i]%=2;
    }
    int ans=0;
    for(int i=0;i<=2000000;i++)
    {
        ans+=cnt[i];
    }
    printf("%d\n",ans);
    return 0;
}