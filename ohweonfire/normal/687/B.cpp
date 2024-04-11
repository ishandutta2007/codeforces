//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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

int n,k,dv[1000111],cnt,mx[1000111];
map<int,int> c;
int main()
{
	for(int i=2;i<1000111;i++)
		for(int j=i;j<1000111;j+=i)
			if(dv[j]==0)
				dv[j]=i;
	get2(n,k);
	for(int i=1,x;i<=n;i++)
	{
		get1(x);
		c.clear();
		while(x!=1)
		{
			c[dv[x]]++;
			x/=dv[x];
		}
		for(map<int,int>::iterator it=c.begin();it!=c.end();it++)
			mx[it->ff]=max(mx[it->ff],it->ss);
	}
	c.clear();
	while(k!=1)
	{
		c[dv[k]]++;
		k/=dv[k];
	}
	for(map<int,int>::iterator it=c.begin();it!=c.end();it++)
		if(mx[it->ff]<(it->ss))
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}