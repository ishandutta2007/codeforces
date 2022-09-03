//  This code is written by Eric Chen ( OhWeOnFire ).
//  Don't copy my code, because my coding style is easy to recognize.
//  I hope my code will get 'Accepted'!

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)
#define hash orzYJZ
#define exp orzTZN
#define generate orzTBY
#define next orzMX
#define sqr(x) ((x)*(x))
#define mem(x,y) memset((x),(y),sizeof(x))
#define abs(x) ((x)>0?(x):(-x))
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
#define printspace(a) print_int(a),putchar(' ')

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LF;
typedef pair<int,int> pii;

const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const double EPS=1e-10;

namespace IOSpace
{
	void get_int(int &x)
	{
		char t=getchar();
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void get_int(LL &x)
	{
		char t=getchar();
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void print_int(int x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
	void print_int(LL x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
}
using namespace IOSpace;

const int maxn=105;
const int maxlog=20;
const LL mod=1000000007;
bool use[3][105];
int n,k,x,y,qx[305],qy[305],front,rear;
char s[3][105];
void add(int x,int y,int dir)
{
	x+=dir;
	if(x>=n||x<0)return;
	if(s[x][y]!='.')return;
	if(s[x][y+1]!='.')return;
	if(s[x][y+2]!='.')return;
	if(use[x][y+2])return;
	use[x][y+2]=true;
	qx[rear]=x;
	qy[rear++]=y+2;
}
void solve()
{
	get2(n,k);
	for(int i=0;i<3;i++)
	{
		scanf("%s",s[i]);
		for(int j=n;j<105;j++)s[i][j]='.';
	}
	qx[0]=(s[1][0]=='s')+(s[2][0]=='s')*2;
	qy[0]=0;
	memset(use,0,sizeof(use));
	front=0;rear=1;
	while(front!=rear)
	{
		x=qx[front];
		y=qy[front++];
		if(y>=n)
		{
			puts("YES");
			return ;
		}
		if(s[x][y+1]!='.')continue;
		y++;
		add(x,y,-1);
		add(x,y,0);
		add(x,y,1);
	}
	puts("NO");
}
int main()
{
	int T;
	get1(T);
	while(T--)solve();
	return 0;
}
/*
4
16 4
...AAAAA........
s.BBB......CCCCC
........DDDDD...
16 4
...AAAAA........
s.BBB....CCCCC..
.......DDDDD....
10 4
s.ZZ......
.....AAABB
.YYYYYY...
10 4
s.ZZ......
....AAAABB
.YYYYYY...
*/