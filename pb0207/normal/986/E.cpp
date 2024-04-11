#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,M=25,lim=1e7,P=1e9+7;

int n,a[N],Q;

int head[N],cnt;

struct node{
	int ne,to;
}edg[N*2+1];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int prime[lim+1],ptot,mark[lim+1],to[lim+1];

void pre()
{
	mark[1]=1;
	for(int i=2;i<=lim;i++)
	{
		if(!mark[i])
			prime[++ptot]=i,to[i]=i;
		for(int j=1;j<=ptot&&i*prime[j]<=lim;j++)
		{
			mark[i*prime[j]]=1;
			to[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}

struct OP{
	int x,y,d,id,w;
	OP(int _x=0,int _y=0,int _d=0,int _id=0,int _w=0){x=_x,y=_y,d=_d,id=_id,w=_w;}
};

vector<OP>c[N],q[N];

vector<int>fac[N];

int fa[N],anc[N][17],dep[N];

int ans[N][M];

void dfs(int i,int f)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		fa[v]=i;
		dep[v]=dep[i]+1;
		dfs(v,i);
	}
}

void prt()
{
	for(int i=1;i<=n;i++)
		anc[i][0]=fa[i];
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=16;i>=0;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=anc[x][i];
	if(x==y)
		return x;
	for(int i=16;i>=0;i--)
		if(anc[x][i]!=anc[y][i])
			x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}

int g[N][M+1];

void calc(int i,int f)
{
	for(int j=0;j<c[i].size();j++)
		g[c[i][j].x][c[i][j].y]++;
	for(int j=0;j<q[i].size();j++)
	{
		for(int k=1;k<q[i][j].y;k++)
			ans[q[i][j].id][q[i][j].w]+=g[q[i][j].x][k]*k*q[i][j].d;
		for(int k=q[i][j].y;k<=M;k++)
			ans[q[i][j].id][q[i][j].w]+=g[q[i][j].x][k]*q[i][j].y*q[i][j].d;
	}
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		calc(v,i);
	}
	for(int j=0;j<c[i].size();j++)
		g[c[i][j].x][c[i][j].y]--;
}

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	pre();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i];
		while(x!=1)
		{
			int pr=to[x],tot=0;
			while(x%pr==0)
				x/=pr,tot++;
			c[i].push_back(OP(pr,tot,0,0,0));
		}
	}
	dfs(1,0);
	prt();
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		int p=lca(u,v);
		while(x!=1)
		{
			int pr=to[x],tot=0;
			fac[i].push_back(pr);
			while(x%pr==0)
				x/=pr,tot++;
			int num=fac[i].size();
			q[u].push_back(OP(pr,tot,1,i,num));
			q[v].push_back(OP(pr,tot,1,i,num));
			q[p].push_back(OP(pr,tot,-1,i,num));
			q[fa[p]].push_back(OP(pr,tot,-1,i,num));
		}
	}
	calc(1,0);
	for(int i=1;i<=Q;i++)
	{
		ll fans=1;
		for(int j=1;j<=fac[i].size();j++)
		{
			ll a=fac[i][j-1];
			ll tot=ans[i][j];
			fans=fans*qpow(a,tot)%P;
		}
		printf("%lld\n",fans);
	}
}