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
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &ex)
{
	char t=getchar();
	bool neg=false;
	ex=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())ex=ex*10+t-'0';
	if(neg)ex=-ex;return true;
}
template<typename T> void print_int(T ex)
{
	if(ex<0)putchar('-'),ex=-ex;
	short a[20]= {},sz=0;
	while(ex>0)a[sz++]=ex%10,ex/=10;
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

#define getcode(i,j) (((i)>>(j))&1)

vector<int> g[111],eid[111];
int n,k,ex[55],ey[55],w[55],m1,m2;
vector<int> vx,vy;

int ans[55],tans[111];

int vs[111],tot;
bool use[111];
void dfs(int x)
{
	vs[tot++]=x;
	use[x]=1;
	for(auto v:g[x])if(!use[v])
		dfs(v);
}

void update(int*ans,int*tans)
{
	int tmp[55]={};
	for(int i=0;i<=50;i++)for(int j=0;i+j<=50;j++)
		tmp[i+j]=(tmp[i+j]+1ll*ans[i]*tans[j])%mod;
	memcpy(ans,tmp,sizeof(tmp));
}
namespace tree_dp
{
	void solve()
	{
		
	}
};
namespace bitmask
{
	int f[1<<25],tans[55];
	int tid[111],n;
	void solve(int idl,int idr)
	{
		n=0;for(int i=0;i<tot;i++)if(vs[i]>=idl&&vs[i]<=idr)tid[vs[i]]=n++;
		for(int i=0;i<(1<<n);i++)f[i]=0;f[0]=1;
		for(int i=0;i<tot;i++)if(vs[i]<idl||vs[i]>idr)
		{
			int&x=vs[i];
			for(int j=(1<<n)-1;j>=0;j--)if(f[j])
			{
				for(int k=0;k<(int)g[x].size();k++)if(!getcode(j,tid[g[x][k]]))
				{
					int nj=j^(1<<tid[g[x][k]]);
					f[nj]=(f[nj]+1ll*f[j]*w[eid[x][k]])%mod;
				}
			}
		}
		memset(tans,0,sizeof(tans));
		for(int i=0;i<(1<<n);i++)
		{
			int num=__builtin_popcount(i);
			tans[num]+=f[i];
			if(tans[num]>=mod)tans[num]-=mod;
		}
		update(ans,tans);
	}
};

int fac[100111];
int main()
{
	fac[0]=1;for(int i=1;i<100111;i++)fac[i]=1ll*i*fac[i-1]%mod;
	get2(n,k);
	for(int i=0;i<k;i++){get3(ex[i],ey[i],w[i]);w[i]=(w[i]+mod-1)%mod;vx.pb(ex[i]);vy.pb(ey[i]);}
	sort(vx.begin(),vx.end());vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());vy.erase(unique(vy.begin(),vy.end()),vy.end());
	m1=(int)vx.size();m2=(int)vy.size();
	for(int i=0;i<k;i++)
	{
		ex[i]=lower_bound(vx.begin(),vx.end(),ex[i])-vx.begin();
		ey[i]=lower_bound(vy.begin(),vy.end(),ey[i])-vy.begin()+m1;
		g[ex[i]].pb(ey[i]);eid[ex[i]].pb(i);
		g[ey[i]].pb(ex[i]);eid[ey[i]].pb(i);
	}
	
	ans[0]=1;
	for(int i=0;i<m1+m2;i++)if(!use[i])
	{
		tot=0;dfs(i);
		int c1=0,c2=0,ce=0;
		for(int j=0;j<tot;j++)
		{
			if(vs[j]<m1)c1++;
			else c2++;
			ce+=(int)g[vs[j]].size();
		}
		ce/=2;ce=ce-tot+1;
		if(c1<=25)bitmask::solve(0,m1-1);
		else if(c2<=25)bitmask::solve(m1,m1+m2-1);
		else tree_dp::solve();
	}
	
	int sum=0;
	for(int i=0;i<=50&&i<=n;i++)sum=(sum+1ll*ans[i]*fac[n-i])%mod;
	printendl(sum);
	return 0;
}