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
#define pb emplace_back
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
#define hash hashy

int head[20111],nxt[40111],to[40111],w[40111],etot=1;
void addedge(int u,int v,int c){nxt[++etot]=head[u];head[u]=etot;to[etot]=v;w[etot]=c;}

const int magic=150;
const int mod=998244353;
const uLL base=43,rbase=(mod*22ll+1)/base;
uLL power[20111],rpower[20111];
namespace hash
{
	int dep[20111],fid[20111],fa[20111];
	
	int hsx1[20111],hsy1[20111];//x: up  y: down
	int fu[magic][20111],fv[magic][20111];
	
	inline int up(const int&x,const int&d){return fu[d%magic][fv[d/magic][x]];}
	inline int getlca(int u,int v)
	{
		if(dep[u]<dep[v])swap(u,v);
		u=up(u,dep[u]-dep[v]);
		if(u==v)return u;
		for(int i=14;i>=0;i--)if(dep[u]>>i&&up(u,1<<i)!=up(v,1<<i))
		{
			u=up(u,1<<i);
			v=up(v,1<<i);
		}
		return fa[u];
	}
	
	inline int hsx(const int&x,const int&d){return (hsx1[x]-hsx1[up(x,d)]*power[d]%mod+mod)%mod;}
	inline int hsy(const int&x,const int&d){return (hsy1[x]-hsy1[up(x,d)]+mod)*rpower[dep[x]-d]%mod;}
	inline int geths(const int&x,const int&y,const int&lca)
	{
		return (hsx(x,dep[x]-dep[lca])+power[dep[x]-dep[lca]]*hsy(y,dep[y]-dep[lca]))%mod;
	}
	inline int geths(const int&x,const int&y){return geths(x,y,getlca(x,y));}
	inline int getnv(const int&x,const int&y,const int&lca,const int&k)
	{
		if(k<=dep[x]-dep[lca])return up(x,k);
		else if(k>dep[x]+dep[y]-(dep[lca]<<1))return -1;
		else return up(y,dep[x]+dep[y]-(dep[lca]<<1)-k);
	}
	inline int getne(const int&x,const int&y,const int&lca,const int&k)
	{
		if(k<=dep[x]-dep[lca])return w[fid[up(x,k-1)]];
		else if(k>dep[x]+dep[y]-(dep[lca]<<1))return -1;
		else return w[fid[up(y,dep[x]+dep[y]-(dep[lca]<<1)-k)]];
	}
	inline int getne(const int&x,const int&y,const int&k){return getne(x,y,getlca(x,y),k);}
	inline int getnv(const int&x,const int&y,const int&k){return getnv(x,y,getlca(x,y),k);}
	
	inline int getlcp(const int&x,const int&y,const int&xx,const int&yy)
	{
		int l=getlca(x,y),ll=getlca(xx,yy);
		int le=0,ri=min(dep[x]+dep[y]-(dep[l]<<1),dep[xx]+dep[yy]-(dep[ll]<<1))+1,mid;
		while(le<ri-1)
		{
			mid=(le+ri)>>1;
			int p=getnv(x,y,l,mid),pp=getnv(xx,yy,ll,mid);
			if((mid<=dep[x]-dep[l]?geths(x,p,p):geths(x,p,l))==(mid<=dep[xx]-dep[ll]?geths(xx,pp,pp):geths(xx,pp,ll)))
				le=mid;
			else ri=mid;
		}
		return le;
	}
	
	void dfs(const int&x)
	{
		fu[0][x]=x;
		for(int i=1;i<magic;i++)
			fu[i][x]=fa[fu[i-1][x]];
		fv[0][x]=x;fv[1][x]=fa[fu[magic-1][x]];
		for(int i=2;i<magic;i++)fv[i][x]=fv[1][fv[i-1][x]];
		
		for(int i=head[x];i;i=nxt[i])if(to[i]!=fa[x])
		{
			fa[to[i]]=x;fid[to[i]]=i;dep[to[i]]=dep[x]+1;
			hsx1[to[i]]=(hsx1[x]*base+w[i]+1)%mod;
			hsy1[to[i]]=(hsy1[x]+(w[i]+1)*power[dep[x]])%mod;
			dfs(to[i]);
		}
	}
};

inline bool cmp(const pii&x,const pii&y)
{
	int p=hash::getlcp(x.ff,x.ss,y.ff,y.ss);
	return hash::getne(x.ff,x.ss,p+1)<hash::getne(y.ff,y.ss,p+1);
}

vector<int>qs[20111];
int qx[20111],qy[20111],ans[20111],n,q;

bool use[20111];
int seq[20111],tot,sz[20111],mx[20111];

void rdfs(const int&x,const int&f)
{
	sz[x]=1;mx[x]=0;seq[++tot]=x;
	for(int i=head[x];i;i=nxt[i])if(to[i]!=f&&!use[to[i]])
	{
		rdfs(to[i],x);
		sz[x]+=sz[to[i]];
		mx[x]=max(mx[x],sz[to[i]]);
	}
}
int getroot(int&rt)
{
	tot=0;rdfs(rt,0);rt=0;
	for(int i=1;i<=tot;i++)
	{
		mx[seq[i]]=max(mx[seq[i]],tot-sz[seq[i]]);
		if(rt==0||mx[rt]>mx[seq[i]])rt=seq[i];
	}
}

vector<int> chs[40111];
int ch[20111][26],ttot;
inline int newnode(){ttot++;memset(ch[ttot],0,sizeof(ch[ttot]));chs[ttot].clear();return ttot;}

int merge(const int&x,const int&y)
{
	if(!x||!y)return x|y;
	for(auto&v:chs[y])chs[x].pb(v);
	chs[y].clear();
	for(int i=0;i<26;i++)ch[x][i]=merge(ch[x][i],ch[y][i]);
	return x;
}


pii vseq[20111],qseq[20111];
int vtot,qtot,dep[20111];
void dfs(const int&x,const int&f,const int&now)
{
	chs[now].pb(x);dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])if(!use[to[i]]&&to[i]!=f)
	{
		if(!ch[now][w[i]])ch[now][w[i]]=newnode();
		dfs(to[i],x,ch[now][w[i]]);
	}
}
void extract(const int&p,const int&root)
{
	for(auto&v:chs[p])vseq[++vtot]=mp(root,v);
	for(int i=0;i<26;i++)if(ch[p][i])extract(ch[p][i],root);
}

void solve(int x)
{
	getroot(x);
	
	ttot=qtot=0;int rt=newnode();
	
	dep[x]=0;
	for(int i=head[x];i;i=nxt[i])if(!use[to[i]])
	{
		int prt=newnode();
		dfs(to[i],x,prt);
		vtot=0;extract(prt,x);
		ch[rt][w[i]]=merge(ch[rt][w[i]],prt);
		for(int j=1;j<=vtot;j++)
		{
			for(auto&q:qs[vseq[j].ss])
			{
				int lcp=hash::getlcp(qx[q],qy[q],qx[q],x);
				if(lcp<dep[qx[q]])
				{
					if(hash::getne(qx[q],qy[q],lcp+1)>hash::getne(qx[q],x,lcp+1))
						ans[q]+=tot-vtot;
				}
				else
				{
					int k=hash::getnv(qx[q],qy[q],lcp);
					qseq[++qtot]=mp(k,q);
					ans[q]-=lower_bound(vseq+1,vseq+vtot+1,mp(k,qy[q]),cmp)-vseq-1;
				}
			}
		}
	}
	
	for(auto&q:qs[x])qseq[++qtot]=mp(x,q);
	if(qtot)
	{
		vtot=0;vseq[++vtot]=mp(x,x);
		extract(rt,x);
		
		for(int i=1;i<=qtot;i++)
		{
			ans[qseq[i].ss]+=lower_bound(vseq+1,vseq+vtot+1,mp(qseq[i].ff,qy[qseq[i].ss]),cmp)-vseq-1;
			if(qx[qseq[i].ss]==x)ans[qseq[i].ss]--;
		}
	}
	use[x]=1;
	for(int i=head[x];i;i=nxt[i])if(!use[to[i]])
		solve(to[i]);
}

int main()
{
	power[0]=rpower[0]=1;
	for(int i=1;i<20111;i++)
	{
		power[i]=power[i-1]*base%mod;
		rpower[i]=rpower[i-1]*rbase%mod;
	}
	
	get2(n,q);
	for(int i=1,u,v;i<n;i++)
	{
		char c;
		get2(u,v);c=getchar();
		addedge(u,v,c-'a');
		addedge(v,u,c-'a');
	}
	for(int i=1;i<=q;i++)
	{
		get2(qx[i],qy[i]);
		qs[qx[i]].pb(i);
	}
	hash::dfs(1);
	
	solve(1);
	for(int i=1;i<=q;i++)printendl(ans[i]);
	return 0;
}