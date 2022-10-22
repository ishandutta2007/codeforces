//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 1000011
char a[MAXN];
int main()
{
	ll ans=0,sum=0,cur=0;
	bool flag=0;
	ll n=read();
	scanf("%s",a+1);
	for(ll i=1;i<=n;++i)
	{
		sum=0;
		if(a[i]=='(')
		{
			sum=1;
			while(sum>0&&i<n)sum+=(a[++i]=='('?1:-1);
			if(i==n&&sum!=0)
			{
				puts("-1");return 0;
			}
		}
		else
		{
			sum=-1;
			++ans;
			while(sum!=0&&i<n)sum+=(a[++i]=='('?1:-1),++ans;
			if(i==n&&sum!=0)
			{
				puts("-1");return 0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}