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

const int maxn=100111;
int sa[maxn],t[maxn],t2[maxn],c[maxn],n,lcp[maxn],rk[maxn];
char s[maxn];
void construct_sa(int m=256)
{
	int *x=t,*y=t2;
	for(int i=0;i<m;i++)c[i]=0;
	for(int i=0;i<n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<m;i++)c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k;i<n;i++)y[p++]=i;
		for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
		for(int i=0;i<m;i++)c[i]=0;
		for(int i=0;i<n;i++)c[x[y[i]]]++;
		for(int i=1;i<m;i++)c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(int i=1;i<n;i++)
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
		if(p>=n)break;
		m=p;
	}
}
void construct_lcp()
{
	int k=0;
	for(int i=0;i<n;i++)rk[sa[i]]=i;
	for(int i=0;i<n-1;i++)
	{
		if(k)k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k])k++;
		lcp[rk[i]]=k;
	}
}
struct table
{
	pii v[20][1000111];
	int lg2[1000111],n;
	void construct(int n,int *a)
	{
		for(int i=2;i<1000111;i++)lg2[i]=lg2[i>>1]+1;
		this->n=n;
		for(int i=1;i<=n;i++)v[0][i]=mp(a[i],i);
		for(int i=1;i<20;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int nxt=j+(1<<i-1);
				if(nxt>n)v[i][j]=v[i-1][j];
				else v[i][j]=max(v[i-1][j],v[i-1][nxt]);
			}
		}
	}
	pii query(int l,int r)
	{
		int len=lg2[r-l+1];
		return max(v[len][l],v[len][r-(1<<len)+1]);
	}
}m1;
int stk[100111],top,cnt[100111];
LL sum[100111];
int main()
{
	scanf("%s",s);
	n=strlen(s)+1;
	construct_sa();
	construct_lcp();n--;
	LL ans=1ll*n*(n+1)/2;
	for(int i=2;i<=n;i++)
	{
		int all=1;
		while(top&&lcp[stk[top]]>=lcp[i])
		{
			all+=cnt[top];
			top--;
		}
		stk[++top]=i;
		cnt[top]=all;
		sum[top]=sum[top-1]+1ll*cnt[top]*lcp[i];
		ans+=sum[top];
	}
	printendl(ans);
	return 0;
}