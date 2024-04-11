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

int a,b,ww;

double calc(double a1)
{
	double a2=sqrt(1.0*ww*ww-a1*a1);//  (-b,a1-a) (a2-b,-a)
	double dis=(-a1*a2+a1*b+a2*a)/(1.0*ww);
	return max(dis,0.0);
}
int main()
{
	get3(a,b,ww);
	double l=0,r=1e10,m1,m2;
	for(int i=1;i<=1000;i++)
	{
		m1=calc((l+l+r)/3);
		m2=calc((l+r+r)/3);
		if(m1>m2)l=(l+l+r)/3;
		else r=(l+r+r)/3;
	}
	r=calc(r);
	if(ww<=b)r=max(r,a*1.0);
	if(ww<=a)r=max(r,b*1.0);
	r=min(r,ww*1.0);
	if(r<1e-10)puts("My poor head =(");
	else printf("%.10lf\n",r);
	return 0;
}