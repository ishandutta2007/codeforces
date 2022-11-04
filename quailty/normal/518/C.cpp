#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int f[100005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[a[i]]=i;
    }
    int b;
    long long cnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b);
        int t=f[b];
        cnt+=(t-1)/k+1LL;
        if(t>1)
        {
            int temp=a[t];
            a[t]=a[t-1];
            a[t-1]=temp;
            f[a[t]]++;
            f[a[t-1]]--;
        }
    }
    printf("%I64d\n",cnt);
    return 0;
}