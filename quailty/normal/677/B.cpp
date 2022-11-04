#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int n,h,k;
    scanf("%d%d%d",&n,&h,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=h;
    long long res=0,now=0;
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        long long t=max((now-(h-a[i+1])+k-1)/k,0LL);
        res+=t;
        now-=t*k;
        now=max(now,0LL);
    }
    return 0*printf("%I64d",res);
}