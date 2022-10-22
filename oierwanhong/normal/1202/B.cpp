//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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
str a;
ll cnt[11][11],dp[11][11];
int main()
{
	std::cin>>a;
	for(ll i=0;i<a.size()-1ll;++i)
		++cnt[a[i]-'0'][a[i+1]-'0'];
	for(ll x=0;x<=9;++x)
		for(ll y=0;y<=9;++y)
		{
			memset(dp,0x3f,sizeof dp);
			for(ll s=0;s<=9;++s)
				for(ll i=0;i<=9;++i)
					for(ll j=0;j<=9;++j)
					{
						if(i+j==0)continue;
						ll t=(s+i*x+j*y)%10;
						umin(dp[s][t],i+j);
					}
			ll ans=0;
			for(ll s=0;s<=9;++s)
				for(ll t=0;t<=9;++t)
				{
					if(dp[s][t]>20&&cnt[s][t])
					{
						ans=-1,s=10,t=10;
						break;
					}
					ans+=(dp[s][t]-1)*cnt[s][t];
				}
			printf("%lld%c",ans,y==9?'\n':' ');
		}
	return 0;
}