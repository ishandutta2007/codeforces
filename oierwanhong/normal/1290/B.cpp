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
#define MAXN 200011
ll sum[26][MAXN];
ll count(ll x,ll l,ll r)
{
	return sum[x][r]-sum[x][l-1];
}
char s[MAXN];
int main()
{
	scanf("%s",s+1);
	ll n=strlen(s+1),q=read();
	for(ll i=1;i<=n;++i)
	{
		for(ll j=0;j<26;++j)
			sum[j][i]=sum[j][i-1]+(s[i]-'a'==j);
	}
	for(ll i=1;i<=q;++i)
	{
		ll l=read(),r=read();
		if(l==r||s[l]!=s[r])
		{
			puts("Yes");continue;
		}
		ll cnt=0;
		for(ll j=0;j<26;++j)
			if((s[l]-'a'!=j)&&count(j,l,r))++cnt;
		puts(cnt>1?"Yes":"No");
	}
	return 0;
}