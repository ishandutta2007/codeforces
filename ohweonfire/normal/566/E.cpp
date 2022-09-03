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

const int maxn=1111;
vector<int> g[maxn];
int n,sz[maxn],tp[maxn],dgr[maxn];
bool leaf[maxn];
bitset<maxn>con[maxn],tmp;
vector<int> have[maxn];

void dfs(int x,int f=0)
{
	for(auto v:g[x])if(v!=f)
	{
		tp[v]=tp[x]^1;
		dfs(v,x);
	}
}

bool cmp(int x,int y){return tp[x]<tp[y];}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		int k,x;get1(k);sz[i]=k;
		while(k--)
		{
			get1(x);
			con[i].set(x);
			have[x].pb(i);
		}
	}
	if(n==2)
	{
		puts("1 2");
		return 0;
	}
	bool bad=1;
	for(int i=1;i<=n;i++)if(sz[i]!=n)bad=0;
	if(bad)
	{
		for(int i=2;i<=n;i++)printf("1 %d\n",i);
		puts("");
		return 0;
	}
	for(int i=1;i<=n;i++)leaf[i]=1;
	
	vector<pii> es;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		tmp=con[i]&con[j];
		if(!tmp.any())continue;
		int v1=tmp._Find_first(),v2=tmp._Find_next(v1);
		if(v2==(int)tmp.size())continue;
		if(tmp._Find_next(v2)!=tmp.size())continue;
		es.pb(mp(v1,v2));
	}
	sort(es.begin(),es.end());es.erase(unique(es.begin(),es.end()),es.end());
	if(es.size()==1)
	{
		int v1=0,v2=0;
		for(int i=1;i<=n;i++)if(sz[i]!=n)
		{
			if(!v1)v1=i;
			else if(con[v1]!=con[i])v2=i;
		}
		for(int i=1;i<=n;i++)if(con[v1][i]&&i!=es[0].ff&&i!=es[0].ss)es.pb(mp(es[0].ff,i));
		for(int i=1;i<=n;i++)if(con[v2][i]&&i!=es[0].ff&&i!=es[0].ss)es.pb(mp(es[0].ss,i));
	}
	else
	{
		for(auto v:es)
		{
			g[v.ff].pb(v.ss);
			g[v.ss].pb(v.ff);
		}
		dfs(es[0].ff);
		for(int i=1;i<=n;i++)leaf[i]=1;
		for(auto v:es)
		{
			leaf[v.ff]=leaf[v.ss]=0;
			dgr[v.ff]++;dgr[v.ss]++;
		}
		for(int i=1;i<=n;i++)if(leaf[i])
		{
			int piv=0;
			for(auto v:have[i])if(piv==0||sz[v]<sz[piv])piv=v;
			
			vector<int>cand;
			for(int j=1;j<=n;j++)if(!leaf[j]&&con[piv][j])cand.pb(j);
			if(cand.size()==2)
			{
				if(dgr[cand[0]]==1)es.pb(mp(cand[0],i));
				else es.pb(mp(cand[1],i));
				continue;
			}
			else
			{
				sort(cand.begin(),cand.end(),cmp);
				if(tp[cand[0]]!=tp[cand[1]])es.pb(mp(cand[0],i));
				else es.pb(mp(cand[cand.size()-1],i));
			}
		}
	}
	for(auto v:es)printf("%d %d\n",v.ff,v.ss);
	return 0;
}