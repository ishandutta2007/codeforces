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
const uLL base=43;

char s[maxn],t[maxn];
int n;
uLL power[maxn],hs[maxn];
uLL calhash(int x,int y){return (hs[y]-hs[x-1])*power[maxn-1-x];}
int lcp(int x,int y)
{
	int l=0,r=min(n-x+1,n-y+1)+1,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(calhash(x,x+mid-1)==calhash(y,y+mid-1))l=mid;
		else r=mid;
	}
	return l;
}
int lcs(int x,int y)
{
	int l=0,r=min(x,y)+1,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(calhash(x-mid+1,x)==calhash(y-mid+1,y))l=mid;
		else r=mid;
	}
	return l;
}
bool cmp(int x,int y)
{
	int t=lcp(x,y);
	return s[x+t]<s[y+t];
}

int ind[maxn],val[maxn],f[maxn],sz[maxn],mxsz,ord[maxn];
bool cmp2(int x,int y){return val[x]>val[y];}
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void un(int x,int y)
{
	x=gf(x);y=gf(y);if(x==y)return;
	f[x]=y;
	sz[y]+=sz[x];
	mxsz=max(mxsz,sz[y]);
}
int main()
{
	power[0]=1;for(int i=1;i<maxn;i++)power[i]=power[i-1]*base;
	scanf("%d%s%s",&n,s+1,t+1);
	reverse(s+1,s+n+1);reverse(t+1,t+n+1);
	for(int i=1;i<=n;i++)hs[i]=hs[i-1]+power[i]*(s[i]-'a'+1);
	
	int tot=0;
	LL ans=0;
	for(int i=1;i<=n;i++)if(t[i]=='0'){ind[++tot]=i;ans=max(ans,n-i+1ll);}
	sort(ind+1,ind+tot+1,cmp);
	if(tot>1)
	{
		for(int i=1;i<tot;i++){val[i]=lcp(ind[i],ind[i+1]);ord[i]=i;}
		sort(ord+1,ord+tot,cmp2);
		mxsz=1;
		for(int i=1;i<tot;i++){f[i]=i;sz[i]=1;}
//		for(int i=1;i<=tot;i++)printf("i= %d ind= %d val= %d\n",i,ind[i],val[i]);
		for(int i=1;i<tot;i++)
		{
			int x=ord[i];
			if(val[x-1]>=val[x])un(x-1,x);if(val[x+1]>=val[x])un(x+1,x);
			ans=max(ans,1ll*val[x]*(mxsz+1));
		}
	}
	printendl(ans);
	return 0;
}