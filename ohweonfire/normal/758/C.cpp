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

LL k;
int n,m,x,y;
LL cnt[111][111];
pii ord[23333];
int main()
{
	get2(n,m);get3(k,x,y);
	int tot=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)ord[tot++]=mp(i,j);
	for(int i=n-2;i>0;i--)for(int j=0;j<m;j++)ord[tot++]=mp(i,j);
	for(int i=0;i<tot;i++)cnt[ord[i].ff][ord[i].ss]+=k/tot;
	for(int i=0;i<k%tot;i++)
		cnt[ord[i].ff][ord[i].ss]++;
	LL mn=k,mx=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
	{
		mx=max(mx,cnt[i][j]);
		mn=min(mn,cnt[i][j]);
	}
	printf("%I64d %I64d %I64d\n",mx,mn,cnt[x-1][y-1]);
	return 0;
}