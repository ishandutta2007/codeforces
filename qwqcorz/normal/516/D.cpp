#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge{int to,val;};
vector<edge>e[N];
int rt; ll mx;
void dfs0(int now,int father,ll len)
{
	if (len>mx) rt=now,mx=len;
	for (edge i:e[now]) if (i.to!=father) dfs0(i.to,now,len+i.val);
}
ll f[N];
void dfs1(int now,int father,ll len)
{
	f[now]=max(f[now],len);
	for (edge i:e[now]) if (i.to!=father) dfs1(i.to,now,len+i.val);
}
int id[N];
ll k[N];
int c[N],deep[N],ans;
void dfs(int now,int father,ll x)
{
	deep[now]=deep[father]+1;
	k[deep[now]]=f[now];
	id[deep[now]]=now;
	c[now]++,c[id[lower_bound(k+1,k+1+deep[now],f[now]-x)-k-1]]--;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father) continue;
		dfs(to,now,x);
		c[now]+=c[to];
	}
	ans=max(ans,c[now]);
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	mx=rt=0,dfs0(1,0,0);int x=rt;
	mx=rt=0,dfs0(x,0,0);int y=rt;
	dfs1(x,0,0),dfs1(y,0,0);
	for (int i=1;i<=n;i++) if (f[i]<f[rt]) rt=i;
	int Q=read();
	while (Q--)
	{
		ans=0;
		memset(c,0,sizeof(c));
		ll x=read();
		dfs(rt,0,x);
		print(ans);
	}
	
	return 0;
}