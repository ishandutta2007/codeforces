#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105],cnt[105][5];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n/k;i++)
    {
        for(int j=0;j<k;j++)
        {
            cnt[j][a[i*k+j]]++;
        }
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=min(cnt[i][1],cnt[i][2]);
    }
    printf("%d\n",ans);
    return 0;
}