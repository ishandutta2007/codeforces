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

const int maxn=1111;

int n,p[maxn][maxn];
double dist[maxn],cur_p[maxn],cur_v[maxn];
bool use[maxn],have[maxn];

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)get1(p[i][j]);
	
	for(int i=1;i<=n;i++)dist[i]=1e10;
	dist[n]=0;
	for(int i=1;i<=n;i++)cur_p[i]=1;
	while(true)
	{
		int piv=0;
		for(int i=1;i<=n;i++)if(dist[i]<1e9&&!use[i]&&(piv==0||dist[piv]>dist[i]))piv=i;
		if(!piv)break;
		use[piv]=1;
		for(int i=1;i<=n;i++)if(!use[i])
		{
			cur_v[i]+=cur_p[i]*p[i][piv]/100.0*(dist[piv]+1);
			cur_p[i]*=(100-p[i][piv])/100.0;
			if(cur_p[i]<1-1e-8)dist[i]=min(dist[i],(cur_v[i]+cur_p[i])/(1-cur_p[i]));
		}
	}
	printf("%.10lf\n",dist[1]);
	return 0;
}