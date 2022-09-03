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
const int inf=1<<30;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;

int ch[1500111][2],cnt[1500111],rt,tot;
short c[1500111][31][2];
int getid(int&x)
{
	if(x)return x;
	return x=++tot;
}

int n,v[50111][31],st[50111][31],a[50111];LL m;
LL getcnt(int x)
{
	if(x<0)return 0;
	LL ret=0;
	for(int i=1;i<=n;i++)
	{
		int cur=rt;
		for(int j=30;j>=0&&cur;j--)
		{
			int nxt=((x>>j)&1)^v[i][j];
			if(((x>>j)&1)==0)ret+=cnt[ch[cur][nxt^1]];
			cur=ch[cur][nxt];
		}
		ret+=cnt[cur];
	}
	if(x==0)ret-=n;
	return ret>>1;
}
int getsum(int x)
{
	int ret=0;
	for(int i=tot;i>=1;i--)for(int j=0;j<31;j++)
	{
		c[i][j][0]+=c[ch[i][0]][j][0]+c[ch[i][1]][j][0];
		c[i][j][1]+=c[ch[i][0]][j][1]+c[ch[i][1]][j][1];
	}
	for(int i=1;i<=n;i++)
	{
		int cur=rt;
		for(int j=30;j>=0&&cur;j--)
		{
			int nxt=((x>>j)&1)^v[i][j];
			if(((x>>j)&1)==0)
			{
				ret=(ret+1ll*cnt[ch[cur][nxt^1]]*((x>>j)<<j))%mod;
				for(int j2=0;j2<=j;j2++)ret=(ret+(1ll<<j2)*c[ch[cur][nxt^1]][j2][v[i][j2]^1])%mod;
			}
			cur=ch[cur][nxt];
		}
		ret=(ret+1ll*cnt[cur]*x)%mod;
	}
	return (1ll*ret*(mod+1)/2)%mod;
}
int main()
{
	rt=1;tot=1;
	
	get2(n,m);
	for(int i=1;i<=n;i++)
	{
		int&tmp=a[i];
		get1(tmp);
		for(int j=0;j<31;j++)v[i][j]=(tmp>>j)&1;
		int cur=rt;
		for(int j=30;j>=0;j--)
		{
			cur=getid(ch[cur][v[i][j]]);
			c[cur][j][v[i][j]]++;
		}
		cnt[cur]++;
	}
	for(int i=tot;i>=1;i--)cnt[i]+=cnt[ch[i][0]]+cnt[ch[i][1]];
	LL l=0,r=2000000000ll,mid,ans;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(getcnt(mid)>=m)l=mid;
		else r=mid;
	}
	ans=(getsum(l+1)+1ll*(m-getcnt(l+1))%mod*l%mod)%mod;
	printendl(ans);
	return 0;
}