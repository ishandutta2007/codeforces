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

mt19937 rng;
int rnd(){return rng();}
int rnd(int x,int y){return uniform_int_distribution<int>(x, y)(rng);}

int n,a[maxn];

vector<int> getfac(int x)
{
	vector<int> ret;
	for(int i=2;i*i<=x;i++)if(x%i==0)
	{
		ret.pb(i);
		while(x%i==0)x/=i;
	}
	if(x>1)ret.pb(x);
	return ret;
}
bool have1[10],have2[10];

int ans[maxn];
void calc_ans(int k1,int k2)
{
	vector<int> v1=getfac(a[k1]),v2=getfac(a[k2]);
	vector<int> choose;
	memset(have1,0,sizeof(have1));memset(have2,0,sizeof(have2));
	for(int i=1;i<=n;i++)
	{
		if(i==k1||i==k2)continue;
		bool ok=0;
		for(int j=0;j<(int)v1.size();j++)if(a[i]%v1[j]!=0)
		{
			if(!have1[j])ok=1;
			have1[j]=1;
		}
		if(ok)choose.pb(i);
		else
		{
			for(int j=0;j<(int)v2.size();j++)if(a[i]%v2[j]!=0)
			{
				if(!have2[j])ok=1;
				have2[j]=1;
			}
			if(ok)choose.pb(i);
		}
	}
	int sz=(int)choose.size();
	for(int i=0;i<(1<<sz);i++)
	{
		memset(have1,0,sizeof(have1));memset(have2,0,sizeof(have2));
		for(int j=0;j<sz;j++)
		{
			if((i>>j)&1)
			{
				for(int k=0;k<(int)v1.size();k++)have1[k]|=(a[choose[j]]%v1[k]!=0);
			}
			else
			{
				for(int k=0;k<(int)v2.size();k++)have2[k]|=(a[choose[j]]%v2[k]!=0);
			}
		}
		bool ok=1;
		for(int j=0;j<(int)v1.size();j++)ok&=have1[j];
		for(int j=0;j<(int)v2.size();j++)ok&=have2[j];
		if(ok)
		{
			puts("YES");
			for(int i=1;i<=n;i++)ans[i]=1;
			ans[k1]=2;
			for(int j=0;j<sz;j++)ans[choose[j]]=((i>>j)&1)+1;
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			puts("");
			exit(0);
		}
	}
}

int main()
{
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	
	if(n<=15)
	{
		for(int i=1;i<(1<<n)-1;i++)
		{
			int g1=0,g2=0;
			for(int j=1;j<=n;j++)
			{
				if((i>>j-1)&1)g1=__gcd(g1,a[j]);
				else g2=__gcd(g2,a[j]);
			}
			if(g1==1&&g2==1)
			{
				puts("YES");
				for(int j=1;j<=n;j++)printf("%d ",((i>>j-1)&1)+1);
				return 0;
			}
		}
		puts("NO");
		return 0;
	}
	for(int i=1;i<=10;i++)
	{
		int q=rnd(2,n);
		calc_ans(1,q);
	}
	puts("NO");
	return 0;
}