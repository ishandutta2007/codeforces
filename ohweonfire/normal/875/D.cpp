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

int n,a[200111],v[200111][20],mx[200111][20],lg[200111];
int qor(int l,int r)
{
	if(l>r)return 0;
	int len=lg[r-l+1];
	return v[l][len]|v[r-(1<<len)+1][len];
}
int qmx(int l,int r)
{
	if(l>r)return 0;
	int len=lg[r-l+1];
	return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
void getor(int v,int &lb,int &ub)
{
	int l=0,r=v,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(qor(mid,v)==a[v])r=mid;else l=mid;
	}
	lb=r;
	l=v;r=n+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(qor(v,mid)==a[v])l=mid;else r=mid;
	}
	ub=l;
}
void getmx(int v,int&lb,int&ub)
{
	int l=0,r=v,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(qmx(mid,v-1)<=a[v])r=mid;else l=mid;
	}
	lb=r;
	l=v;r=n+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(qmx(v+1,mid)<a[v])l=mid;else r=mid;
	}
	ub=l;
}
int main()
{
	for(int i=2;i<200111;i++)lg[i]=lg[i>>1]+1;
	get1(n);for(int i=1;i<=n;i++){get1(a[i]);v[i][0]=mx[i][0]=a[i];}
	for(int j=1;j<20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int nxt=i+(1<<j-1);
			if(nxt>n)v[i][j]=v[i][j-1];
			else v[i][j]=v[i][j-1]|v[nxt][j-1];
			if(nxt>n)mx[i][j]=mx[i][j-1];
			else mx[i][j]=max(mx[i][j-1],mx[nxt][j-1]);
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int l1,r1,l2,r2;
		getor(i,l1,r1);
		getmx(i,l2,r2);
		l1=max(l1,l2);r1=min(r1,r2);
		ans-=1ll*(i-l1+1)*(r1-i+1);
		ans+=1ll*(i-l2+1)*(r2-i+1);
	}
	printendl(ans);
	return 0;
}