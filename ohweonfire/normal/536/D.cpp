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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=2111;

vector<int>g[maxn],l[maxn];
bool use[maxn];
int n,m,s,t,p[maxn];
LL sdist[maxn],tdist[maxn];

void dijkstra(int s,LL*d)
{
	memset(use,0,sizeof(use));
	memset(d,-1,sizeof(LL)*maxn);
	d[s]=1;
	while(true)
	{
		int piv=0;
		for(int i=1;i<=n;i++)if(!use[i]&&d[i]!=-1&&(piv==0||d[piv]>d[i]))piv=i;
		if(!piv)break;
		use[piv]=1;
		for(int i=0;i<(int)g[piv].size();i++)if(d[g[piv][i]]==-1||d[g[piv][i]]>d[piv]+l[piv][i])
			d[g[piv][i]]=d[piv]+l[piv][i];
	}
}

LL dps[maxn][maxn],dpt[maxn][maxn],sum[maxn][maxn];
int cnt[maxn][maxn];
void prework(LL*d)
{
	vector<LL>vs;
	for(int i=1;i<=n;i++)vs.pb(d[i]);
	sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)d[i]=upper_bound(vs.begin(),vs.end(),d[i])-vs.begin();
}

int main()
{
	get2(n,m);get2(s,t);
	for(int i=1;i<=n;i++)get1(p[i]);
	
	for(int i=1,u,v,w;i<=m;i++)
	{
		get3(u,v,w);
		g[u].pb(v);l[u].pb(w);
		g[v].pb(u);l[v].pb(w);
	}
	
	dijkstra(s,sdist);
	dijkstra(t,tdist);
	prework(sdist);
	prework(tdist);
	
	for(int i=1;i<=n;i++)
	{
		sum[sdist[i]][tdist[i]]+=p[i];
		cnt[sdist[i]][tdist[i]]++;
	}
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n+1;j++)
	{
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
	}
//	for(int i=1;i<=n;i++)printf("i= %d %d %d\n",i,sdist[i],tdist[i]);
	for(int i=n;i>=0;i--)for(int j=n;j>=0;j--)
	{
		if(cnt[i][n]+cnt[n][j]-cnt[i][j]==cnt[n][n])continue;
		LL s;int c;
		
		dps[i][j]=-Linf;
		
		s=sum[i+1][n]-sum[i][n]-sum[i+1][j]+sum[i][j];
		c=cnt[i+1][n]-cnt[i][n]-cnt[i+1][j]+cnt[i][j];
		
		dps[i][j]=max(dps[i][j],dps[i+1][j]+s);
		if(c)dps[i][j]=max(dps[i][j],dpt[i+1][j]+s);
		
		dpt[i][j]=Linf;
		s=sum[n][j+1]-sum[n][j]-sum[i][j+1]+sum[i][j];
		c=cnt[n][j+1]-cnt[n][j]-cnt[i][j+1]+cnt[i][j];
		dpt[i][j]=min(dpt[i][j],dpt[i][j+1]-s);
		if(c)dpt[i][j]=min(dpt[i][j],dps[i][j+1]-s);
//		printf("i= %d j= %d dp= %lld %lld\n",i,j,dps[i][j],dpt[i][j]);
	}
	if(dps[0][0]>0)puts("Break a heart");
	else if(dps[0][0]==0)puts("Flowers");
	else puts("Cry");
	
	return 0;
}