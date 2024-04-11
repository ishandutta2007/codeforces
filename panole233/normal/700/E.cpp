#include<bits/stdc++.h>
using namespace std;

int n,cnt,la,ma[400010],ch[400010][26],fa[400010],f[400010],po[400010],T[400010],Tn,ans,hd[400010],Cnt,tp[400010],dfn[400010],siz[400010],p[400010];
struct node{int to,next;}e[400010];
struct segt{int l,r,val,laz,ma;}t[1600100];
bool bo[400010];
char s[200010];

void ins(int c,int nw)
{
	int np=(++cnt),p=la; po[ma[la=np]=nw]=cnt;
	while (p&&!ch[p][c]) ch[p][c]=np,p=fa[p];
	if (!p) fa[np]=1; else
	{
		int q=ch[p][c];
		if (ma[q]==ma[p]+1) fa[np]=q; else
		{
			int nq=(++cnt); ma[nq]=ma[p]+1;
			for (int i=0; i<26; i++) ch[nq][i]=ch[q][i];
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			while (ch[p][c]==q) ch[p][c]=nq,p=fa[p];
		}
	}
}

void addedge(int x,int y)
{
	e[++Cnt].next=hd[x];
	hd[x]=Cnt;
	e[Cnt].to=y;
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++Cnt),p[Cnt]=x;
	if (!hd[x]) return; 
	int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	tp[maa]=tp[x],Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].val=-1000000,t[i].laz=0;
	if (l==r) {t[i].ma=ma[p[l]]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].ma=t[i<<1].ma;
}

void pushdown(int i)
{
	if (!t[i].laz) return;
	t[i<<1].laz=t[i].laz;
	t[i<<1].val=t[i].laz-t[i<<1].ma;
	t[i<<1|1].laz=t[i].laz;
	t[i<<1|1].val=t[i].laz-t[i<<1|1].ma;
	t[i].laz=0;
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].laz=v,t[i].val=v-t[i].ma; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
	t[i].val=t[i<<1].val;
}

int query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].val;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return query(i<<1,l,mid);
}

int find(int i,int l,int r,int v)
{
	if (t[i].l==t[i].r) return t[i].l;
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return find(i<<1,l,r,v);
	if (l>mid) return find(i<<1|1,l,r,v);
	if (t[i<<1|1].val<v) return find(i<<1,l,mid,v);
	return find(i<<1|1,mid+1,r,v);
}

int Find(int x,int v)
{
	while (x) 
	{
		if (query(1,dfn[tp[x]],dfn[x])>=v) return find(1,dfn[tp[x]],dfn[x],v);
		x=fa[tp[x]];
	}
}

void Change(int x,int v)
{
	while (x) change(1,dfn[tp[x]],dfn[x],v),x=fa[tp[x]];
}

int main()
{
	scanf("%d",&n),scanf("%s",s),cnt=la=1,fa[1]=ma[1]=0;
	for (int i=n-1; i>=0; i--) ins(s[i]-'a',n-i);
	memset(bo,0,sizeof(bo)),bo[1]=1;
	memset(f,0,sizeof(f)),ans=0;
	memset(hd,0,sizeof(hd)),Cnt=0;
	for (int i=2; i<=cnt; i++) addedge(fa[i],i);
	tp[1]=1,Cnt=0,dfs(1),Dfs(1),build(1,1,Cnt),change(1,1,1,1000000);
	for (int i=1,x; i<=n; i++)
	{
		x=po[i],Tn=0;
		while (!bo[x]) T[++Tn]=x,x=fa[x];
		for (int j=1; j<=Tn; j++) bo[T[j]]=1,f[T[j]]=f[p[Find(x,i-ma[T[j]])]]+1;
		Change(po[i],i);
	}
	for (int i=1; i<=cnt; i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}