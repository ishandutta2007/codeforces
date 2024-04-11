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

const int maxn=400111;

map<int,int> cnt;

int n,a[maxn],c[maxn],p,q,pre[maxn];
vector<int> ansv[maxn];

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		cnt[a[i]]++;
	}
	for(auto x:cnt)c[x.ss]++;
	
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(LL)i*c[i];
	for(int i=1;i<=n;i++)c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
	{
		int val=pre[i]+(c[n]-c[i])*i;
		if(val/i>=i&&val/i*i>p*q)
		{
			p=i;
			q=val/i;
		}
	}
	vector<pii> vs;
	int need=p*q;
	for(auto x:cnt)
	{
		int have=min(need,min(x.ss,p));
		vs.pb(mp(have,x.ff));
		need-=have;
	}
	sort(vs.begin(),vs.end());
	swap(p,q);
	for(int i=1;i<=p;i++)ansv[i].resize(q+1);
	int cx=1,cy=1;
	for(auto x:vs)
	{
//		printf("x= %d y= %d\n",x.ff,x.ss);
		int t=x.ff;
		while(t--)
		{
			ansv[cx][cy]=x.ss;
			cy++;if(cy==q+1)
			{
				cy=1;
				cx++;
			}
		}
	}
	printf("%d\n%d %d\n",p*q,p,q);
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=q;j++)printf("%d ",ansv[(i+p-j)%p+1][j]);
		puts("");
	}
	return 0;
}