#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300010
int n,k;
ll a[N];
int c[N];
int dp[N];
int lowbit(int x)
{
    return x&(-x);
}
int ask(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x))
        ans+=c[x];
    return ans;
}
void change(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        c[x]+=y;
}
bool ok(ll mid)
{
    for(int i=1;i<=n;++i)  dp[i]=0,c[i]=0;
    dp[0]=1;
    for(int i=k;i<=n;++i)
    {
        int r=i-k;
        int l=lower_bound(a+1,a+n+1,a[i]-mid)-a-1;
        if(l>r) continue;
        if(l==0 || ask(r)-ask(l-1)>0)
        {
            dp[i]=1;
            change(i,1);
        }
    }
    return dp[n];
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        sort(a+1,a+n+1);
        ll l=0,r=3e14;
        while(l<r)
        {
            ll mid=(l+r)/2;
            if(ok(mid)) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
}