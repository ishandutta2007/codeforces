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

const int mod=1e9+9;
int power(int x,int y){x%=mod;int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}

int n,a,b,k;
char s[100111];
int main()
{
	get1(n);get3(a,b,k);
	scanf("%s",s);
	
	int ans=0,coef=1ll*power(b,k)*power(power(a,k),mod-2)%mod;
	int sum;
	if(coef!=1)sum=1ll*(mod+1-power(coef,(n+1)/k))*power(mod+1-coef,mod-2)%mod;
	else sum=(n+1)/k;
	
	for(int i=0;i<k;i++)
	{
		int tmp=1ll*power(a,n-i)*power(b,i)%mod;
		if(s[i]=='+')ans=(ans+tmp)%mod;
		else ans=(ans-tmp+mod)%mod;
	}
	ans=1ll*ans*sum%mod;
	printf("%d\n",ans);
	return 0;
}