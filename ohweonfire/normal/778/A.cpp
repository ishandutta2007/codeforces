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

char s[200111],t[200111],ss[200111];
bool use[200111];
int p[200111],n,m;
bool check(int x)
{
	memset(use,0,sizeof(use));
	int nn=0;
	for(int i=0;i<x;i++)use[p[i]]=1;
	for(int i=0;i<n;i++)if(!use[i])ss[nn++]=s[i];
	int cur=0;
	for(int i=0;i<m;i++)
	{
		while(cur<nn&&ss[cur]!=t[i])cur++;
		if(cur==nn)return false;
		cur++;
	}
	return true;
}
int main()
{
	scanf("%s%s",s,t);
	n=strlen(s);m=strlen(t);
	int l=0,r=n+1;
	for(int i=0;i<n;i++)
	{
		get1(p[i]);
		p[i]--;
	}
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}