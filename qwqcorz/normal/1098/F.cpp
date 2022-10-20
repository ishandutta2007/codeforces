#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int len[N];
vector<int>e[N];
namespace sptree
{
	int dfn[N],ndfn[N],fa[N],top[N],deep[N],siz[N],son[N],cntdfn=0;
	void dfs0(int now,int father)
	{
		fa[now]=father;
		deep[now]=deep[father]+1;
		siz[now]=1,son[now]=0;
		for (int to:e[now])
		{
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int Top)
	{
		top[now]=Top;
		ndfn[dfn[now]=++cntdfn]=now;
		for (int to:e[now])
		{
			if (to==son[now]) continue;
			dfs1(to,to);
		}
		if (son[now]) dfs1(son[now],Top);
	}
	void build()
	{
		dfs0(1,0);
		dfs1(1,1);
	}
}
using namespace sptree;
char s[N];
namespace SAM
{
	struct node
	{
		bool isclone;
		int len,link;
		int to[26];
	}s[N];
	int p[N],np[N],siz=1,End=1;
	void extend(int c)
	{
		int now=++siz;
		s[now].len=s[End].len+1;
		int p=End; End=now;
		for (;p&&!s[p].to[c];p=s[p].link) s[p].to[c]=now;
		if (!p) return s[now].link=1,void();
		int q=s[p].to[c];
		if (s[p].len+1==s[q].len) s[now].link=q;
		else
		{
			s[++siz]=s[q];
			s[siz].len=s[p].len+1;
			s[siz].isclone=1;
			s[now].link=s[q].link=siz;
			for (;p&&s[p].to[c]==q;p=s[p].link) s[p].to[c]=siz;
		}
	}
	void build(char *a)
	{
		int n=strlen(a+1);
		for (int i=n;i>=1;i--) extend(a[i]-'a'),np[p[i]=End]=i;
		for (int i=2;i<=siz;i++) e[s[i].link].push_back(i);
		for (int i=2;i<=siz;i++) len[i]=s[i].len;
	}
}
using SAM::p;
using SAM::np;
struct Query
{
	int l,r;
}q[N];
ll ans[N];
vector<int>q1[N];
namespace Case1
{
	struct bit
	{
		int tot[N],n;ll sum[N];
		inline void clear(int x){for (;x<=n;x+=x&-x) tot[x]=sum[x]=0;}
		inline void add(int x,int y){for (;x<=n;x+=x&-x) tot[x]++,sum[x]+=y;}
		inline int querytot(int x)
		{
			int ret=0;
			for (;x;x&=x-1) ret+=tot[x];
			return ret;
		}
		inline int querytot(int l,int r){return querytot(r)-querytot(l-1);}
		inline ll querysum(int x)
		{
			ll ret=0;
			for (;x;x&=x-1) ret+=sum[x];
			return ret;
		}
		inline ll querysum(int l,int r){return querysum(r)-querysum(l-1);}
	}t;
	inline void insert(int x){t.add(x,x);}
	inline void erase(int x){t.clear(x);}
	inline void add(int l,int r)
	{
		for (int i=l;i<r;i++)
		if (np[ndfn[i]]) insert(np[ndfn[i]]);
	}
	inline void clear(int now)
	{
		for (int i=dfn[now];i<dfn[now]+siz[now];i++)
		if (np[ndfn[i]]) erase(np[ndfn[i]]);
	}
	void dfs(int now)
	{
		if (son[now])
		{
			for (int to:e[now])
			{
				if (to==son[now]) continue;
				dfs(to);
				clear(to);
			}
			dfs(son[now]);
			for (int i=dfn[now];i<dfn[now]+siz[now]-siz[son[now]];i++)
			for (int id:q1[ndfn[i]])
			{
				int l=q[id].l,r=q[id].r,lca=len[now];
				int m=max(r-lca+1,l);
				ans[id]+=1LL*t.querytot(m,r)*(r+1)-t.querysum(m,r);
				ans[id]+=1LL*t.querytot(l,m-1)*lca;
			}
		}
		add(dfn[now],dfn[now]+siz[now]-siz[son[now]]);
	}
}
namespace Case2
{
	struct bit
	{
		int tot[N],n;ll sum1[N],sum2[N];
		inline void clear(int x){x++;for (;x<=n;x+=x&-x) tot[x]=sum1[x]=sum2[x]=0;}
		inline void add(int x,int y,int z,int f){x++;for (;x<=n;x+=x&-x) tot[x]+=f,sum1[x]+=y*f,sum2[x]+=z*f;}
		inline int querytot(int x)
		{
			x++;
			int ret=0;
			for (;x;x&=x-1) ret+=tot[x];
			return ret;
		}
		inline int querytot(int l,int r){return querytot(r)-querytot(l-1);}
		inline ll querysum1(int x)
		{
			x++;
			ll ret=0;
			for (;x;x&=x-1) ret+=sum1[x];
			return ret;
		}
		inline ll querysum1(int l,int r){return querysum1(r)-querysum1(l-1);}
		inline ll querysum2(int x)
		{
			x++;
			ll ret=0;
			for (;x;x&=x-1) ret+=sum2[x];
			return ret;
		}
		inline ll querysum2(int l,int r){return querysum2(r)-querysum2(l-1);}
	}t;
	struct data
	{
		int id,lca,deep,f;
	};
	vector<data>a[N];
	struct data2
	{
		int id,a,b,c,f;
	};
	vector<data2>b[N];
	inline void insert(const data &a){t.add(a.lca+a.id-1,a.lca,a.id,a.f);}
	inline void erase(const data &a){t.clear(a.lca+a.id-1);}
	data A[N]; data2 B[N];
	void cdq(vector<data>&a,vector<data2>&b,int l,int r,int ql,int qr)
	{
		if (ql>qr)
		{
			sort(a.begin()+l,a.begin()+r+1,[&](const data &x,const data &y){
				return x.id<y.id;
			});
			return;
		}
		int mid=(l+r)/2,qm=ql;
		while (qm<=qr&&b[qm].a<a[mid].deep) qm++;
		if (l<r)
		{
			cdq(a,b,l,mid,ql,qm-1);
			cdq(a,b,mid+1,r,qm,qr);
		}
		if (l==r)
		{
			sort(b.begin()+ql,b.begin()+qm,[&](const data2 &x,const data2 &y){
				return x.b<y.b;
			});
			sort(b.begin()+qm,b.begin()+qr+1,[&](const data2 &x,const data2 &y){
				return x.b<y.b;
			});
		}
		for (int i=qm,j=l;i<=qr;i++)
		{
			while (j<=mid&&a[j].id<=b[i].b) insert(a[j++]);
			ans[b[i].id]+=1LL*t.querysum1(b[i].c)*b[i].f;
			ans[b[i].id]+=(1LL*t.querytot(b[i].c+1,t.n)*(b[i].c+1)-t.querysum2(b[i].c+1,t.n))*b[i].f;
		}
		for (int i=l;i<=mid;i++)
		if (a[i].id<=b[qr].b) erase(a[i]);
		
		int i,j,k;
		for (k=i=l,j=mid+1;i<=mid&&j<=r;)
		if (a[i].id<a[j].id) A[k++]=a[i++];
						else A[k++]=a[j++];
		while (i<=mid) A[k++]=a[i++];
		while (j<=r) A[k++]=a[j++];
		for (i=l;i<=r;i++) a[i]=A[i];
		
		for (k=i=ql,j=qm;i<qm&&j<=qr;)
		if (b[i].b<b[j].b) B[k++]=b[i++];
					  else B[k++]=b[j++];
		while (i<qm) B[k++]=b[i++];
		while (j<=qr) B[k++]=b[j++];
		for (i=ql;i<=qr;i++) b[i]=B[i];
	}
	void solve(int n,int m,int Q)
	{
		t.n=n*2;
		for (int i=1;i<=n;i++)
		{
			int now=p[i];
			a[top[now]].push_back((data){i,len[now],deep[now],1});
			while (top[now]>1)
			{
				a[top[now]].push_back((data){i,len[fa[top[now]]],deep[top[now]],-1});
				a[top[fa[top[now]]]].push_back((data){i,len[fa[top[now]]],deep[fa[top[now]]],1});
				now=fa[top[now]];
			}
		}
		for (int i=1;i<=Q;i++)
		{
			int now=p[q[i].l],l=q[i].l,r=q[i].r;
			while (now)
			{
				b[top[now]].push_back((data2){i,deep[now],r,r,1});
				b[top[now]].push_back((data2){i,deep[now],l-1,r,-1});
				now=fa[top[now]];
			}
		}
		for (int i=1;i<=m;i++)
		if (i==top[i]&&!a[i].empty()&&!b[i].empty())
		{
			sort(a[i].begin(),a[i].end(),[&](const data &x,const data &y){
				return x.deep<y.deep;
			});
			sort(b[i].begin(),b[i].end(),[&](const data2 &x,const data2 &y){
				return x.a<y.a;
			});
			cdq(a[i],b[i],0,(int)a[i].size()-1,0,(int)b[i].size()-1);
		}
	}
}

signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	SAM::build(s);
	sptree::build();
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		q[i].l=read();
		q[i].r=read();
		q1[p[q[i].l]].push_back(i);
	}
	int m=Case1::t.n=SAM::siz;
	Case1::dfs(1);
	Case2::solve(n,m,Q);
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}