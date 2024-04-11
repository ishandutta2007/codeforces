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

const int maxn=2333;
int n,m,a[12][maxn],dp[1<<12],nxt[1<<12],ord[maxn],mx[maxn];
#define getcode(i,j) (((i)>>(j))&1)
bool cmp(int x,int y){return mx[x]>mx[y];}
void solve()
{
	get2(n,m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)get1(a[i][j]);
	for(int i=0;i<(1<<n);i++)dp[i]=-inf;
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		nxt[i]=i<<1;
		nxt[i]|=(nxt[i]>>n);
		nxt[i]&=(1<<n)-1;
	}
	for(int j=0;j<m;j++)
	{
		mx[j]=0;
		for(int i=0;i<n;i++)mx[j]=max(mx[j],a[i][j]);
		ord[j]=j;
	}
	sort(ord,ord+m,cmp);
	for(int jv=0;jv<n&&jv<m;jv++)
	{
		int j=ord[jv];
		for(int msk=0;msk<(1<<n);msk++)
		{
			for(int i=0;i<n;i++)if(!getcode(msk,i))dp[msk|(1<<i)]=max(dp[msk|(1<<i)],dp[msk]+a[i][j]);
		}
		for(int i=0;i<n;i++)for(int msk=0;msk<(1<<n);msk++)dp[msk]=max(dp[msk],dp[nxt[msk]]);
	}
	printf("%d\n",dp[(1<<n)-1]);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}