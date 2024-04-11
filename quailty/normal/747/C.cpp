#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--)
    {
        int t,k,d,cnt=0;
        scanf("%d%d%d",&t,&k,&d);
        for(int i=1;i<=n;i++)
            cnt+=(t>a[i]);
        if(cnt<k)
        {
            printf("-1\n");
            continue;
        }
        int res=0;
        for(int i=1;i<=n && k;i++)if(t>a[i])
        {
            a[i]=t+d-1;
            res+=i;
            k--;
        }
        printf("%d\n",res);
    }
    return 0;
}