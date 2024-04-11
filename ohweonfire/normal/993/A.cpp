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

pii a[4],b[4];

int area(const pii&a,const pii&b,const pii&c)
{
	return (b.ff-a.ff)*(c.ss-a.ss)-(b.ss-a.ss)*(c.ff-a.ff);
}

bool in(pii a[4],pii b)
{
	int v1=0,v2=0;
	for(int i=0;i<4;i++)
	{
		v1+=area(a[0],a[i],a[i+1&3]);
		v2+=abs(area(a[i],a[i+1&3],b));
	}
	return abs(v1)==v2;
}
int main()
{
	for(int i=0;i<4;i++)
	{
		get2(a[i].ff,a[i].ss);
		a[i].ff<<=1;
		a[i].ss<<=1;
	}
	for(int i=0;i<4;i++)
	{
		get2(b[i].ff,b[i].ss);
		b[i].ff<<=1;
		b[i].ss<<=1;
	}
	for(int i=-200;i<=200;i++)for(int j=-200;j<=200;j++)if(in(a,mp(i,j))&&in(b,mp(i,j)))
	{
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}