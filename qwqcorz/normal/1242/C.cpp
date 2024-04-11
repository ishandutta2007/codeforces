#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll K=20;
const ll N=5e3+5;
const ll S=1<<16;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
map<ll,ll>id;
vector<ll>h[S];
bool used[K*N],vis[K*N],f[S];
ll n[N],s[K],a[K][N],to[K*N],bel[K*N],val[K*N],from[S],c[K],p[K];
stack<ll>st;
void get(ll x)
{
	if (!h[x].empty())
	{
		for (ll i:h[x]) c[bel[i]]=val[i],p[bel[to[i]]]=bel[i];
		return;
	}
	get(from[x]);
	get(x^from[x]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll k=read(),cnt=0,sum=0;
	for (ll i=1;i<=k;i++)
	{
		n[i]=read();
		for (ll j=1;j<=n[i];j++)
		{
			id[a[i][j]=read()]=++cnt;
			bel[cnt]=i;
			val[cnt]=a[i][j];
			s[i]+=a[i][j];
			sum+=a[i][j];
		}
	}
	if (sum%k) return puts("No"),0;
	sum/=k;
	for (ll i=1;i<=k;i++)
	for (ll j=1;j<=n[i];j++)
	{
		ll t=sum-(s[i]-a[i][j]);
		if (id.count(t)) to[id[a[i][j]]]=id[t];
	}
	for (ll i=1;i<=cnt;i++) if (!used[i])
	{
		ll now=i;
		while (1)
		{
			vis[now]=1;
			st.push(now);
			if (!to[now]) break;
			if (used[to[now]]) break;
			if (vis[to[now]])
			{
				if (to[now]==now)
				{
					f[1<<(bel[now]-1)]=1;
					h[1<<(bel[now]-1)].clear();
					h[1<<(bel[now]-1)].push_back(now);
					break;
				}
				vector<ll>tmp(0);
				ll ed=to[now],x,state=0,flag=1;
				do
				{
					x=st.top();
					vis[x]=0;
					used[x]=1;
					tmp.push_back(x);
					if (state&(1<<(bel[x]-1))) flag=0;
					state|=1<<(bel[x]-1);
					st.pop();
				}while (x!=ed);
				if (flag)
					f[state]=1,
					h[state]=tmp;
				break;
			}
			now=to[now];
		}
		while (!st.empty()) vis[st.top()]=0,used[st.top()]=1,st.pop();
	}
	for (ll i=1;i<(1<<k);i++)
	for (ll j=(i-1)&i;j;j=(j-1)&i)
	if (f[j]&&f[i^j])
	{
		f[i]=1;
		from[i]=j;
	}
	if (f[(1<<k)-1])
	{
		puts("Yes");
		get((1<<k)-1);
		for (ll i=1;i<=k;i++) print(c[i],' '),print(p[i]);
	}
	else puts("No");
	
	return 0;
}