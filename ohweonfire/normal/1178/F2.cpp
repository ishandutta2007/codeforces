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

const int maxm=1000111;
const int maxn=1111;
const int mod=998244353;

int n,m,a[maxm],b[maxm],tot;
int dp[maxn][maxn],pre[maxn],nxt[maxn],last[maxn],mn[maxn][maxn];
vector<int> vs[maxn];

int dfs(int l,int r)
{
	if(l>r)return 1;
	if(dp[l][r]!=-1)return dp[l][r];
	int mnv=mn[l][r],lv=*vs[mnv].begin(),rv=*vs[mnv].rbegin();
	if(lv<l||rv>r)return 0;
	int ret=1,s1=0,s2=0;
	for(int i=0;i<(int)vs[mnv].size()-1;i++)ret=(LL)ret*dfs(vs[mnv][i]+1,vs[mnv][i+1]-1)%mod;
	for(int i=l;i<=lv;i++)s1=(s1+(LL)dfs(l,i-1)*dfs(i,lv-1))%mod;
	for(int i=rv;i<=r;i++)s2=(s2+(LL)dfs(rv+1,i)*dfs(i+1,r))%mod;
	ret=(LL)ret*s1%mod*s2%mod;
	return dp[l][r]=ret;
}

int main()
{
	get2(n,m);
	for(int i=1;i<=m;i++)get1(a[i]);
	tot=0;
	for(int i=1;i<=m;i++)if(i==1||a[i]!=a[i-1])b[++tot]=a[i];
	if(tot>=n+n)
	{
		puts("0");
		return 0;
	}
	m=tot;memcpy(a,b,sizeof(a));
	
	memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	memset(last,0,sizeof(last));
	for(int i=m;i>=1;i--)
	{
		nxt[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		vs[a[i]].pb(i);
		int mnv=inf;
		for(int j=i;j<=m;j++)
		{
			mnv=min(mnv,a[j]);
			mn[i][j]=mnv;
		}
	}
	
	memset(dp,-1,sizeof(dp));
	printendl(dfs(1,m));
	return 0;
}