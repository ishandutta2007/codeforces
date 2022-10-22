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
#define MAXN 1111
char a[MAXN],b[MAXN];
std::vector<ll>ans[MAXN];
ll p[MAXN];
int main()
{
	scanf("%s",a+1);
	ll n=strlen(a+1),cnt=0;
	while(1)
	{
		ll l=1,r=n,flag=0;
		while(l<r)
		{
			while(l<r&&a[l]!='(')++l;
			while(l<r&&a[r]!=')')--r;
			if(l>=r)break;
			p[++flag]=l,p[++flag]=r;
			++l,--r;
		}
		if(!flag)break;
		++cnt;
		std::sort(p+1,p+flag+1);
		for(ll i=1;i<=flag;++i)ans[cnt].push_back(p[i]);
		ll _n=0,it=1;
		for(ll i=1;i<=n;++i)
		{
			while(it<=n&&p[it]<i)++it;
			if(p[it]!=i)a[++_n]=a[i];
		}
		n=_n;
	}
	printf("%lld\n",cnt);
	for(ll i=1;i<=cnt;++i)
	{
		printf("%lld\n",ll(ans[i].size()));
		for(ll j=0;j<ans[i].size();++j)printf("%lld ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}