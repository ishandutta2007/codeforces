//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
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
#define MAXN 500011
char s[MAXN];
ll a[MAXN],tmp[MAXN],sum[MAXN],premin[MAXN];
ll calc(ll n)
{
    premin[0]=INF;
    for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+a[i],premin[i]=min(premin[i-1],sum[i]);
    if(!premin[n])return 1;
    ll sufmin=INF,s=0;
    for(ll i=n;i>1;--i)
    {
        sufmin=min(sufmin+a[i],a[i]);
        s+=a[i];
        if(s+premin[i]>=0&&sufmin>=0)return i;
    }
    return -1;
}
int main()
{
    ll n=read();scanf("%s",s+1);
    for(ll i=1;i<=n;++i)a[i]=(s[i]=='('?1:-1),sum[i]=sum[i-1]+a[i];
    if((n&1)||sum[n])return printf("0\n1 1")&0;
    ll pos=calc(n);
    if(pos==-1)return printf("0\n1 1")&0;
    for(ll i=pos;i<=n;++i)tmp[i-pos+1]=a[i];
    for(ll i=1;i<pos;++i)tmp[n-pos+1+i]=a[i];
    ll maxv,ansx,ansy,c0=0;
    for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+tmp[i],a[i]=tmp[i],c0+=!sum[i];
    maxv=c0,ansx=ansy=1;
    for(ll i=1,j;i<=n;i=j)//1 -> -1
	{
		j=i+1;
		if(sum[i]<1)continue;
		ll cur=(sum[i]==1);
		while(j<=n&&sum[j]>=1)
			cur+=(sum[j]==1),++j;
		if(umax(maxv,cur))ansx=i,ansy=j; 
	}
	for(ll i=1,j;i<=n;i=j)
	{
		j=i+1;
		if(sum[i]<2)continue;
		ll cur=(sum[i]==2);
		while(j<=n&&sum[j]>=2)cur+=(sum[j]==2),++j;
		if(umax(maxv,cur+c0))ansx=i,ansy=j;
	}
    if(ansx<=n-pos+1)ansx+=pos-1;
    else ansx-=(n-pos+1);
    if(ansy<=n-pos+1)ansy+=pos-1;
    else ansy-=(n-pos+1);
    printf("%lld\n%lld %lld",maxv,ansx,ansy);
}