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

const int mod=998244353;
int power(int x,int y){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}
struct frac
{
	int a,b;
	frac(int a=0,int b=1){this->a=a;this->b=b;}
	frac operator *(const frac&x)const{return frac(1ll*a*x.a%mod,1ll*b*x.b%mod);}
	frac operator /(const frac&x)const{return frac(1ll*a*x.b%mod,1ll*b*x.a%mod);}
	frac operator /(int x)const{return frac(a,1ll*b*x%mod);}
	frac operator *(int x)const{return frac(1ll*a*x%mod,b);}
	frac operator +(const frac&x)const{return frac((1ll*a*x.b+1ll*b*x.a)%mod,1ll*b*x.b%mod);}
	frac operator -(const frac&x)const{return frac((1ll*a*x.b+1ll*b*(mod-x.a))%mod,1ll*b*x.b%mod);}
};
frac p,np,pw1[2333],pw2[2333],prob[2333][2333],f[2333],ans[2333];
int n,a,b;
int main()
{
	get3(n,a,b);p=frac(a,b);np=frac(b-a,b);
	pw1[0]=pw2[0]=frac(1,1);for(int i=1;i<2333;i++){pw1[i]=pw1[i-1]*p;pw2[i]=pw2[i-1]*np;}
	prob[0][0]=frac(1,1);
	for(int i=0;i<n;i++)for(int j=0;j<=i;j++)
	{
		prob[i+1][j]=prob[i+1][j]+prob[i][j]*pw1[j];
		prob[i+1][j+1]=prob[i+1][j+1]+prob[i][j]*pw2[i-j];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=frac(1,1);
		for(int j=1;j<i;j++)f[i]=f[i]-f[j]*prob[i][j];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)ans[i]=ans[i]+(ans[j]+ans[i-j]+frac((1ll*j*(j-1)/2+1ll*j*(i-j))%mod))*f[j]*prob[i][j];
		ans[i]=ans[i]+frac(1ll*i*(i-1)/2%mod)*f[i];
		ans[i]=ans[i]/(frac(1)-f[i]);
	}
	printf("%d\n",1ll*ans[n].a*power(ans[n].b,mod-2)%mod);
	return 0;
}