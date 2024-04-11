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
}m;
int n,a[1000111];
LL ans;
void solve(int l,int r)
{
	if(l>r)return;
	int mx=m.query(l,r).ss;
	ans+=1ll*a[mx]*(mx-l+1)*(r-mx+1);
	solve(l,mx-1);
	solve(mx+1,r);
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	m.construct(n,a);
	solve(1,n);
	for(int i=1;i<=n;i++)a[i]=-a[i];
	m.construct(n,a);
	solve(1,n);
	printendl(ans);
	return 0;
}