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

const LL mod=1e9+7;

LL det(pii &a,pii &b){return 1ll*a.ff*b.ss-1ll*a.ss*b.ff;}
int n,cnt,px[1000111],py[1000111];
pii p[1000111];
LL area,ans,p1[1000111],p2[1000111],pre[1000111];
LL calc(int x,int y){return det(p[y],p[x])+pre[y]-pre[x];}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get2(p[i].ff,p[i].ss);
	reverse(p+1,p+n+1);for(int i=1;i<=n;i++)p[i+n]=p[i];
	
	for(int i=2;i<=n+n;i++)
	{
		pre[i]=pre[i-1]+det(p[i-1],p[i]);
		p1[i]=(p1[i-1]+det(p[i-1],p[i])%mod+mod)%mod;
		p2[i]=(p2[i-1]+p1[i])%mod;
	}
	for(int i=1;i<=n+n;i++)
	{
		px[i]=(px[i-1]+p[i].ff)%mod;
		py[i]=(py[i-1]+p[i].ss)%mod;
	}
	area=pre[n+1];
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		while(calc(i,cur)<=area/2)cur++;//  [i+2,cur)
		cnt+=cur-i-2;if(cnt>=mod)cnt-=mod;
		ans=(ans+p2[cur-1]-p2[i+1]+mod)%mod;
		ans=(ans-p1[i]*(cur-i-2)%mod+mod)%mod;
		ans=(ans+1ll*(px[cur-1]-px[i+1]+mod)*p[i].ss)%mod;
		ans=(ans-1ll*(py[cur-1]-py[i+1]+mod)*p[i].ff%mod+mod)%mod;
//		for(int j=i+2;j<cur;j++)ans=(ans+calc(i,j))%mod;
	}
	ans=(p1[n+1]*cnt%mod-ans*2+mod*2)%mod;
	printendl(ans);
	return 0;
}