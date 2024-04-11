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

int n,m,k;
char s[1111][1111];
int x[300111],y[300111],xx[300111],yy[300111],tp[300111];

LL a[1111][1111][26];
inline LL query(int x1,int y1,int x2,int y2,int t){return a[x2][y2][t]+a[x1-1][y1-1][t]-a[x1-1][y2][t]-a[x2][y1-1][t];}
LL sum[1111][1111];
inline LL query(int x1,int y1,int x2,int y2){return sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1];}
int main()
{
	get3(n,m,k);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=k;i++)
	{
		char tmp[5];int &t=tp[i];
		get2(x[i],y[i]);get2(xx[i],yy[i]);scanf("%s",tmp);t=tmp[0]-'a';
		a[x[i]][y[i]][t]++;a[x[i]][yy[i]+1][t]--;a[xx[i]+1][y[i]][t]--;a[xx[i]+1][yy[i]+1][t]++;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int t=0;t<26;t++)a[i][j][t]+=a[i][j-1][t]+a[i-1][j][t]-a[i-1][j-1][t];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		LL ss=0;for(int t=0;t<26;t++)ss+=a[i][j][t];
		a[i][j][s[i][j]-'a']+=k-ss;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		for(int t=0;t<26;t++)sum[i][j]+=abs(s[i][j]-'a'-t)*a[i][j][t];
		sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int t=0;t<26;t++)a[i][j][t]+=a[i][j-1][t]+a[i-1][j][t]-a[i-1][j-1][t];
	LL ans=Linf,cur;
	for(int i=1;i<=k;i++)
	{
		cur=sum[n][m]-query(x[i],y[i],xx[i],yy[i]);
		for(int j=0;j<26;j++)
			cur+=query(x[i],y[i],xx[i],yy[i],j)*abs(j-tp[i]);
		ans=min(ans,cur);
	}
	printendl(ans);
	return 0;
}