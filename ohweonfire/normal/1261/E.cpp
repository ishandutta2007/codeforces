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

int go[maxn*maxn][2],rt,tot;
int a[maxn],n,val[maxn][maxn],ord[maxn],cur[maxn],rk[maxn];
bool cmp(int x,int y){return a[x]<a[y];}

void solve(int n)
{
	if(!n)
	{
		cur[1]=rt;
		return;
	}
	for(int i=1;i<n;i++)
	{
		val[n+1][i]=(a[i]==n);
		if(a[i]==n)a[i]--;
	}
	solve(n-1);
	cur[n+1]=rt;
	for(int i=1;i<n;i++)
	{
		if(!go[cur[n+1]][val[n+1][i]])go[cur[n+1]][val[n+1][i]]=++tot;
		cur[n+1]=go[cur[n+1]][val[n+1][i]];
	}
	int piv=0;
	for(int i=1;i<=n;i++)if(cur[i]==cur[n+1])piv=i;
	int need=a[n]-1;val[n+1][n]=1;
	for(int i=1;i<=n;i++)
	{
		if(i==piv||!need)val[i][n]=0;
		else
		{
			need--;
			val[i][n]=1;
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		if(!go[cur[i]][val[i][n]])go[cur[i]][val[i][n]]=++tot;
		cur[i]=go[cur[i]][val[i][n]];
	}
}

int main()
{
	rt=++tot;
	
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	sort(a+1,a+n+1);
	solve(n);
	for(int i=1;i<=n;i++)rk[ord[i]]=i;
	printf("%d\n",n+1);
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=n;j++)printf("%d",val[i][rk[j]]);
		puts("");
	}
	
	return 0;
}