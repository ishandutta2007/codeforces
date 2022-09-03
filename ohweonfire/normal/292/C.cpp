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

const int maxlog=20;
const LL mod=1000000007;
const int maxn=253004;

int ans[maxn][4],cnt;
int p[14],len,cur[4];
void gen_ip(int ip,int pos)
{
	if(pos==len+1&&ip==4)
	{
		ans[cnt][0]=cur[0];ans[cnt][1]=cur[1];ans[cnt][2]=cur[2];ans[cnt++][3]=cur[3];
		return;
	}
	if(pos==len+1||ip==4)return;
	if(pos+4-ip>len+1)return;
	if(pos+(4-ip)*3<=len)return;
	if(p[pos]==0)
	{
		cur[ip]=0;
		gen_ip(ip+1,pos+1);
		return;
	}
	int tmp=0;
	for(int i=pos;i<=len;i++)
	{
		tmp=tmp*10+p[i];
		if(tmp>=256)break;
		cur[ip]=tmp;
		gen_ip(ip+1,i+1);
	}
}
int tar,n,dig[10];
void gen_p(int l,int r,int mask)
{
	if(l>r)
	{
		if(mask==tar)gen_ip(0,1);
		return;
	}
	for(int i=0;i<n;i++)
	{
		p[l]=p[r]=dig[i];
		gen_p(l+1,r-1,mask|(1<<i));
	}
}
int main()
{
	get1(n);
	for(int i=0;i<n;i++)get1(dig[i]);
	sort(dig,dig+n);
	tar=1<<n;tar--;
	for(len=4;len<=12;len++)gen_p(1,len,0);
	printendl(cnt);
	for(int i=0;i<cnt;i++)printf("%d.%d.%d.%d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	return 0;
}
/*
6
0 1 2 9 8 7
*/