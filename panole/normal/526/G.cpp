#include<bits/stdc++.h>
using namespace std;

const int L=1,R=1000000000;
int sum[100010],cnt,m,n,rt[100010],f[100010],g[100010],x,y,z,ans,hd[100010],tot,fa[100010],q[100010],l,r,dis[100010],la[100010],c[100010],cn,Rt;
struct node{int ls,rs,cnt,val;}t[13000010];
struct edg{int to,next,val;}e[200010];
bool bo[100010];

void addedge(int x,int y,int z)
{
	e[++cnt]=(edg){y,hd[x],z},hd[x]=cnt;
	e[++cnt]=(edg){x,hd[y],z},hd[y]=cnt;
}

void add(int i,int I,int l,int r,int v)
{
	if (l==r) {t[i].val=t[I].val+v,t[i].cnt=t[I].cnt+1; return;}
	int mid=(l+r)>>1;
	if (v<=mid) t[i].rs=t[I].rs,add(t[i].ls=(++tot),t[I].ls,l,mid,v);
	else t[i].ls=t[I].ls,add(t[i].rs=(++tot),t[I].rs,mid+1,r,v);
	t[i].val=t[t[i].ls].val+t[t[i].rs].val;
	t[i].cnt=t[t[i].ls].cnt+t[t[i].rs].cnt;
}

void del(int i,int I,int l,int r,int v)
{
	if (l==r) {t[i].val=t[I].val-v,t[i].cnt=t[I].cnt-1; return;}
	int mid=(l+r)>>1;
	if (v<=mid) t[i].rs=t[I].rs,del(t[i].ls=(++tot),t[I].ls,l,mid,v);
	else t[i].ls=t[I].ls,del(t[i].rs=(++tot),t[I].rs,mid+1,r,v);
	t[i].val=t[t[i].ls].val+t[t[i].rs].val;
	t[i].cnt=t[t[i].ls].cnt+t[t[i].rs].cnt;
}

int query(int i,int l,int r,int v)
{
	if (l==r) return min(v,t[i].cnt)*l;
	int mid=(l+r)>>1,ans=0;
	if (t[t[i].rs].cnt>=v) return query(t[i].rs,mid+1,r,v);
	ans=t[t[i].rs].val,v-=t[t[i].rs].cnt;
	return ans+query(t[i].ls,l,mid,v);
}

void dfs(int x)
{
	int ma=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&!bo[e[i].to]) 
		{
			fa[e[i].to]=x,dfs(e[i].to);
			if (f[e[i].to]+e[i].val>ma) 
			{
				if (ma) Rt=rt[0],add(rt[0]=(++tot),Rt,L,R,ma);
				ma=f[e[i].to]+e[i].val;
			}
			else Rt=rt[0],add(rt[0]=(++tot),Rt,L,R,f[e[i].to]+e[i].val);
		}
	f[x]=ma;
}

void Dfs(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&!bo[e[i].to])
		{
			g[e[i].to]=g[x]+e[i].val;
			del(rt[e[i].to]=(++tot),rt[x],L,R,f[e[i].to]+e[i].val);
			if (f[e[i].to]) Rt=rt[e[i].to],add(rt[e[i].to]=(++tot),Rt,L,R,f[e[i].to]);
			Dfs(e[i].to);
		}
}

int main()
{
	scanf("%d%d",&n,&m),t[0].ls=t[0].rs=t[0].cnt=t[0].val=0;
	for (int i=1; i<n; i++) scanf("%d%d%d",&x,&y,&z),addedge(x,y,z);
	for (int i=1; i<=n; i++) dis[i]=-1;
	q[l=r=1]=1,dis[1]=0;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis[e[i].to]==-1) dis[q[++r]=e[i].to]=dis[x]+e[i].val;
	}
	l=1;
	for (int i=2; i<=r; i++) if (dis[q[i]]>dis[q[l]]) l=i;
	for (int i=1; i<=n; i++) dis[i]=-1;
	q[1]=q[l],l=r=1,dis[q[1]]=la[q[1]]=0;
	while (l<=r)
	{
		x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (dis[e[i].to]==-1) dis[q[++r]=e[i].to]=dis[x]+e[i].val,la[e[i].to]=x;
	}
	l=1;
	for (int i=2; i<=r; i++) if (dis[q[i]]>dis[q[l]]) l=i;
	l=q[l],c[cn=1]=l;
	while (la[l]) l=la[l],c[++cn]=l;
	sum[1]=0;
	for (int i=1; i<cn; i++)
	{
		bo[c[i]]=1;
		for (int j=hd[c[i]]; j; j=e[j].next)
			if (e[j].to==c[i+1]) {sum[i+1]=sum[i]+e[j].val; break;}
	}
	bo[c[cn]]=1,rt[0]=tot=0;
	for (int i=1; i<=cn; i++) 
	{
		dfs(c[i]);
		if (f[c[i]]) Rt=rt[0],add(rt[0]=(++tot),Rt,L,R,f[c[i]]);
	}
	for (int i=1; i<=cn; i++) rt[c[i]]=rt[0],g[c[i]]=max(sum[cn]-sum[i],sum[i]),f[c[i]]=sum[cn]-g[c[i]];
	for (int i=1; i<=cn; i++) 
	{
		if (f[c[i]]) Rt=rt[c[i]],add(rt[c[i]]=(++tot),Rt,L,R,f[c[i]]);
		Dfs(c[i]);
	}
	for (int i=1; i<=n; i++) if (f[i]) Rt=rt[i],del(rt[i]=(++tot),Rt,L,R,f[i]);
	for (int qaq=1; qaq<=m; qaq++)
	{
		scanf("%d%d",&x,&y);
		if (qaq>1) x=(x+ans-1)%n+1,y=(y+ans-1)%n+1;
		ans=f[x]+g[x],y--;
		if (y) ans+=query(rt[x],L,R,y<<1);
		printf("%d\n",ans);
	}
	return 0;
}