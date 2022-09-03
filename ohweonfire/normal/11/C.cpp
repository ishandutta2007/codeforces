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

const int maxn=253;
const int maxlog=20;
const LL mod=1000000007;
char s[maxn][maxn];
int n,m,ans,cnt;
pii q[maxn*maxn],down;
int use[maxn][maxn],kk;
void dfs(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||s[x][y]=='0'||use[x][y])return;
	use[x][y]=kk;++cnt;
	down=max(down,mp(x,y));
	dfs(x-1,y-1);
	dfs(x-1,y+1);
	dfs(x+1,y-1);
	dfs(x+1,y+1);
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}
void solve()
{
	ans=kk=0;
	get2(n,m);
	mem(use,0);
	int len,ok;
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)if(!use[i][j]&&s[i][j]=='1')
		{
			kk++;
			cnt=0;
			down=mp(-1,-1);
			dfs(i,j);
			if(down.ff==i)continue;
			if(down.ss==j&&((down.ff-i)&1)==0)
			{
				len=down.ff-i;if(len<<1!=cnt)continue;ok=1;
				for(int ii=0;ii+ii<=len&&ok;ii++)
				{
					ok&=(j-ii>=0&&use[i+ii][j-ii]==kk&&use[down.ff-ii][j-ii]==kk);
					ok&=(j+ii<m&&use[i+ii][j+ii]==kk&&use[down.ff-ii][j+ii]==kk);
				}
				ans+=ok;
			}
			else if(down.ss-j==down.ff-i)
			{
				len=down.ff-i;if(len<<2!=cnt)continue;ok=1;
				for(int ii=0;ii<=len&&ok;ii++)
				{
					ok&=use[i][j+ii]==kk;
					ok&=use[down.ff][j+ii]==kk;
					ok&=use[i+ii][j]==kk;
					ok&=use[i+ii][down.ss]==kk;
				}
				ans+=ok;
			}
		}
	printf("%d\n",ans);
}
int main()
{
	int T;get1(T);
	while(T--)solve();
	return 0;
}
/*
3
8 8
00010001
00101000
01000100
10000010
01000100
00101000
11010011
11000011
10 10
1111111000
1000001000
1011001000
1011001010
1000001101
1001001010
1010101000
1001001000
1000001000
1111111000
12 11
11111111111
10000000001
10111111101
10100000101
10101100101
10101100101
10100000101
10100000101
10111111101
10000000001
11111111111
00000000000
*/