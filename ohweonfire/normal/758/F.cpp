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

int l,r,n;
LL getpw(int a,int b)
{
	LL ret=1;
	for(int i=1;i<=b;i++)ret*=a;
	return ret;
}
int main()
{
	LL ans=0;
	get3(n,l,r);
	if(n==1)ans=r-l+1;
	else if(n==2)ans=1ll*(r-l+1)*(r-l);
	else
	{
		int ub;
		
		for(int a=1;a*a<=r;a++)
		{
			int cur,p=1;
			for(cur=1; cur<n;cur++)
			{
				if(1ll*p*a>r)break;
				p*=a;
			}
			if(cur==n)ub=a;
		}
//		printf("ub= %d\n",ub);
		for(int a=1;a<=ub;a++)
			for(int b=a+1;b<=ub;b++)
			{
				if(__gcd(a,b)>1)continue;
				LL mn=getpw(a,n-1),mx=getpw(b,n-1);//mn*k>=l mx*k<=r
				int ll=(l+mn-1)/mn,rr=r/mx;
//				printf("%d %d = %d %d\n",a,b,ll,rr);
				ans+=2ll*max(0,rr-ll+1);
			}
	}
	printendl(ans);
	return 0;
}