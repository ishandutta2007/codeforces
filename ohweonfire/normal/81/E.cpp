// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <cassert>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

vector<int> g[100111],id[100111];
int n,dep[100111],tp[100111],stk[100111];
bool incyc[100111];int clen,cyc[100111];
void dfs(int x,int fid=0)
{
	stk[dep[x]]=x;
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(!dep[g[x][i]])
		{
			dep[g[x][i]]=dep[x]+1;
			dfs(g[x][i],id[x][i]);
		}
		else if(dep[g[x][i]]<dep[x]&&id[x][i]!=fid)
		{
			clen=0;
			for(int j=dep[g[x][i]];j<=dep[x];j++)
			{
				cyc[++clen]=stk[j];
				incyc[stk[j]]=1;
			}
		}
	}
}

pii operator +(const pii&a,const pii&b){return mp(a.ff+b.ff,a.ss+b.ss);}
pii operator -(const pii&a,const pii&b){return mp(a.ff-b.ff,a.ss-b.ss);}
void operator +=(pii&a,const pii&b){a=a+b;}

int tv[100111];
pii tdp[100111][2],dp1[100111],dp2[100111],ans;//0: not matched 1: matched down
vector<pii>vs;
void dfs2(int x,int f=0)
{
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f&&!incyc[g[x][i]])
	{
		dfs2(g[x][i],x);
		tdp[x][0]+=max(tdp[g[x][i]][0],tdp[g[x][i]][1]);
	}
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f&&!incyc[g[x][i]])
	{
		pii tmp=tdp[x][0]-max(tdp[g[x][i]][0],tdp[g[x][i]][1])+tdp[g[x][i]][0]+mp(1,tp[x]!=tp[g[x][i]]);
		if(tmp>tdp[x][1])
		{
			tdp[x][1]=tmp;
			tv[x]=g[x][i];
		}
	}
}
void dfs3(int x,int v,int f=0)
{
	if(v==1)vs.pb(mp(x,tv[x]));
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f&&!incyc[g[x][i]])
	{
		if(v==0||g[x][i]!=tv[x])dfs3(g[x][i],tdp[g[x][i]][0]<tdp[g[x][i]][1],x);
		else dfs3(g[x][i],0,x);
	}
}
void do_dp(int l,int r,pii dp[100111])
{
	for(int i=l;i<=r;i++)
	{
		dp[i]=dp[i-1]+max(tdp[cyc[i]][0],tdp[cyc[i]][1]);
		if(i>l)dp[i]=max(dp[i],dp[i-2]+tdp[cyc[i]][0]+tdp[cyc[i-1]][0]+mp(1,tp[cyc[i]]!=tp[cyc[i-1]]));
	}
}
void recover(int l,int r,pii dp[100111])
{
	int i=r;
	while(i>=l)
	{
		if(dp[i]==dp[i-1]+max(tdp[cyc[i]][0],tdp[cyc[i]][1]))
		{
			dfs3(cyc[i],tdp[cyc[i]][0]<tdp[cyc[i]][1]);
			i--;
		}
		else
		{
			vs.pb(mp(cyc[i-1],cyc[i]));
			dfs3(cyc[i],0);
			dfs3(cyc[i-1],0);
			i-=2;
		}
	}
}
void calc(int x)
{
	dep[x]=1;clen=0;dfs(x);
	for(int i=1;i<=clen;i++)dfs2(cyc[i]);
//	printf("x= %d\n",x);
//	printf("clen= %d\n",clen);for(int i=1;i<=clen;i++)printf("%d ",cyc[i]);puts("");
	dp1[1]=mp(1,tp[cyc[1]]!=tp[cyc[clen]])+tdp[cyc[1]][0]+tdp[cyc[clen]][0];
	do_dp(2,clen-1,dp1);
	do_dp(1,clen,dp2);
	if(dp1[clen-1]>dp2[clen])//match cyc[1] with cyc[clen]
	{
		ans+=dp1[clen-1];
		vs.pb(mp(cyc[1],cyc[clen]));
		dfs3(cyc[1],0);dfs3(cyc[clen],0);
		recover(2,clen-1,dp1);
	}
	else
	{
		ans+=dp2[clen];
		recover(1,clen,dp2);
	}
	if((int)vs.size()!=ans.ff)
	{
		puts("Baojing");for(;;);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	get1(n);
	for(int i=1,f;i<=n;i++)
	{
		get2(f,tp[i]);
//		do{f=(rand()<<10|rand())%n+1;}while(f==i);
//		tp[i]=rand()%2+1;
//		printf("%d %d\n",f,tp[i]);
		g[f].pb(i);g[i].pb(f);
		id[f].pb(i);id[i].pb(i);
	}
//	puts("");
	for(int i=1;i<=n;i++)if(!dep[i])calc(i);
	printf("%d %d\n",ans.ff,ans.ss);
	for(auto v:vs)printf("%d %d\n",v.ff,v.ss);
	return 0;
}