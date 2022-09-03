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

int n,a[500111],pre[500111],suf[500111];
set<int> v;
LL ans;
void del(int x)
{
	ans+=min(a[pre[x]],a[suf[x]]);
	v.erase(x);
	if(pre[x]!=1)
	{
		if(a[pre[pre[x]]]>=a[pre[x]]&&a[suf[x]]>=a[pre[x]])
			v.insert(pre[x]);
		else v.erase(pre[x]);
	}
	if(suf[x]!=n)
	{
		if(a[suf[suf[x]]]>=a[suf[x]]&&a[pre[x]]>=a[suf[x]])
			v.insert(suf[x]);
		else v.erase(suf[x]);
	}
	suf[pre[x]]=suf[x];
	pre[suf[x]]=pre[x];
}
int main()
{
	get1(n);
	if(n<=2)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=i-1;
		suf[i]=i+1;
		get1(a[i]);
	}
	for(int i=2;i<n;i++)if(a[i]<=a[i-1]&&a[i]<=a[i+1])v.insert(i);
	while(!v.empty())
	{
		int id=*v.begin();
		del(id);
	}
	int cur=suf[1];
	while(cur!=n)
	{
		ans+=min(a[pre[cur]],a[suf[cur]]);
		cur=suf[cur];
	}
	printendl(ans);
	return 0;
}