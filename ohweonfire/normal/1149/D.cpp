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

const int maxn=233;

int f[maxn],sz[maxn],id[maxn],tot;
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

int n,m,a,b;
int eu[maxn],ev[maxn],ew[maxn];
vector<int>es[maxn];

int dp[1<<17][71],vs[10111],vtot;
int go_a[10111],go_b[10111];
queue<pii> qv[10111];

void dijkstra(int msk,int x)
{
	for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++)vs[++vtot]=i*a+j*b;
	sort(vs+1,vs+vtot+1);vtot=unique(vs+1,vs+vtot+1)-vs-1;
	for(int i=1;i<=vtot;i++)
	{
		go_a[i]=lower_bound(vs+1,vs+vtot+1,vs[i]+a)-vs;
		if(go_a[i]>vtot||vs[go_a[i]]!=vs[i]+a)go_a[i]=-1;
		go_b[i]=lower_bound(vs+1,vs+vtot+1,vs[i]+b)-vs;
		if(go_b[i]>vtot||vs[go_b[i]]!=vs[i]+b)go_b[i]=-1;
	}
	
	memset(dp,inf,sizeof(dp));
	dp[msk][x]=0;qv[1].push(mp(msk,x));
	
	int cur=1;
	while(true)
	{
		while(cur<=vtot&&(int)qv[cur].size()==0)cur++;
		if(cur>vtot)break;
		msk=qv[cur].front().ff;x=qv[cur].front().ss;qv[cur].pop();
		if(vs[cur]!=dp[msk][x])continue;
		for(auto e:es[x])
		{
			int v=eu[e]^ev[e]^x;
			if(ew[e]==b&&id[v]!=-1&&((msk>>id[v])&1))continue;
			int nmsk=msk,nd=dp[msk][x]+ew[e],nid=cur;if(id[v]!=-1)nmsk|=(1<<id[v]);
			if(ew[e]==a)nid=go_a[nid];else nid=go_b[nid];if(nid==-1||dp[nmsk][v]<=nd)continue;
			dp[nmsk][v]=nd;qv[nid].push(mp(nmsk,v));
		}
	}
}

int main()
{
	get2(n,m);get2(a,b);
	for(int i=1;i<=m;i++)get3(eu[i],ev[i],ew[i]);
	
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)if(ew[i]==a)f[gf(eu[i])]=gf(ev[i]);
	
	for(int i=1;i<=n;i++)sz[gf(i)]++;
	memset(id,-1,sizeof(id));
	for(int i=1;i<=n;i++)if(f[i]==i&&sz[i]>3)id[i]=tot++;
	for(int i=1;i<=n;i++)if(f[i]!=i)id[i]=id[gf(i)];
	
	for(int i=1;i<=m;i++)if(ew[i]==a||gf(eu[i])!=gf(ev[i]))
	{
		es[eu[i]].pb(i);
		es[ev[i]].pb(i);
	}
	
	if(id[1]!=-1)dijkstra(1<<id[1],1);
	else dijkstra(0,1);
	
	for(int t=1;t<=n;t++)
	{
		int ans=inf;
		for(int i=0;i<(1<<tot);i++)ans=min(ans,dp[i][t]);
		printf("%d%c",ans,t==n?'\n':' ');
	}
	
	return 0;
}