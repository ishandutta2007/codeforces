/*
	Name: More Queries to Array...
	Copyright: Junior Two Class Five NFLS
	Author: Eric Chen(OhWeOnFire)
	Date: 2015/8/23
	Description: Codeforces 266E
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)
#define hash orzYJZ
#define exp orzTZN
#define generate orzTBY
#define left orzMX
#define right orzYYT
#define sqr(x) ((x)*(x))
#define mem(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LF;
typedef pair<int,int> pii;

const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const double EPS=1e-10;

const int maxn=100005;
const int maxlog=20;
const LL mod=1000000007;

int pre[6][maxn],n,m;
int c[6][6];
struct Segment_TreeSS
{
	int pw;
	struct segment
	{
		int l,r,change,sum;
	} seg[maxn<<2];
	void init(int l,int r,int t)
	{
		seg[t].l=l;
		seg[t].r=r;
		seg[t].change=-1;
		seg[t].sum=0;
		if(l==r)return;
		int mid=l+r>>1;
		init(l,mid,t<<1);
		init(mid+1,r,t<<1|1);
	}
	void set(int ql,int qr,int t,int v)
	{
		if(seg[t].l==ql&&seg[t].r==qr)
		{
			seg[t].change=v;
			seg[t].sum=(int)(v*1ll*(pre[pw][qr]+mod-pre[pw][ql-1])%mod);
			return;
		}
		int mid=seg[t].l+seg[t].r>>1;
		if(seg[t].change!=-1)
		{
			seg[t<<1].change=seg[t<<1|1].change=seg[t].change;
			seg[t<<1].sum=int(seg[t].change*1ll*(pre[pw][mid]+mod-pre[pw][seg[t].l-1])%mod);
			seg[t<<1|1].sum=int(seg[t].change*1ll*(pre[pw][seg[t].r]+mod-pre[pw][mid])%mod);
			seg[t].change=-1;
		}
		if(qr<=mid)set(ql,qr,t<<1,v);
		else if(ql>mid)set(ql,qr,t<<1|1,v);
		else
		{
			set(ql,mid,t<<1,v);
			set(mid+1,qr,t<<1|1,v);
		}
		seg[t].sum=(seg[t<<1].sum+seg[t<<1|1].sum)%mod;
	}
	int query(int ql,int qr,int t)
	{
		if(seg[t].l==ql&&seg[t].r==qr)return seg[t].sum;
		int mid=seg[t].l+seg[t].r>>1;
		if(seg[t].change!=-1)
		{
			seg[t<<1].change=seg[t<<1|1].change=seg[t].change;
			seg[t<<1].sum=int(seg[t].change*1ll*(pre[pw][mid]+mod-pre[pw][seg[t].l-1])%mod);
			seg[t<<1|1].sum=int(seg[t].change*1ll*(pre[pw][seg[t].r]+mod-pre[pw][mid])%mod);
			seg[t].change=-1;
		}
		if(qr<=mid)return query(ql,qr,t<<1);
		else if(ql>mid)return query(ql,qr,t<<1|1);
		else return (query(ql,mid,t<<1)+query(mid+1,qr,t<<1|1))%mod;
	}
}sgt[6];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<6;i++)
	{
		sgt[i].init(1,n,1);
		sgt[i].pw=i;
		for(int j=0;j<=i;j++)if(j==0)c[i][j]=1;else c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	int l,r,x;
	for(int i=1;i<=n;i++)
	{
		int t=1;
		for(int j=0;j<6;j++)
		{
			pre[j][i]=(pre[j][i-1]+t)%mod;
			t=(t*1ll*(i+1))%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<6;j++)
			sgt[j].set(i,i,1,x);
	}
	char op[4];
	int pwl[6];
	while(m--)
	{
		scanf("%s%d%d%d",op,&l,&r,&x);
		if(op[0]=='?')
		{
			int ans=0,prod=1;
			for(int i=0;i<=x;i++)
			{
				ans+=c[x][i]*1ll*prod%mod*sgt[x-i].query(l,r,1)%mod;
				ans%=mod;
				prod=prod*1ll*(mod-l)%mod;
			}
			printf("%d\n",ans);
		}
		else
			for(int i=0;i<6;i++)sgt[i].set(l,r,1,x);
	}
	return 0;
}