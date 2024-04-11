#include<cstdio>
#include<cstring>

int n,m,c,q,hd[50001],cnt,dfn[50001],rt[50001],tot,x,col[50001],val[50001],tp[50001],siz[50001],y,ord,fa[50001];
long double nn,xx;
double yy;

struct node
{
	int to,next;
}e[50001];

struct node2
{
	int ls,rs,laz;
	long long v,val;
}t[10000001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

void Dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next) Dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void dfs(int x)
{
	dfn[x]=(++cnt); int mx=0,ma;
	for (int i=hd[x]; i; i=e[i].next)
		if (siz[e[i].to]>mx) mx=siz[e[i].to],ma=e[i].to;
	if (!mx) return;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to==ma) tp[e[i].to]=tp[x],dfs(e[i].to);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=ma) tp[e[i].to]=e[i].to,dfs(e[i].to);
}

void pushdown(int i,int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1,i1=t[i].ls,i2=t[i].rs;
	if (!i1) i1=t[i].ls=(++tot),t[i1].ls=t[i1].rs=t[i1].laz=0,t[i1].v=-(1ll*c*(mid-l+1)),t[i1].val=1ll*c*c*(mid-l+1);
	if (!i2) i2=t[i].rs=(++tot),t[i2].ls=t[i2].rs=t[i2].laz=0,t[i2].v=-(1ll*c*(r-mid)),t[i2].val=1ll*c*c*(r-mid);
	if (t[i].laz==0) return;
	t[i1].laz+=t[i].laz; t[i2].laz+=t[i].laz;
	t[i1].val+=2ll*t[i1].v*t[i].laz+1ll*t[i].laz*t[i].laz*(mid-l+1);
	t[i2].val+=2ll*t[i2].v*t[i].laz+1ll*t[i].laz*t[i].laz*(r-mid);
	t[i1].v+=1ll*t[i].laz*(mid-l+1); t[i2].v+=1ll*t[i].laz*(r-mid);
	t[i].laz=0;
}

void add(int i,int l,int r,int ql,int qr,int val)
{
	pushdown(i,l,r);
	if (l==ql&&r==qr) {t[i].laz+=val; t[i].val+=2ll*t[i].v*val+1ll*val*val*(r-l+1); t[i].v+=1ll*val*(r-l+1); return;}
	int mid=(l+r)>>1;
	if (qr<=mid) add(t[i].ls,l,mid,ql,qr,val); else
	if (ql>mid) add(t[i].rs,mid+1,r,ql,qr,val); else
	add(t[i].ls,l,mid,ql,mid,val),add(t[i].rs,mid+1,r,mid+1,qr,val);
	t[i].val=t[t[i].ls].val+t[t[i].rs].val;
	t[i].v=t[t[i].ls].v+t[t[i].rs].v;
}

void Add(int x,int c,int val)
{
	while (tp[x]!=1) add(rt[c],1,n,dfn[tp[x]],dfn[x],val),x=fa[tp[x]];
	add(rt[c],1,n,dfn[1],dfn[x],val);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&q,&c);
	for (int i=1; i<=n; i++) scanf("%d",&col[i]);
	memset(hd,0,sizeof(hd)); cnt=tot=0;
	for (int i=2; i<=n; i++) scanf("%d",&fa[i]),addedge(fa[i],i);
	for (int i=1; i<=m; i++) scanf("%d",&val[i]);
	for (int i=1; i<=m; i++) rt[i]=(++tot),t[tot].ls=t[tot].rs=0,t[tot].v=-(1ll*c*n),t[tot].val=1ll*c*c*n;
	cnt=0; Dfs(1); tp[1]=1; dfs(1);
	for (int i=1; i<=n; i++) Add(i,col[i],val[col[i]]);
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==1) scanf("%d%d",&x,&y),Add(x,col[x],-val[col[x]]),col[x]=y,Add(x,y,val[y]);
		else scanf("%d",&x),xx=t[rt[x]].val,nn=n,nn=xx/nn,yy=nn,printf("%.10lf\n",yy);
	}
	return 0;
}