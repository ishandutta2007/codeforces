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

int n,m,k,s,a[100111],dist[100111][111];
vector<int>g[100111];

int q[100111];
int main()
{
	get2(n,m);get2(k,s);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	memset(dist,inf,sizeof(dist));
	for(int c=1;c<=k;c++)
	{
		int rr=0;
		for(int i=1;i<=n;i++)if(a[i]==c)
		{
			q[rr++]=i;
			dist[i][c]=0;
		}
		for(int fr=0;fr<rr;fr++)
		{
			int x=q[fr];
			for(auto&v:g[x])if(dist[v][c]==inf)
			{
				dist[v][c]=dist[x][c]+1;
				q[rr++]=v;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(dist[i]+1,dist[i]+k+1);
		int ans=0;
		for(int j=1;j<=s;j++)ans+=dist[i][j];
		printf("%d ",ans);
	}
	return 0;
}