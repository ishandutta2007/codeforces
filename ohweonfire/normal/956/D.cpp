// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
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
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int bit[200111];
void add(int x){for(;x<200111;x+=x&-x)bit[x]++;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}

pii a[100111],b[100111];
vector<pii> vs;
bool cmp(const pii&a,const pii&b){return 1ll*a.ff*b.ss<1ll*a.ss*b.ff;}

int n,w,x[100111],v[100111],l[100111],r[100111];
int main()
{
	get2(n,w);
	for(int i=1;i<=n;i++)
	{
		get2(x[i],v[i]);
		bool flag=0;
		if(x[i]<0)x[i]=-x[i];else{flag=1;v[i]=-v[i];}
		a[i]=mp(x[i],v[i]+w);
		b[i]=mp(x[i],v[i]-w);
		if(flag)swap(a[i],b[i]);
		vs.pb(a[i]);vs.pb(b[i]);
	}
	sort(vs.begin(),vs.end(),cmp);
	for(int i=1,l,r;i<=n;i++)
	{
		l=lower_bound(vs.begin(),vs.end(),a[i],cmp)-vs.begin()+1;
		r=lower_bound(vs.begin(),vs.end(),b[i],cmp)-vs.begin()+1;
		a[i]=mp(l,-r);
	}
	sort(a+1,a+n+1);
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i].ss=-a[i].ss;
		ans+=i-1-query(a[i].ss-1);
		add(a[i].ss);
	}
	printendl(ans);
	return 0;
}