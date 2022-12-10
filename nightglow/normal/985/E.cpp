#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 551010
int a[N],f[N];
int n,k,d;
int sum;
int main()
{
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=-1;
    sum=0;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        while(r<i-k) sum+=f[++r];
        while(a[l+1]+d<a[i]&&l<=r) sum-=f[l++];
        f[i]=(sum?1:0);
    }
    if(f[n]) puts("YES");
    else puts("NO");
    return 0;
}