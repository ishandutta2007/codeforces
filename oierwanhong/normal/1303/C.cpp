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
bool g[31][31],vis[31];
ll deg[31];
char s[511];
void work(ll u)
{
	vis[u]=1;
	putchar('a'+u);
	for(ll v=0;v<26;++v)
		if(g[u][v]&&!vis[v])
		{
			work(v);
		}
}
int main()
{
	ll task=read();
	while(task--)
	{
		memset(g,0,sizeof g);memset(deg,0,sizeof deg);memset(vis,0,sizeof vis);
		scanf("%s",s+1);
		ll n=strlen(s+1);
		if(n==1)
		{
			puts("YES");
			putchar(s[1]);
			for(ll i=0;i<26;++i)
				if(s[1]!='a'+i)putchar('a'+i);
			putchar('\n');
			continue;
		}
		for(ll i=1;i<n;++i)
		{
			ll u=s[i]-'a',v=s[i+1]-'a';
			g[u][v]=g[v][u]=1;
		}
		for(ll u=0;u<26;++u)
			for(ll v=0;v<u;++v)
				if(g[u][v])++deg[u],++deg[v];
		ll s=0,c=0;
		bool flag=0;
		for(ll i=0;i<26;++i)
		{
			if(deg[i]>2)flag=1;
			if(deg[i]&1)++c,s=i;
		}
		if(c!=2||flag)puts("NO");
		else
		{
			puts("YES");
			work(s);
			for(ll i=0;i<26;++i)
				if(!vis[i])putchar('a'+i);
			putchar('\n');
		}
	}
	return 0;
}