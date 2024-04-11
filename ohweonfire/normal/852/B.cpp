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

const int mod=1e9+7;
int n,l,m,va[1000111],vb[1000111],vc[1000111];
struct matrix
{
	int a[111][111];
	void clear(int x)
	{
		for(int i=0;i<m;i++)for(int j=0;j<m;j++)a[i][j]=(i==j)*x;
	}
}tran;
matrix operator *(matrix a,matrix b)
{
	matrix ret;ret.clear(0);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)for(int k=0;k<m;k++)
		ret.a[i][j]=(ret.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%mod;
	return ret;
}
matrix mul(matrix x,int y)
{
	matrix ret;ret.clear(1);
	while(y)
	{
		if(y&1)ret=ret*x;
		x=x*x;
		y>>=1;
	}
	return ret;
}

int ca[111],cb[111],cc[111];
int main()
{
	get3(n,l,m);
	for(int i=1;i<=n;i++)get1(va[i]);
	for(int i=1;i<=n;i++)get1(vb[i]);
	for(int i=1;i<=n;i++)get1(vc[i]);
	tran.clear(0);
	for(int i=1;i<=n;i++)ca[va[i]%m]++;
	for(int i=1;i<=n;i++)cb[vb[i]%m]++;
	for(int i=1;i<=n;i++)cc[(vc[i]+vb[i])%m]++;
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)tran.a[i][(i+j)%m]=cb[j];
	tran=mul(tran,l-2);
	int ans=0;
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)for(int k=0;k<m;k++)
	{
		if((i+j+k)%m)continue;
		ans=(ans+1ll*ca[i]*cc[k]%mod*tran.a[i][(i+j)%m])%mod;
	}
	printendl(ans);
	return 0;
}