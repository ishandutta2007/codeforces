//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
ll fa[MAXN],dep[MAXN];
void work()
{
    ll n=read(),sum_dep=read(),cur=0,pos;
    dep[0]=-1;
    for(ll i=1;i<=n;++i)
    {
        fa[i]=i>>1;dep[i]=dep[i>>1]+1;cur+=dep[i];
        if((i&(i-1))==0)pos=i;
    }
    sum_dep-=cur;
    if(sum_dep<0){puts("NO");return;}
    if(sum_dep==0)
    {
    	puts("YES");
        for(ll i=2;i<=n;++i)printf("%lld ",fa[i]);
        puts("");
        return;
    }
    for(ll i=n;i;--i)
    {
        if((i&(i-1))==0)continue;
        sum_dep-=dep[pos]+1-dep[i];
        if(sum_dep<=0)
        {
            while(sum_dep)pos=fa[pos],++sum_dep;
            sum_dep=0;
            fa[i]=pos;break;
        }
        fa[i]=pos,dep[i]=dep[pos]+1,pos=i;
    }
    if(sum_dep)puts("NO");
    else
    {
    	puts("YES");
        for(ll i=2;i<=n;++i)printf("%lld ",fa[i]);
        puts("");
    }
    
}
int main()
{
    ll t=read();
    while(t--)work();
}