#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000ll;
long long nwv,nwf[250001];
int n,cnt,hd[250001],fa[250001],d[250001],siz[250001],x,y,c,rt,tot,TOT,V[250001],RT[250001][2],malen,tt[250001][2],ttn;
struct node{int to,next,la,c;}e[1500001];
struct spaly{int siz,ch[2],fa; long long val,s;}t[501001];
struct seg{int ls,rs; long long val;}T[12000001];

void upd(int x) 
{
	t[x].s=t[t[x].ch[0]].s+t[t[x].ch[1]].s+t[x].val;
	t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+1;
}

bool clc(int x) {return t[t[x].fa].ch[1]==x;}

void rotate(int x)
{
	int f=t[x].fa,g=t[f].fa,F=clc(x);
	if (g) t[g].ch[clc(f)]=x;
	t[x].fa=g,t[t[f].ch[F]=t[x].ch[F^1]].fa=f;
	t[t[x].ch[F^1]=f].fa=x,upd(f);
}

void splay(int x)
{
	for (int f=t[x].fa; f; rotate(x),f=t[x].fa)
		if (t[f].fa) rotate(clc(x)==clc(f)?f:x);
	upd(rt=x);
}

void find(int x,int k)
{
	if (t[t[x].ch[0]].siz>=k) {find(t[x].ch[0],k); return;}
	if (t[t[x].ch[0]].siz==k-1||!t[x].ch[1]) {splay(x); return;}
	find(t[x].ch[1],k-t[t[x].ch[0]].siz-1);
}

int gnode()
{
	t[++tot].siz=1;
	t[tot].ch[0]=t[tot].ch[1]=t[tot].fa=0;
	t[tot].val=t[tot].s=0;
	return tot;
}

void INS(int x,long long v)
{
	if (t[x].val>=v)
	{
		if (t[x].ch[0]) INS(t[x].ch[0],v);
		else t[x].ch[0]=gnode(),t[tot].fa=x,t[tot].val=t[tot].s=v,splay(tot);
	} else
	{
		if (t[x].ch[1]) INS(t[x].ch[1],v);
		else t[x].ch[1]=gnode(),t[tot].fa=x,t[tot].val=t[tot].s=v,splay(tot);
	}
}

void ins(long long x)
{
	if (!rt) rt=gnode(),t[1].val=t[1].s=x;
	else INS(rt,x);
}

void DEL(int x)
{
	splay(x); 
	if (!t[x].ch[1]) t[t[x].ch[0]].fa=0,rt=t[x].ch[0]; else
	{
		t[t[x].ch[0]].fa=t[t[x].ch[1]].fa=0;
		int nw=t[x].ch[1];
		while (t[nw].ch[0]) nw=t[nw].ch[0];
		splay(nw),t[nw].ch[0]=t[x].ch[0],t[t[nw].ch[0]].fa=nw,upd(nw);
	}
}

void del(int x,long long v)
{
	if (t[x].val==v) {DEL(x); return;}
	if (v<t[x].val) del(t[x].ch[0],v);
	else del(t[x].ch[1],v);
}

void del(long long x) {del(rt,x);}

void addedge(int x,int y,int c)
{
	e[++cnt]=(node){y,hd[x],0,c},e[hd[x]].la=cnt,hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0,c},e[hd[y]].la=cnt,hd[y]=cnt;
}

void deledge(int x,int i)
{
	if (i==hd[x]) hd[x]=e[i].next,e[hd[x]].la=0;
	else e[e[i].la].next=e[i].next,e[e[i].next].la=e[i].la;
}

void change(int i,int I,int l,int r,int x,long long v)
{
	if (l==r) {T[i].val=v; return;}
	int mid=(l+r)>>1;
	if (x<=mid) T[i].rs=T[I].rs,change(T[i].ls=(++TOT),T[I].ls,l,mid,x,v);
	else T[i].ls=T[I].ls,change(T[i].rs=(++TOT),T[I].rs,mid+1,r,x,v);
}

void add(int i,int I,int l,int r,int qr)
{
	if (l==r) {T[i].val=T[I].val+nwf[l]; return;}
	int mid=(l+r)>>1;
	if (qr<=mid) T[i].rs=T[I].rs,add(T[i].ls=(++TOT),T[I].ls,l,mid,qr);
	else add(T[i].ls=(++TOT),T[I].ls,l,mid,mid),add(T[i].rs=(++TOT),T[I].rs,mid+1,r,qr); 
}

long long getf(int i,int l,int r,int x)
{
	if (x>r) return 0;
	if (l==r) return T[i].val;
	int mid=(l+r)>>1;
	if (x<=mid) return T[i].ls?getf(T[i].ls,l,mid,x):0;
	else return T[i].rs?getf(T[i].rs,mid+1,r,x):0;
}

void add(int x,long long v)
{
	if (x>malen) malen=x;
	nwf[x]+=v;
}

void dfs(int x)
{
	siz[x]=1; int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) 
		{
			V[e[i].to]=e[i].c,fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
			if (siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
		}
	if (!ma)
	{
		change(RT[x][0]=(++TOT),0,0,n-1,0,0);
		change(RT[x][1]=(++TOT),0,0,n-1,0,V[x]);
		return;
	}
	for (int j=0; j<=(x==1?0:1); j++)
	{
		RT[x][j]=RT[maa][1],malen=-1;
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=maa)
				for (int k=0; ; k++)
				{
					nwv=getf(RT[e[i].to][1],0,n-1,k);
					if (!nwv) break; add(k,nwv);
				}
		tot=rt=0;
		if (j==1) add(0,V[x]+getf(RT[x][0],0,n-1,0)-getf(RT[x][1],0,n-1,0));
		ttn=0;
		for (int k=0; k<d[x]-(x!=1); k++)
		{
			for (int i=hd[x]; i; i=e[i].next)
				if (e[i].to!=fa[x])
				{
					nwv=getf(RT[e[i].to][1],0,n-1,k+j);
					if (k) del(getf(RT[e[i].to][0],0,n-1,k+j-1)+e[i].c-getf(RT[e[i].to][1],0,n-1,k+j-1));
					ins(getf(RT[e[i].to][0],0,n-1,k+j)+e[i].c-nwv);
					if (!nwv) {tt[++ttn][0]=e[i].to,tt[ttn][1]=e[i].c,deledge(x,i); continue;}
				}
			if (!rt) break;
			find(rt,d[x]-k-(x!=1));
			add(k+j,t[t[rt].ch[0]].s+t[rt].val);
		}
		for (int k=1; k<=ttn; k++) e[++cnt]=(node){tt[k][0],hd[x],0,tt[k][1]},e[hd[x]].la=cnt,hd[x]=cnt;
		if (j)
		{
			for (int k=0; k<=malen; k++) 
			{
				nwv=getf(RT[x][0],0,n-1,k);
				nwf[k]=min(nwf[k],nwv-getf(RT[x][1],0,n-1,k)+V[x]);
			}
		}
		int NW=RT[x][j];
		if (malen!=-1) add(RT[x][j]=(++TOT),NW,0,n-1,malen);
		for (int k=0; k<=malen; k++) nwf[k]=0;
	}
}

int main()
{
	scanf("%d",&n),TOT=0;
	for (int i=1; i<n; i++) scanf("%d%d%d",&x,&y,&c),addedge(x,y,c),d[x]++,d[y]++;
	V[1]=0,memset(fa,0,sizeof(fa)),TOT=0,dfs(1);
	for (int i=0; i<n; i++) printf("%I64d ",getf(RT[1][0],0,n-1,i));
	return puts(""),0;
}