#include<cstdio>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
#define MAXN 300011
ll val[MAXN],res[MAXN][3];
std::vector<pll>p;
int main()
{
	ll n=read(),m=read();
	for(ll i=1;i<=m;++i)
	{
		ll u=read(),v=read(),w=read();
		val[u]-=w,val[v]+=w;
	}
	for(ll i=1;i<=n;++i)
		if(val[i]<0)p.push_back(pll(i,-val[i]));
	ll len=0;
	for(ll i=1;i<=n;++i)
		while(val[i]>0)
		{
			ll cur=std::min(val[i],p.back().second);
			++len;
			res[len][0]=p.back().first;
			res[len][1]=i,res[len][2]=cur;
			val[i]-=cur;p.back().second-=cur;
			if(!p.back().second)
			{
				p.pop_back();
			}
		}
	printf("%lld\n",len);
	for(ll i=1;i<=len;++i)
		printf("%lld %lld %lld\n",res[i][0],res[i][1],res[i][2]);
	return 0;
}