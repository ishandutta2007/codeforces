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

const uLL base=1000000007;

uLL power[200111],pre[200111];
uLL calhash(int x,int y){return (pre[y]-pre[x-1])*power[200100-x];}
int m,a[200111],is[200111],id[200111],sa[200111],n,k,st[100111],ed[100111];
int lcp(int x,int y)
{
	int l=0,r=m-max(x,y)+2,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(calhash(x,x+mid-1)==calhash(y,y+mid-1))l=mid;
		else r=mid;
	}
	return l;
}
bool cmp(int x,int y)
{
	int t=lcp(x,y);
	return a[x+t]<a[y+t];
}
char s[100111];

int far[200111],cnt[200111];

bool check(int x,int len)
{
	if(len==0)return true;
	int l=0,r=id[x],mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(lcp(x,sa[mid])>=len)r=mid;
		else l=mid;
	}
//	printf("left= %d\n",r);
	int t=far[r];
	if(t>m)return false;
	return lcp(x,sa[t])>=len;
}
int main()
{
	power[0]=1;for(int i=1;i<200111;i++)power[i]=power[i-1]*base;
	get2(n,k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		st[i]=m+1;
		for(int j=1;s[j];j++)
		{
			a[++m]=s[j]-'a'+1;
			is[m]=i;
		}
		ed[i]=m;
		a[++m]=26+i;
	}
	for(int i=1;i<=m;i++)pre[i]=pre[i-1]+a[i]*power[i];
	for(int i=1;i<=m;i++)sa[i]=i;
	
	sort(sa+1,sa+m+1,cmp);for(int i=1;i<=m;i++)id[sa[i]]=i;
	int cur=0,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<=m&&cur<k)
		{
			r++;
			if(cnt[is[sa[r]]]==0)cur++;
			cnt[is[sa[r]]]++;
		}
//		if(r<i)puts("Baojing");
		far[i]=r;
		cnt[is[sa[i]]]--;
		if(cnt[is[sa[i]]]==0)cur--;
	}
//	puts("a");for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
//	puts("sa");for(int i=1;i<=m;i++)printf("%d ",sa[i]);puts("");
//	puts("fa");for(int i=1;i<=m;i++)printf("%d ",far[i]);puts("");
	
	for(int i=1;i<=n;i++)
	{
//		printf("i= %d\n",i);
		LL ans=0;
		int cur=st[i];
		for(int j=st[i];j<=ed[i];j++)
		{
			while(cur<=ed[i]&&check(j,cur-j+1))cur++;
//			printf("St= %d Ed= %d\n",j-st[i]+1,cur-st[i]+1);
			ans+=cur-j;
		}
		printf("%I64d ",ans);
	}
	return 0;
}