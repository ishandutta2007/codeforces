//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
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
void write(ll x,char c=' ')
{
	if(x==0)
	{
		putchar('0'),putchar(c);
		return;
	}
	ll a[20],top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}
	while(top)putchar(a[top--]+'0');
	putchar(c);
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}

/**********/
#define MAXN 200011
struct Edge
{
	ll v,w,nxt;
}e[MAXN<<1|1];
ll last[MAXN],tot=0;
void adde(ll u,ll v)
{
	++tot;
	e[tot].v=v;
	e[tot].nxt=last[u];last[u]=tot;
}
ll q[MAXN],dep[MAXN];
bool del[MAXN];
void work()
{
	tot=0;
	ll n=read(),m=read();
	for(ll i=1;i<=n;++i)
		last[i]=dep[i]=del[i]=0;
	for(ll i=1;i<=m;++i)
	{
		ll u=read(),v=read();
		adde(u,v);adde(v,u);
	}
	ll h=1,t=1,cnt=0;
	q[t++]=1;dep[1]=1;
	while(h<t)
	{
		ll u=q[h++];
		if(!(dep[u]&1))del[u]=1,++cnt;
		for(ll i=last[u];i;i=e[i].nxt)
		{
			ll v=e[i].v;
			if(dep[v])continue;
			dep[v]=dep[u]+1;
			q[t++]=v;
		}
	}
	if(cnt>n/2)
	{
		write(n-cnt,'\n');
		for(ll i=1;i<=n;++i)
			if(!del[i])write(i);
	}
	else
	{
		write(cnt,'\n');
		for(ll i=1;i<=n;++i)
			if(del[i])write(i);
	}
	putchar('\n');
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}