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

const int maxn=200111;

int n,p[maxn],x,a,y,b;
LL k;

bool check(int t)
{
	LL ret=0;
	int t1=t/a,t2=t/b,t3=t/((LL)a*b/__gcd(a,b));
	t1-=t3;t2-=t3;
	for(int i=1;i<=t3;i++)ret+=p[i]/100*(x+y);
	for(int i=1;i<=t1;i++)ret+=p[i+t3]/100*x;
	for(int i=1;i<=t2;i++)ret+=p[i+t3+t1]/100*y;
	return (ret>=k);
}

void solve()
{
	get1(n);for(int i=1;i<=n;i++)get1(p[i]);sort(p+1,p+n+1);reverse(p+1,p+n+1);
	get2(x,a);get2(y,b);get1(k);
	if(x<y)
	{
		swap(x,y);
		swap(a,b);
	}
	
	int lb=0,rb=n+1;
	while(lb<rb-1)
	{
		int mid=(lb+rb)>>1;
		if(check(mid))rb=mid;
		else lb=mid;
	}
	if(rb==n+1)rb=-1;
	printendl(rb);
}
int main()
{
	int tc;get1(tc);while(tc--)solve();
	return 0;
}