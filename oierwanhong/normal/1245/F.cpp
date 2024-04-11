//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 41
ll f[2][2][MAXN];
ll mdfs(ll L,ll R,ll x,bool up1,bool up2)
{
    if(x<0)return 1;
    ll &cur=f[up1][up2][x];
    if(cur>=0)return cur;
    cur=0;
    ll lim1=1,lim2=1;
    if(up1)lim1=(L>>x)&1;
    if(up2)lim2=(R>>x)&1;
    for(ll i=0;i<=lim1;++i)
        for(ll j=0;j<=lim2;++j)
            if(!(i&j))
                cur+=mdfs(L,R,x-1,up1&i==lim1,up2&j==lim2);
    return cur;
}
ll calc(ll l,ll r)//prefix
{
    if(l<0||r<0)return 0;
    memset(f,-1,sizeof f);
    return mdfs(l,r,31,1,1);
}
int main()
{
    ll t=read();
    while(t--)
    {
        ll l=read(),r=read();
        printf("%lld\n",calc(r,r)-calc(l-1,r)-calc(r,l-1)+calc(l-1,l-1));
    }
    return 0;
}