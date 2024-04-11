// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
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

const int mod=1e9+7;
inline void combine(int&ans0,int&ans1,int t0,int t1)
{
	int tt0=ans0,tt1=ans1;
	ans0=(1ll*t0*tt0+1ll*t1*tt1)%mod;
	ans1=(1ll*t0*tt1+1ll*t1*tt0)%mod;
}
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

int n,m,k[100111],a[100111][2],oc[100111][2],cnt[100111];

int vs[100111],vse[100111],tot;
bool use[100111];
void dfs(int x,int fa)
{
	vs[++tot]=x;use[x]=1;
	for(int i=0;i<k[x];i++)if(abs(a[x][i])!=fa&&cnt[abs(a[x][i])]==2)
	{
		int id=abs(a[x][i]),y=abs(oc[id][0])+abs(oc[id][1])-x;
		if(!use[y]||fa)vse[tot]=id;
		if(!use[y])dfs(y,id);
	}
}

int ans0,ans1,dp[100111][2][2];
namespace chain
{
	void solve(int s,int st)
	{
		tot=0;dfs(s,st);
		for(int i=1;i<=tot;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=0;
		if(st)dp[1][0][0]=dp[1][1][0]=1;
		else dp[1][0][0]=1;
		for(int i=1;i<tot;i++)
		{
			int tp=(oc[vse[i]][0]^oc[vse[i]][1])<0;
			for(int j=0;j<2;j++)for(int k=0;k<2;k++)if(dp[i][j][k])
			{
				for(int nxt=0;nxt<2;nxt++)
					add(dp[i+1][nxt^tp][k^(j|nxt)],dp[i][j][k]);
			}
		}
		int t0=0,t1=0;
		t0=dp[tot][0][0]+dp[tot][1][1];if(t0>=mod)t0-=mod;
		t1=dp[tot][0][1]+dp[tot][1][0];if(t1>=mod)t1-=mod;
		if(k[vs[tot]]==2)
		{
			add(t0,dp[tot][0][1]);add(t0,dp[tot][1][1]);
			add(t1,dp[tot][0][0]);add(t1,dp[tot][1][0]);
		}
		combine(ans0,ans1,t0,t1);
	}
};
namespace cycle
{
	void solve(int s)
	{
		tot=0;dfs(s,0);
//		printf("cycle ");for(int i=1;i<=tot;i++)printf("%d ",vs[i]);puts("");
		int ntp=(oc[vse[tot]][0]^oc[vse[tot]][1])<0,t0,t1;
		
		//0 tp
		for(int i=1;i<=tot;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=0;
		dp[1][0][0]=1;
		for(int i=1;i<tot;i++)
		{
			int tp=(oc[vse[i]][0]^oc[vse[i]][1])<0;
			for(int j=0;j<2;j++)for(int k=0;k<2;k++)if(dp[i][j][k])
			{
				for(int nxt=0;nxt<2;nxt++)
					add(dp[i+1][nxt^tp][k^(j|nxt)],dp[i][j][k]);
			}
		}
		t0=t1=0;
		if(!ntp)
		{
			add(t0,dp[tot][0][0]);add(t0,dp[tot][1][1]);
			add(t1,dp[tot][0][1]);add(t1,dp[tot][1][0]);
		}	
		else
		{
			add(t0,dp[tot][0][1]);add(t0,dp[tot][1][1]);
			add(t1,dp[tot][0][0]);add(t1,dp[tot][1][0]);
		}
		
		//1 tp^1
		for(int i=1;i<=tot;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=0;
		dp[1][1][0]=1;
		for(int i=1;i<tot;i++)
		{
			int tp=(oc[vse[i]][0]^oc[vse[i]][1])<0;
			for(int j=0;j<2;j++)for(int k=0;k<2;k++)if(dp[i][j][k])
			{
				for(int nxt=0;nxt<2;nxt++)
					add(dp[i+1][nxt^tp][k^(j|nxt)],dp[i][j][k]);
			}
		}
		if(ntp)
		{
			add(t0,dp[tot][0][0]);add(t0,dp[tot][1][1]);
			add(t1,dp[tot][0][1]);add(t1,dp[tot][1][0]);
		}	
		else
		{
			add(t0,dp[tot][0][1]);add(t0,dp[tot][1][1]);
			add(t1,dp[tot][0][0]);add(t1,dp[tot][1][0]);
		}
//		printf("t0= %d t1= %d\n",t0,t1);
		combine(ans0,ans1,t0,t1);
	}
};

int main()
{
	get2(n,m);
	ans0=1;ans1=0;
	for(int i=1;i<=n;i++)
	{
		get1(k[i]);
		for(int j=0;j<k[i];j++)get1(a[i][j]);
		if(k[i]==2&&abs(a[i][0])==abs(a[i][1]))
		{
			if(a[i][0]==a[i][1])combine(ans0,ans1,1,1);
			else combine(ans0,ans1,0,2);
			k[i]=0;
			cnt[abs(a[i][0])]=2;
			continue;
		}
		for(int j=0;j<k[i];j++)
		{
			if(a[i][j]>0)oc[a[i][j]][cnt[a[i][j]]]=i;
			else oc[-a[i][j]][cnt[-a[i][j]]]=-i;
			cnt[abs(a[i][j])]++;
		}
	}
	for(int i=1;i<=m;i++)if(!cnt[i])combine(ans0,ans1,2,0);
	
	for(int i=1;i<=n;i++)if(k[i])
	{
		bool ok=1;
		for(int j=0;j<k[i];j++)ok&=(cnt[abs(a[i][j])]==1);
		if(ok)
		{
			if(k[i]==1)combine(ans0,ans1,1,1);
			else combine(ans0,ans1,1,3);
			k[i]=0;
		}
	}
	
	for(int i=1;i<=n;i++)if(!use[i]&&k[i])
	{
		if(k[i]==1)chain::solve(i,0);
		else
		{
			int piv=-1;for(int j=0;j<2;j++)if(cnt[abs(a[i][j])]==1)piv=j;
			if(piv!=-1)chain::solve(i,abs(a[i][piv]));
		}
	}
	for(int i=1;i<=n;i++)if(!use[i]&&k[i])cycle::solve(i);
	printf("%d\n",ans1);
	return 0;
}