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

struct graph
{
	bitset<511>c1[511],c2[511];
	void set(int x,int y)
	{
		c1[x].set(y);
		c2[y].set(x);
	}
}c1[70],c2[70],cur,tmp;
int n,m;
graph comb(graph &a,graph &b)
{
	graph ret;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if((a.c1[i]&b.c2[j]).count())
			ret.set(i,j);
	}
	return ret;
}
bool check(graph&a)
{
	return (a.c1[1].count()>0);
}
bool print(graph&a)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)printf("%d ",a.c1[i].test(j));
		puts("");
	}
	puts("");
}
int main()
{
	get2(n,m);
	for(int i=0,u,v,w;i<m;i++)
	{
		get3(u,v,w);
		if(w==0)
			c1[0].set(u,v);
		else c2[0].set(u,v);
	}
	for(int i=1;i<60;i++)
	{
		c1[i]=comb(c1[i-1],c2[i-1]);
		c2[i]=comb(c2[i-1],c1[i-1]);
	}
//	print(c1[1]);
	LL ans=0;bool flag=0;
	cur.set(1,1);
	for(int i=59;i>=0;i--)
	{
		if(!flag)tmp=comb(cur,c1[i]);
		else tmp=comb(cur,c2[i]);
		if(check(tmp))
		{
			flag^=1;
			cur=tmp;
			ans+=1ll<<i;
		}
	}
	if(ans>=1000000000000000000ll)puts("-1");
	else printendl(ans);
	return 0;
}