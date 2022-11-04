#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
const ll INF=(1LL<<60)-1;
ll a[MAXN],b[MAXN],pre[MAXN],suf[MAXN];
int locp[MAXN],locs[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<=n+1;i++)
        pre[i]=suf[i]=-INF;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
            if(pre[i]<2*b[j]-b[i])//[1,j]-[j+1,i] => [0,j)-[j,i)
            {
                pre[i]=2*b[j]-b[i];
                locp[i]=j;
            }
    for(int i=n;i>=1;i--)
        b[i]=b[i+1]+a[i];
    for(int i=1;i<=n+1;i++)
        for(int j=i;j<=n+1;j++)
            if(suf[i]<b[i]-2*b[j])//[i,j-1]-[j,n] => [i,j-1)-[j-1,n)
            {
                suf[i]=max(suf[i],b[i]-2*b[j]);
                locs[i]=j-1;
            }
    int mx=0;
    for(int i=0;i<=n;i++)
        if(pre[mx]+suf[mx+1]<pre[i]+suf[i+1])
            mx=i;
    printf("%d %d %d\n",locp[mx],mx,locs[mx+1]);
    return 0;
}