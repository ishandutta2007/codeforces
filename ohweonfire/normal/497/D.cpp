// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

#define sqr(x) ((x)*(x))
int dist(pii& a,pii& b){return sqr(a.ff-b.ff)+sqr(a.ss-b.ss);}
LL area(pii a,pii b,pii c)
{
	b=mp(b.ff-a.ff,b.ss-a.ss);
	c=mp(c.ff-a.ff,c.ss-a.ss);
	return b.ff*c.ss-b.ss*c.ff;
}
int n,m;
pii p,q,a[1111],b[1111];
int main()
{
	get3(p.ff,p.ss,n);for(int i=0;i<n;i++)get2(a[i].ff,a[i].ss);
	get3(q.ff,q.ss,m);for(int i=0;i<m;i++)get2(b[i].ff,b[i].ss);
	
	int r=dist(p,q);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
	{
		pii c=mp(p.ff-q.ff+b[j].ff,p.ss-q.ss+b[j].ss);
		int d1=dist(a[i],c),d2=dist(a[(i+1)%n],c),d3=dist(a[i],a[(i+1)%n]);
		if(d1==r||d2==r||(d1>r&&d2<r)||(d1<r&&d2>r))
		{
			puts("YES");
			return 0;
		}
		if(d1>r&&d2>r&&d3>=abs(d1-d2)&&sqr(area(a[i],a[(i+1)%n],c))<=1ll*r*d3)
		{
			puts("YES");
			return 0;
		}
	}
	swap(p,q);swap(a,b);swap(n,m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
	{
		pii c=mp(p.ff-q.ff+b[j].ff,p.ss-q.ss+b[j].ss);
		int d1=dist(a[i],c),d2=dist(a[(i+1)%n],c),d3=dist(a[i],a[(i+1)%n]);
		if(d1==r||d2==r||(d1>r&&d2<r)||(d1<r&&d2>r))
		{
			puts("YES");
			return 0;
		}
		if(d1>r&&d2>r&&d3>=abs(d1-d2)&&sqr(area(a[i],a[(i+1)%n],c))<=1ll*r*d3)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}