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

int p[1000111],v[1000111],mx[1000111],mx2[1000111],n;
void add(int x)
{
	int f=p[x];
	if(mx[f]==x);
	else if(mx2[f]==x)
	{
		if(v[mx[f]]<v[x])swap(mx[f],mx2[f]);
	}
	else if(v[mx[f]]<v[x])
	{
		mx2[f]=mx[f];
		mx[f]=x;
	}
	else if(v[mx2[f]]<v[x])mx2[f]=x;
	int nv;
	if(f==1)nv=v[mx[1]];
	else nv=v[mx[f]]+(v[mx[f]]==v[mx2[f]]);
	if(nv!=v[f])
	{
		v[f]=nv;
		if(f>1)add(f);
	}
}
int main()
{
	get1(n);n++;
	for(int i=2;i<=n;i++)
		get1(p[i]);
	for(int i=2;i<=n;i++)
	{
		v[i]=1;
		add(i);
		printf("%d\n",v[1]);
	}
	return 0;
}