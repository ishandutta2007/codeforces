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

const int maxn=100111;
const int maxv=2000111;
const int base1=443;
const int mod1=1e9+7;
const int base2=43;
const int mod2=998244353;

int power1[maxn],power2[maxn];

int ans[maxn];
namespace kmp
{
	vector<int>qs[maxn];
	int t1[maxn],t2[maxn];
	int addq(int id,int k,int l1,int l2){t1[id]=l1;t2[id]=l2;qs[k].pb(id);}
	
	int nxt[maxn],link[maxn],rnxt[maxn],rlink[maxn],s[maxn],n;
	
	void construct(int*nxt,int*link)
	{
		nxt[1]=0;
		for(int i=2;i<=n;i++)
		{
			nxt[i]=nxt[i-1];
			while(nxt[i]&&s[nxt[i]+1]!=s[i])nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
			if(i-nxt[i]==nxt[i]-nxt[nxt[i]])link[i]=link[nxt[i]];
			else link[i]=nxt[i];
		}
	}
	
	int inter(const pair<int,pii>&a,const pair<int,pii>&b)
	{
		if(a.ff==b.ff)
		{
			if((a.ss.ff-b.ss.ff)%a.ff!=0)return 0;
			int st=max(a.ss.ff,b.ss.ff),ed=min(a.ss.ss,b.ss.ss);
			if(st>ed)return 0;
			return (ed-st)/a.ff+1;
		}
		else
		{
			int sz1=(a.ss.ss-a.ss.ff)/a.ff+1,sz2=(b.ss.ss-b.ss.ff)/b.ff+1,ret=0;
			if(sz1<sz2)
			{
				for(int t=a.ss.ff;t<=a.ss.ss;t+=a.ff)
					ret+=(t>=b.ss.ff&&t<=b.ss.ss&&(t-b.ss.ff)%b.ff==0);
			}
			else
			{
				for(int t=b.ss.ff;t<=b.ss.ss;t+=b.ff)
					ret+=(t>=a.ss.ff&&t<=a.ss.ss&&(t-a.ss.ff)%a.ff==0);
			}
			return ret;
		}
	}
	
	void solve(int k,const vector<int>&ch)
	{
		n=(int)ch.size();
		for(int i=0;i<n;i++)s[i+1]=ch[i];
		construct(nxt,link);reverse(s+1,s+n+1);construct(rnxt,rlink);
		for(auto&i:qs[k])
		{
			vector<pair<int,pii> >v1,v2;
			int t,st,ed,d;
			
			t=t1[i];
			while(t)
			{
				d=t-nxt[t];ed=t;st=link[t]+d;
				v1.pb(mp(d,mp(st,ed)));
				t=link[t];
			}
			reverse(v1.begin(),v1.end());
			
			t=t2[i];
			while(t)
			{
				d=t-rnxt[t];ed=t;st=rlink[t]+d;
				v2.pb(mp(d,mp(n-ed,n-st)));
				t=rlink[t];
			}
			
			int it1=0,it2=0;
			while(it1<(int)v1.size()&&it2<(int)v2.size())
			{
				ans[i]+=inter(v1[it1],v2[it2]);
				if(v1[it1].ss.ss<v2[it2].ss.ss)it1++;
				else it2++;
			}
		}
	}
};

int bit[maxv],vpos[maxn<<1],ltot;
pair<pii,int> lpos[maxn<<1];
void add(int x,const int&v){for(;x<maxv;x+=x&-x)bit[x]+=v;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}

namespace ac
{
	int go[maxv][26],tot=1,rt=1;
	
	int q[maxv],fail[maxv],dfn[maxv],edfn[maxv],timer;
	vector<int> g[maxv];
	
	vector<pii> qs1[maxv],qs2[maxv];
	
	int ans2[maxn<<1];
	void addq(int id,int p1,int p2,int k1,int k2)
	{
		qs1[p1].pb(mp(id,k2));qs1[p2].pb(mp(id,k1));
		qs2[p1].pb(mp(id<<1,k1));qs2[p2].pb(mp(id<<1|1,k2));
	}
	
	int len[maxn<<1];
	void dfs(int x,int dep,int hs1,int hs2)
	{
		add(dfn[x],1);
		vector<pii> mem;
		int id=lower_bound(lpos+1,lpos+ltot+1,mp(mp(hs1,hs2),0))-lpos;
		for(;id<=ltot&&lpos[id].ff.ff==hs1&&lpos[id].ff.ss==hs2;id++)
		{
			mem.pb(mp(lpos[id].ss,len[lpos[id].ss]));
			len[lpos[id].ss]=dep;
		}
		
		for(auto&q:qs1[x])ans[q.ff]+=query(edfn[vpos[q.ss]])-query(dfn[vpos[q.ss]]-1);
		for(auto&q:qs2[x])ans2[q.ff]=len[q.ss];
		
		for(int i=0;i<26;i++)if(go[x][i])
			dfs(go[x][i],dep+1,(hs1+(LL)power1[dep]*(i+1))%mod1,(hs2+(LL)power2[dep]*(i+1))%mod2);
			
		add(dfn[x],-1);
		for(auto&v:mem)len[v.ff]=v.ss;
	}
	
	void rdfs(int x)
	{
		dfn[x]=++timer;
		for(auto&v:g[x])rdfs(v);
		edfn[x]=timer;
	}
	
	void construct()
	{
		int fr=0,rr=0,x;q[rr++]=rt;
		fail[rt]=rt;
		for(;fr<rr;fr++)
		{
			x=q[fr];
			for(int i=0;i<26;i++)if(go[x][i])
			{
				if(x==rt)fail[go[x][i]]=x;
				else
				{
					int&f=fail[go[x][i]];
					f=fail[x];while(f!=rt&&!go[f][i])f=fail[f];
					if(go[f][i])f=go[f][i];
				}
				q[rr++]=go[x][i];
			}
		}
	}
	void solve()
	{
		for(int i=2;i<=tot;i++)g[fail[i]].pb(i);
		rdfs(rt);
		dfs(rt,0,0,0);
	}
};

int head[maxn],nxt[maxn<<1],to[maxn<<1],sv[maxn<<1],etot=1;
void addedge(int u,int v,int w)
{
	nxt[++etot]=head[u];head[u]=etot;
	to[etot]=v;sv[etot]=w;
}

bool useR[maxn];
int sz[maxn],sub[maxn],pos[maxn],tot,seq[maxn],mark[maxn],timer;

void rdfs(int x,int fa)
{
	seq[++tot]=x;sz[x]=1;mark[x]=timer;
	for(int i=head[x];i;i=nxt[i])if(!useR[to[i]]&&to[i]!=fa)
	{
		rdfs(to[i],x);
		sz[x]+=sz[to[i]];
	}
}
int getroot(int x)
{
	timer++;
	tot=0;rdfs(x,0);
	int ret=0;
	for(int i=1;i<=tot;i++)if((sz[seq[i]]<<1)>=tot&&(ret==0||sz[ret]>sz[seq[i]]))
		ret=seq[i];
	return ret;
}

void dfs(int x,int fa,int insub,int cur)
{
	sub[x]=insub;pos[x]=cur;
	for(int i=head[x];i;i=nxt[i])if(!useR[to[i]]&&to[i]!=fa)
	{
		if(!ac::go[cur][sv[i]])ac::go[cur][sv[i]]=++ac::tot;
		dfs(to[i],x,fa==0?to[i]:insub,ac::go[cur][sv[i]]);
	}
}

vector<int> qs[maxn];
int n,m,q,q1[maxn],q2[maxn],qk[maxn];

void solve(int x)
{
	x=getroot(x);
	
	dfs(x,0,x,ac::rt);
	
	for(int _=1;_<=tot;_++)
	{
		int v=seq[_];
		for(auto&i:qs[v])if(mark[q1[i]]==timer&&mark[q2[i]]==timer&&sub[q1[i]]!=sub[q2[i]])
			ac::addq(i,pos[q1[i]],pos[q2[i]],qk[i],qk[i]+m);
	}
	
	useR[x]=1;
	for(int i=head[x];i;i=nxt[i])if(!useR[to[i]])solve(to[i]);
}

vector<int> ch[maxn];
char s[maxn];

int main()
{
	power1[0]=1;for(int i=1;i<maxn;i++)power1[i]=(LL)power1[i-1]*base1%mod1;
	power2[0]=1;for(int i=1;i<maxn;i++)power2[i]=(LL)power2[i-1]*base2%mod2;
	
	get3(n,m,q);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);scanf("%s",s);
		addedge(u,v,s[0]-'a');
		addedge(v,u,s[0]-'a');
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		for(int j=0;s[j];j++)ch[i].pb(s[j]-'a');
	}
	
	for(int i=1;i<=q;i++)
	{
		get3(q1[i],q2[i],qk[i]);
		qs[q1[i]].pb(i);
	}
	
	solve(1);
	
	for(int i=1;i<=m;i++)
	{
		int sz=(int)ch[i].size(),cur,hs1,hs2;
		
		cur=ac::rt;hs1=hs2=0;
		for(int j=0;j<sz;j++)
		{
			if(ac::go[cur][ch[i][j]]==0)ac::go[cur][ch[i][j]]=++ac::tot;
			cur=ac::go[cur][ch[i][j]];
			hs1=((LL)hs1*base1+ch[i][j]+1)%mod1;
			hs2=((LL)hs2*base2+ch[i][j]+1)%mod2;
			if(j<sz-1)lpos[++ltot]=mp(mp(hs1,hs2),i);
		}
		vpos[i]=cur;
		
		cur=ac::rt;hs1=hs2=0;
		for(int j=sz-1;j>=0;j--)
		{
			if(ac::go[cur][ch[i][j]]==0)ac::go[cur][ch[i][j]]=++ac::tot;
			cur=ac::go[cur][ch[i][j]];
			hs1=((LL)hs1*base1+ch[i][j]+1)%mod1;
			hs2=((LL)hs2*base2+ch[i][j]+1)%mod2;
			if(j>0)lpos[++ltot]=mp(mp(hs1,hs2),i+m);
		}
		vpos[i+m]=cur;
	}
	
	ac::construct();
	sort(lpos+1,lpos+ltot+1);
	ac::solve();
	
	for(int i=1;i<=q;i++)if(ac::ans2[i<<1]&&ac::ans2[i<<1|1])kmp::addq(i,qk[i],ac::ans2[i<<1],ac::ans2[i<<1|1]);
	for(int i=1;i<=m;i++)kmp::solve(i,ch[i]);
	
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	
	return 0;
}