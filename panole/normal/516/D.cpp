#include<bits/stdc++.h>
using namespace std;

const long long lim=100000000000ll;
long long qv[61],dis[100010],ma,nw,dep[100010];
int n,Q,ans[61],x,y,v,hd[100010],cnt,q[100010],l,r,maa,la[100010],rt[100010];
struct node{int to,next,val;}e[200010];
struct seg{int ls,rs,val;}t[6000010];

void addedge(int x,int y ,int v)
{
	e[++cnt]=(node){y,hd[x],v},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],v},hd[y]=cnt;
}

void add(int i,long long l,long long r,long long x)
{
	t[i].val++;
	if (l==r) return;
	long long mid=(l+r)>>1;
	if (x<=mid) add(t[i].ls?t[i].ls:(t[i].ls=(++cnt)),l,mid,x);
	else add(t[i].rs?t[i].rs:(t[i].rs=(++cnt)),mid+1,r,x);
}

int query(int i,long long l,long long r,long long ql,long long qr)
{
	if (l==ql&&r==qr) return t[i].val;
	long long mid=(l+r)>>1;
	if (qr<=mid) return t[i].ls?query(t[i].ls,l,mid,ql,qr):0;
	if (ql>mid) return t[i].rs?query(t[i].rs,mid+1,r,ql,qr):0;
	return (t[i].ls?query(t[i].ls,l,mid,ql,mid):0)+(t[i].rs?query(t[i].rs,mid+1,r,mid+1,qr):0);
}

void merge(int i,int I,long long l,long long r)
{
	t[i].val+=t[I].val;
	if (l==r) return;
	long long mid=(l+r)>>1;
	if (t[i].ls) {if (t[I].ls) merge(t[i].ls,t[I].ls,l,mid);} else t[i].ls=t[I].ls;
	if (t[i].rs) {if (t[I].rs) merge(t[i].rs,t[I].rs,mid+1,r);} else t[i].rs=t[I].rs;
}

void dfs(int x,int fa)
{
	rt[x]=(++cnt),add(rt[x],0,lim,dep[x]);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) 
		{
			if (dep[e[i].to]==-1) dep[e[i].to]=dep[x]+e[i].val;
			dfs(e[i].to,x),merge(rt[x],rt[e[i].to],0,lim);
		}
	for (int i=1; i<=Q; i++) ans[i]=max(ans[i],query(rt[x],0,lim,dep[x],dep[x]+qv[i]));
}

int main()
{
	scanf("%d",&n),cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) 
	{
		scanf("%d%d%d",&x,&y,&v);
		addedge(x,y,v);
	}
	scanf("%d",&Q);
	for (int i=1; i<=Q; i++) scanf("%I64d",&qv[i]),ans[i]=0;
	for (int i=2; i<=n; i++) dis[i]=-1;
	dis[1]=0,q[l=r=1]=1;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis[e[i].to]==-1) dis[e[i].to]=dis[x]+e[i].val,q[++r]=e[i].to;
	}
	ma=0,maa=0;
	for (int i=1; i<=n; i++) if (dis[i]>ma) ma=dis[i],maa=i;
	for (int i=1; i<=n; i++) dis[i]=-1;
	dis[maa]=0,q[l=r=1]=maa;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis[e[i].to]==-1) dis[e[i].to]=dis[x]+e[i].val,q[++r]=e[i].to,la[e[i].to]=((i&1)?(i+1):(i-1));
	}
	ma=0,maa=0,nw=0;
	for (int i=1; i<=n; i++) if (dis[i]>ma) ma=dis[i],maa=i;
	for (int i=1; i<=n; i++) dep[i]=-1;
	while (1) 
	{
		nw+=e[la[maa]].val;
		if ((nw<<1)>ma) 
		{
			x=maa,y=e[la[maa]].to; 
			dep[x]=ma-(nw-e[la[maa]].val);
			dep[y]=nw;
			break;
		}
		if ((nw<<1)==ma) 
		{
			x=y=e[la[maa]].to; 
			dep[x]=nw;
			break;
		}
		maa=e[la[maa]].to;
	}
	cnt=0;
	if (dep[x]<dep[y]) dfs(x,0); else dfs(y,0);
	for (int i=1; i<=Q; i++) printf("%d\n",ans[i]);
	return 0;
}