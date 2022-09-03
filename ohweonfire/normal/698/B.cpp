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

const int maxn=200111;
int a[maxn],n,id[maxn],cyc[maxn],cnt;
vector<pii> hehe;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)
	{
		int cur=i;
		cnt++;
		while(id[cur]==0)
		{
			id[cur]=cnt;
			cur=a[cur];
		}
		if(id[cur]==cnt)
		{
			int sz=1,tmp=cur;
			cur=a[cur];
			while(cur!=tmp)
			{
				sz++;
				cur=a[cur];
			}
			hehe.pb(mp(sz,cur));
		}
	}
	sort(hehe.begin(),hehe.end());
	for(int i=(int)hehe.size()-1;i>0;i--)
		a[hehe[i].ss]=hehe[i-1].ss;
	int ans=hehe.size();
	if(hehe.size()>0&&hehe[0].ff==1)
		ans--;
	else if(hehe.size()>0)
		a[hehe[0].ss]=hehe[0].ss;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}