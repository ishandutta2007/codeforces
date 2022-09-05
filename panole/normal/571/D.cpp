#include<bits/stdc++.h>
using namespace std;

vector<int> v[500010];
int n,cnt,hd[1000010],dfn[1000010],L[1000010],R[1000010],Q,p[1000010],tot,qp[1010],nqa,nw,rt[500010];
struct edg{int to,next;}e[2000010];
struct node{int l,r,val;}t[2000010];
struct que{int ord,x,y;}q[500010];
struct lin{int ord,t,x;}qa[1000010];
long long val[500010],laz[500010],ans[500010];
char s[5];

int ask(int x) {return p[x]==x?x:p[x]=ask(p[x]);}
bool cmp(const lin &a,const lin &b) {return a.t<b.t;}
void addedge(int x,int y) {e[++cnt]=(edg){y,hd[x]},hd[x]=cnt;}

void dfs(int x)
{
	L[x]=cnt+1;
	if (!hd[x]) {dfn[x]=(++cnt),R[x]=cnt; return;}
	for (int i=hd[x]; i; i=e[i].next) dfs(e[i].to);
	R[x]=cnt;
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].val=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);	
}

void change(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].val=v; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r,v); else
	if (l>mid) change(i<<1|1,l,r,v); else
	change(i<<1,l,mid,v),change(i<<1|1,mid+1,r,v);
}

int query(int i,int x)
{
	if (t[i].l==t[i].r) return t[i].val;
	int mid=(t[i].l+t[i].r)>>1;
	return max(query(i<<1|(x>mid),x),t[i].val);
}

int main()
{
	scanf("%d%d",&n,&Q),tot=n;
	qp['U']=0,qp['M']=1,qp['A']=2,qp['Z']=3,qp['Q']=4;
	for (int i=1; i<=2*n; i++) p[i]=i;
	for (int i=1; i<=Q; i++)
	{
		scanf("%s",s),q[i].ord=qp[s[0]];
		if (q[i].ord>1) scanf("%d",&q[i].x); else
		if (q[i].ord==0) scanf("%d%d",&q[i].x,&q[i].y); else
		scanf("%d%d",&q[i].x,&q[i].y),addedge(++tot,ask(q[i].x)),addedge(tot,ask(q[i].y)),p[p[q[i].x]]=p[p[q[i].y]]=tot;
	}
	cnt=0;
	for (int i=1; i<=n; i++) if (!L[ask(i)]) dfs(p[i]);
	build(1,1,n),cnt=n,nqa=0;
	for (int i=1; i<=n; i++) p[i]=i;
	for (int i=1; i<=Q; i++)
		if (q[i].ord==1) p[q[i].x]=p[q[i].y]=(++cnt); else
		if (q[i].ord==3) change(1,L[p[q[i].x]],R[p[q[i].x]],i); else
		if (q[i].ord==4) qa[++nqa]=(lin){-i,query(1,dfn[q[i].x]),q[i].x},qa[++nqa]=(lin){i,i,q[i].x};
	sort(qa+1,qa+1+nqa,cmp),nw=1;
	for (int i=1; i<=n; i++) p[i]=rt[i]=i,v[i].push_back(i);
	for (int i=1; i<=Q; i++)
	{
		while (nw<=nqa&&qa[nw].t<i) 
		{
			if (qa[nw].ord<0) ans[-qa[nw].ord]-=(val[qa[nw].x]+laz[ask(qa[nw].x)]);
			else ans[qa[nw].ord]+=(val[qa[nw].x]+laz[ask(qa[nw].x)]);
			nw++;
		}
		if (q[i].ord==0)
		{
			p[q[i].y]=q[i].x;
			if (v[rt[q[i].x]].size()<v[rt[q[i].y]].size()) 
			{
				for (int j=0,sz=v[rt[q[i].x]].size(); j<sz; j++)
					v[rt[q[i].y]].push_back(v[rt[q[i].x]][j]),val[v[rt[q[i].x]][j]]+=laz[q[i].x]-laz[q[i].y];
				laz[q[i].x]=laz[q[i].y],rt[q[i].x]=rt[q[i].y];
			} else
			{
				for (int j=0,sz=v[rt[q[i].y]].size(); j<sz; j++)
					v[rt[q[i].x]].push_back(v[rt[q[i].y]][j]),val[v[rt[q[i].y]][j]]+=laz[q[i].y]-laz[q[i].x];
			}
		} else
		if (q[i].ord==2) laz[q[i].x]+=v[rt[q[i].x]].size();
	}
	while (nw<=nqa)
	{
		if (qa[nw].ord<0) ans[-qa[nw].ord]-=(val[qa[nw].x]+laz[ask(qa[nw].x)]);
		else ans[qa[nw].ord]+=(val[qa[nw].x]+laz[ask(qa[nw].x)]);
		nw++;
	}
	for (int i=1; i<=Q; i++)
		if (q[i].ord==4) printf("%I64d\n",ans[i]);
	return 0;
}