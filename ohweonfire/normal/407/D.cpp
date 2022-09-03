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

int n,m,a[453][453],r[453][453],l[453][453],mxl[453][453],ans;

int lx[160111],ql[453],qr[453],lf,lr,rf,rr;
int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)get1(a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)mxl[i][j]=1;
	for(int i1=n;i1>=1;i1--)
	{
		memset(lx,-1,sizeof(lx));
		for(int j=1;j<=m;j++)
		{
			if(lx[a[i1][j]]!=-1)l[i1][j]=lx[a[i1][j]];
			else l[i1][j]=0;
			lx[a[i1][j]]=j;
			for(int i=i1+1;i<=n;i++)
			{
				l[i][j]=l[i-1][j];
				if(lx[a[i][j]]!=-1)l[i][j]=max(l[i][j],lx[a[i][j]]);
			}
		}
		memset(lx,-1,sizeof(lx));
		for(int j=m;j>=1;j--)
		{
			if(lx[a[i1][j]]!=-1)r[i1][j]=lx[a[i1][j]];
			else r[i1][j]=m+1;
			lx[a[i1][j]]=j;
			for(int i=i1+1;i<=n;i++)
			{
				r[i][j]=r[i-1][j];
				if(lx[a[i][j]]!=-1)r[i][j]=min(r[i][j],lx[a[i][j]]);
			}
		}
		for(int i=i1;i<=n;i++)
		{
			lf=lr=rf=rr=0;
			for(int j=1;j<=m;j++)
			{
				while(lf!=lr&&l[i][ql[lr-1]]<=l[i][j])lr--;ql[lr++]=j;
				while(rf!=rr&&r[i][qr[rr-1]]>=r[i][j])rr--;qr[rr++]=j;
				mxl[i][j]=max(mxl[i][j-1],mxl[i][j]);
				while(mxl[i][j]<=j)
				{
					while(lf!=lr&&ql[lf]<mxl[i][j])lf++;
					while(rf!=rr&&qr[rf]<mxl[i][j])rf++;
					if(lf!=lr&&l[i][ql[lf]]>=mxl[i][j])mxl[i][j]++;
					else if(rf!=rr&&r[i][qr[rf]]<=j)mxl[i][j]++;
					else break;
				}
				ans=max(ans,(i-i1+1)*(j-mxl[i][j]+1));
			}
		}
	}
	printendl(ans);
	return 0;
}