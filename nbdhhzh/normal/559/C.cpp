#include<bits/stdc++.h>
#define PII pair<int,int>
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define mod 1000000007
#define N 200010
#define M 2000010
using namespace std;
long long jc[N],ny[N],f[N],ans;
int h,w,n,i,j;
struct stp{int x,y;}a[N];
bool cmp(stp x,stp y){if(x.x!=y.x)return x.x<y.x;return x.y<y.y;}
long long powmod(long long x,long long y)
{
    long long ans=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)ans=ans*x%mod;
    return ans;
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    jc[0]=ny[0]=1;
    for(i=1;i<=h+w;i++)jc[i]=jc[i-1]*i%mod;
    ny[h+w]=powmod(jc[h+w],mod-2);
    for(i=h+w-1;i>=1;i--)ny[i]=ny[i+1]*(i+1)%mod;
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    ans=jc[h+w-2]*ny[h-1]%mod*ny[w-1]%mod;
    for(i=1;i<=n;i++)
    {
        f[i]=jc[a[i].x+a[i].y-2]*ny[a[i].x-1]%mod*ny[a[i].y-1]%mod;
        for(j=1;j<i;j++)if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
            f[i]-=f[j]*jc[a[i].x+a[i].y-a[j].x-a[j].y]%mod*ny[a[i].x-a[j].x]%mod*ny[a[i].y-a[j].y]%mod;
        f[i]=(f[i]%mod+mod)%mod;
        ans=ans-f[i]*jc[h+w-a[i].y-a[i].x]%mod*ny[h-a[i].x]%mod*ny[w-a[i].y]%mod;
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
}