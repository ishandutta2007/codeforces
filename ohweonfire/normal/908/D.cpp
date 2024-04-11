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

const int mod=1e9+7;
int power(int x,int y){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}

struct frac
{
	int a,b;
	frac(int a=0,int b=1){this->a=a;this->b=b;}
	frac operator *(const frac&x)const{return frac(1ll*a*x.a%mod,1ll*b*x.b%mod);}
	frac operator /(int x)const{return frac(a,1ll*b*x%mod);}
	frac operator *(int x)const{return frac(1ll*a*x%mod,b);}
	frac operator +(const frac&x)const{return frac((1ll*a*x.b+1ll*b*x.a)%mod,1ll*b*x.b%mod);}
};

frac dp[1111][2111];
int k,pa,pb;
int main()
{
	get3(k,pa,pb);
	dp[1][0]=frac(1,1);frac ans;
	for(int i=1;i<=k;i++)for(int j=0;j<k;j++)
	{
		dp[i+1][j]=dp[i+1][j]+dp[i][j]*pa/(pa+pb);
		dp[i][i+j]=dp[i][i+j]+dp[i][j]*pb/(pa+pb);
	}
	for(int i=1;i<=k;i++)for(int j=k-i;j<k;j++)
	{
		if(i==k)ans=ans+dp[i][j]*(frac(i+j,1)+frac(pa,pb));
		else if(i+j>=k)ans=ans+dp[i][j]*(i+j)*pb/(pa+pb);
	}
	printf("%d\n",1ll*ans.a*power(ans.b,mod-2)%mod);
	return 0;
}