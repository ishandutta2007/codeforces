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

const int maxn=100111;

void nosol()
{
	puts("IMPOSSIBLE");
	exit(0);
}

vector<int> g[maxn];
int L,R,n,m,l[maxn],r[maxn],eu[maxn],ev[maxn];

int tp[maxn];
void dfs(int x,int t)
{
	if(tp[x]!=-1)
	{
		if(tp[x]!=t)nosol();
		return;
	}
	tp[x]=t;
	for(int i=0;i<(int)g[x].size();i++)dfs(g[x][i],t^1);
}

int main()
{
	get2(L,R);get2(n,m);
	
	for(int i=1;i<=n;i++)get2(l[i],r[i]);
	for(int i=1;i<=m;i++)
	{
		get2(eu[i],ev[i]);
		g[eu[i]].pb(ev[i]);
		g[ev[i]].pb(eu[i]);
	}
	
	int n1=*max_element(l+1,l+n+1),n2=*min_element(r+1,r+n+1);
	if(n1+n2<L)n1=L-n2;
	else if(n1+n2>R)n2=R-n1;
	if(n1<0||n2<0)nosol();
	
	memset(tp,-1,sizeof(tp));
	for(int i=1;i<=n;i++)
	{
		bool ok1=(l[i]<=n1&&n1<=r[i]),ok2=(l[i]<=n2&&n2<=r[i]);
		if(!ok1&&!ok2)nosol();
		if(!ok1)dfs(i,1);
		else if(!ok2)dfs(i,0);
	}
	for(int i=1;i<=n;i++)if(tp[i]==-1)dfs(i,0);
	
	puts("POSSIBLE");
	printf("%d %d\n",n1,n2);
	for(int i=1;i<=n;i++)putchar('1'+tp[i]);puts("");
	
	return 0;
}