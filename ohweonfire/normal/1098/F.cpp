// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=400111;

int fa[maxn],val[maxn],tot;

namespace sam
{
	int go[maxn][26];
	int append(int p,int c)
	{
		int np=++tot;val[np]=val[p]+1;
		while(p&&!go[p][c])
		{
			go[p][c]=np;
			p=fa[p];
		}
		if(!p)fa[np]=1;
		else
		{
			int q=go[p][c];
			if(val[q]==val[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;val[nq]=val[p]+1;
				memcpy(go[nq],go[q],sizeof(go[q]));
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				while(p&&go[p][c]==q)
				{
					go[p][c]=nq;
					p=fa[p];
				}
			}
		}
		return np;
	}
	
	void construct(char*s,int n,int*pos)
	{
		tot=1;
		pos[n+1]=1;
		for(int i=n;i>=1;i--)
			pos[i]=append(pos[i+1],s[i]-'a');
	}
};

vector<int> g[maxn],qs[maxn];
int sz[maxn],son[maxn],top[maxn];

void dfs1(int x)
{
	sz[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
	{
		dfs1(g[x][i]);
		sz[x]+=sz[g[x][i]];
		if(sz[son[x]]<sz[g[x][i]])son[x]=g[x][i];
	}
	if(x==1)son[x]=0;
}
void dfs2(int x,int tp)
{
	top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=son[x])
		dfs2(g[x][i],g[x][i]);
}

struct q_t
{
	int l,r,v,id;
	q_t(int k1,int k2,int k3,int k4){l=k1;r=k2;v=k3;id=k4;}
};
vector<q_t> q_rec[maxn],q_tri[maxn];

int pos[200111];
void addquery(int l,int r,int id)
{
	int cur=pos[l],len=r-l+1;
	while(cur)
	{
		int tp=val[fa[top[cur]]];
		if(tp<len)
		{
			q_rec[top[cur]].pb(q_t(l,r-min(val[cur],len),min(val[cur],len)-tp,id));
			q_tri[top[cur]].pb(q_t(r-min(val[cur],len)+1,r-tp,0,id));
		}
		cur=fa[top[cur]];
	}
}

struct BIT
{
	LL bit[maxn];
	BIT(){memset(bit,0,sizeof(bit));}
	void add(int x,int v)
	{
		for(;x<maxn;x+=x&-x)
			bit[x]+=v;
	}
	LL query(int x)
	{
		LL ret=0;
		for(;x;x-=x&-x)ret+=bit[x];
		return ret;
	}
};

LL ans[200111];

int have[maxn];
pii vs[maxn];

void addall(int x,int ban,int t)
{
	if(have[x])vs[++tot]=mp(have[x],t);
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=ban)
		addall(g[x][i],ban,t);
}

BIT in,out_cnt,out_sum;

void go(int tp)
{
	tot=0;
	int cur=tp;
	for(int i=1;cur;i++)
	{
		addall(cur,son[cur],val[cur]-val[fa[tp]]);
		cur=son[cur];
	}
	
	vector<pii> qv;
	for(int i=1;i<=tot;i++)qv.pb(mp(vs[i].ss,-i));
	for(int i=0;i<(int)q_rec[tp].size();i++)
	{
		qv.pb(mp(q_rec[tp][i].v,i));
//		printf("q rec %d %d %d\n",q_rec[tp][i].l,q_rec[tp][i].r,q_rec[tp][i].v);
	}
	
	sort(qv.begin(),qv.end());
	for(int i=1;i<=tot;i++)out_cnt.add(vs[i].ff,1);
	for(int i=0;i<(int)qv.size();i++)
	{
		int id=qv[i].ss;
		if(id<0)
		{
			id=-id;
			out_cnt.add(vs[id].ff,-1);
			in.add(vs[id].ff,vs[id].ss);
		}
		else
		{
			q_t&cur=q_rec[tp][id];
			ans[cur.id]+=in.query(cur.r)-in.query(cur.l-1)+(out_cnt.query(cur.r)-out_cnt.query(cur.l-1))*cur.v;
		}
	}
	for(int i=1;i<=tot;i++)in.add(vs[i].ff,-vs[i].ss);
	
	qv.clear();
	for(int i=1;i<=tot;i++)qv.pb(mp(vs[i].ff+vs[i].ss,-i));
	for(int i=0;i<(int)q_tri[tp].size();i++)
	{
		qv.pb(mp(q_tri[tp][i].r+1,i));
//		printf("q tri %d %d\n",q_tri[tp][i].l,q_tri[tp][i].r);
	}
	
	sort(qv.begin(),qv.end());
	for(int i=1;i<=tot;i++)
	{
		out_cnt.add(vs[i].ff,1);
		out_sum.add(vs[i].ff,vs[i].ff);
	}
	
	for(int i=0;i<(int)qv.size();i++)
	{
		int id=qv[i].ss;
		if(id<0)
		{
			id=-id;
			out_cnt.add(vs[id].ff,-1);
			out_sum.add(vs[id].ff,-vs[id].ff);
			in.add(vs[id].ff,vs[id].ss);
		}
		else
		{
			q_t&cur=q_tri[tp][id];
			ans[cur.id]+=in.query(cur.r)-in.query(cur.l-1)+(out_cnt.query(cur.r)-out_cnt.query(cur.l-1))*(cur.r+1)-(out_sum.query(cur.r)-out_sum.query(cur.l-1));
		}
	}
	for(int i=1;i<=tot;i++)in.add(vs[i].ff,-vs[i].ss);
//	printf("%lld\n\n",ans[1]);
}

void dfs(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
		dfs(g[x][i]);
	if(top[x]==x&&x>1)go(x);
}

char s[200111];
int n,q,ql[200111],qr[200111];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	get1(q);
	for(int i=1;i<=q;i++)get2(ql[i],qr[i]);
	
	sam::construct(s,n,pos);
	
//	for(int i=1;i<=n;i++)printf("i= %d pos= %d\n",i,pos[i]);
//	for(int i=1;i<=tot;i++)printf("%d fa= %d len= %d\n",i,fa[i],val[i]);
	
	for(int i=2;i<=tot;i++)g[fa[i]].pb(i);
	for(int i=1;i<=n;i++)have[pos[i]]=i;
	
	dfs1(1);
	dfs2(1,1);
	
	for(int i=1;i<=q;i++)addquery(ql[i],qr[i],i);
	
	dfs(1);
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	
	return 0;
}