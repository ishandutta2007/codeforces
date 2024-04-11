//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
char a[1011][1011];
ll s[1011],cnt[21];
int main()
{
	ll n=read(),m=read(),ans=0;
	for(ll i=1;i<=n;++i)
		scanf("%s",&a[i][1]);
	for(ll i=1;i<=m;++i)s[i]=read();
	for(ll i=1;i<=m;++i)
	{
		for(ll j=1;j<=n;++j)
			++cnt[a[j][i]-'A'];
		ll mx=0;
		for(ll j=0;j<5;++j)
			mx=max(mx,cnt[j]),cnt[j]=0;
		ans+=mx*s[i];
	}
	printf("%lld",ans);
	return 0;
}