#include<bits/stdc++.h> 
using namespace std;

const int L=1,R=1000000000;

struct spaly
{
	int tot,rt;
	vector<int> fa,ch[2],siz,val,num;
	void init() 
	{
		tot=rt=0; 
		fa.clear(),ch[0].clear(),ch[1].clear(),siz.clear(),val.clear(),num.clear();
	}
	void upd(int x) {siz[x]=siz[ch[0][x]]+siz[ch[1][x]]+num[x];}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f];
		bool F=(ch[1][f]==x);
		if (g) ch[ch[1][g]==f][g]=x; else rt=x;
		fa[ch[F][f]=ch[F^1][x]]=f;
		fa[x]=g,fa[ch[F^1][x]=f]=x;
		upd(f);
	}
	void splay(int x)
	{
		while (x!=rt)
		{
			int f=fa[x];
			if (f!=rt) rotate((ch[1][fa[f]]==f)==(ch[1][f]==x)?f:x);
			rotate(x);
		}
		upd(x);
	}
	void ins(int nw,int x)
	{
		if (val[nw]==x) num[nw]++,splay(nw); else
		if (val[nw]<x) 
		{
			if (ch[1][nw]) {ins(ch[1][nw],x); return;}
			ch[1][nw]=(++tot),fa.push_back(nw),ch[0].push_back(0),ch[1].push_back(0),siz.push_back(1);
			val.push_back(x),num.push_back(1),splay(tot); return;
		}
		else 
		{
			if (ch[0][nw]) {ins(ch[0][nw],x); return;}
			ch[0][nw]=(++tot),fa.push_back(nw),ch[0].push_back(0),ch[1].push_back(0),siz.push_back(1);
			val.push_back(x),num.push_back(1),splay(tot); return;
		}
	}
	int find(int nw,int x)
	{
		int ans=0;
		if (val[nw]==x) 
		{
			ans=siz[ch[0][nw]]+num[nw];
			return splay(nw),ans;
		}
		if (val[nw]<x) 
		{
			ans=siz[ch[0][nw]]+num[nw];
			if (ch[1][nw]) return ans+find(ch[1][nw],x);
			else return splay(nw),ans;
		}
		if (ch[0][nw]) return find(ch[0][nw],x);
		else return splay(nw),0;
	}
	void ins(int x) 
	{
		if (!rt)
		{
			rt=(++tot);
			fa.push_back(0),ch[0].push_back(0),ch[1].push_back(0),siz.push_back(0);
			val.push_back(0),num.push_back(0);
			fa.push_back(0),ch[0].push_back(0),ch[1].push_back(0),siz.push_back(1);
			val.push_back(x),num.push_back(1); return;
		}
		ins(rt,x);
	}
	int find(int x)
	{
		if (!rt) return 0;
		return find(rt,x);
	}
};

pair<int,pair<int,int> > A[300001];
pair<int,int> B[100001],Pre[100001];
int n,m,p[100001],s[100001],b[100001],pre[100001],inc[100001],tot,ans[100001],val[300001],cnt;
struct node{int l,r; spaly A;}t[1200001];

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].A.init();
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void add(int i,int l,int r,int v)
{
	if (t[i].l==l&&t[i].r==r) {t[i].A.ins(v); return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
}

int query(int i,int x,int v)
{
	int ans=t[i].A.find(v);
	if (t[i].l==t[i].r) return ans;
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) return ans+query(i<<1,x,v);
	else return ans+query(i<<1|1,x,v);
}

void getans(bool bo)
{
	build(1,1,cnt);
	for (int i=1; i<=n; i++) B[i]=make_pair(b[i],i);
	for (int i=1; i<=m; i++) Pre[i]=make_pair(pre[i],i);
	sort(B+1,B+1+n),sort(Pre+1,Pre+1+m);
	int nwB=1,nwPre=1;
	while (nwB<=n&&nwPre<=m)
	{
		if (B[nwB].first+bo<=Pre[nwPre].first) add(1,p[B[nwB].second],s[B[nwB].second],val[p[B[nwB].second]]-B[nwB].first),nwB++;
		else ans[Pre[nwPre].second]+=query(1,inc[Pre[nwPre].second],val[inc[Pre[nwPre].second]]-Pre[nwPre].first),nwPre++;
	}
	for (int i=nwPre; i<=m; i++) ans[Pre[i].second]+=query(1,inc[Pre[i].second],val[inc[Pre[i].second]]-Pre[i].first);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",&p[i]),A[i]=make_pair(p[i],make_pair(0,i));
	for (int i=1; i<=n; i++) scanf("%d",&s[i]),A[i+n]=make_pair(s[i],make_pair(1,i));
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	for (int i=1; i<=m; i++) scanf("%d",&inc[i]),A[i+n+n]=make_pair(inc[i],make_pair(2,i));
	for (int i=1; i<=m; i++) scanf("%d",&pre[i]);
	sort(A+1,A+1+n+n+m),cnt=0,A[0].first=-1;
	for (int i=1; i<=n+n+m; i++)
	{
		if (A[i].first!=A[i-1].first) val[++cnt]=A[i].first;
		if (A[i].second.first==0) p[A[i].second.second]=cnt;
		if (A[i].second.first==1) s[A[i].second.second]=cnt;
		if (A[i].second.first==2) inc[A[i].second.second]=cnt;
	}
	getans(0);
	for (int i=1; i<=n; i++) b[i]=1000000001-b[i];
	for (int i=1; i<=m; i++) pre[i]=1000000001-pre[i];
	getans(1);
	for (int i=1; i<=m; i++) printf("%d ",ans[i]);
	return puts(""),0;
}