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

const int maxn=1200111;
const int mod=1e9+7;
vector<int> g[maxn],l[maxn];

int tot;
void addedge(int u,int v,int w)
{
//	printf("addedge %d %d w= %d\n",u,v,w);
	g[u].pb(v);l[u].pb(w);
}

int n,m,dig[10],dcnt;

void adde(int u,int v,int id)
{
	dcnt=0;
	while(id)
	{
		dig[dcnt++]=id%10;
		id/=10;
	}
	int last=v;reverse(dig,dig+dcnt);
	for(int i=0;i<dcnt;i++)
	{
		if(i==dcnt-1)addedge(last,u,dig[i]);
		else addedge(last,++tot,dig[i]);
		last=tot;
	}
	
	last=u;
	for(int i=0;i<dcnt;i++)
	{
		if(i==dcnt-1)addedge(last,v,dig[i]);
		else addedge(last,++tot,dig[i]);
		last=tot;
	}
}

int dist[maxn],bfn[maxn],q[maxn],ans[maxn];
void bfs(int x)
{
	memset(dist,-1,sizeof(dist));
	int fr=0,rr=0,tot=0;
	q[rr++]=x;dist[x]=0;ans[x]=0;bfn[x]=++tot;
	for(int nxt=0;fr<rr;fr=nxt)
	{
		while(nxt<rr&&dist[q[fr]]==dist[q[nxt]])nxt++;
		vector<pair<pii,int> > vs;
		for(int j=fr;j<nxt;j++)
		{
			int x=q[j];
			for(int i=0;i<(int)g[x].size();i++)
			{
				if(dist[g[x][i]]==-1)vs.pb(mp(mp(bfn[x]*10+l[x][i],(ans[x]*10ll+l[x][i])%mod),g[x][i]));
			}
		}
		sort(vs.begin(),vs.end());
		pii last=mp(-1,-1);
		for(auto v:vs)if(dist[v.ss]==-1)
		{
			if(v.ff!=last)tot++;
			last=v.ff;
			ans[v.ss]=v.ff.ss;
			dist[v.ss]=dist[q[fr]]+1;
			bfn[v.ss]=tot;
			q[rr++]=v.ss;
		}
	}
}

int main()
{
	get2(n,m);
	tot=n;
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		adde(u,v,i);
	}
	bfs(1);
	for(int i=2;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}