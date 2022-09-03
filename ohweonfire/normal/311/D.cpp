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

const int mod=95542721;

int n,a[100111],q;

const int cyc=48;
int sum[300111][50],delta[300111],tsum[50];
#define lson (t<<1)
#define rson ((t<<1)|1)
void build(int l,int r,int t=1)
{
	if(l==r)
	{
		sum[t][0]=a[l];
		for(int i=1;i<cyc;i++)sum[t][i]=1ll*sum[t][i-1]*sum[t][i-1]%mod*sum[t][i-1]%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,lson);
	build(mid+1,r,rson);
	for(int i=0;i<cyc;i++)sum[t][i]=(sum[lson][i]+sum[rson][i])%mod;
}
void add(int l,int r,int tl,int tr,int t)
{
	if(l<=tl&&tr<=r)
	{
		delta[t]++;if(delta[t]==cyc)delta[t]=0;
		int tmp=sum[t][0];
		for(int i=0;i<cyc-1;i++)sum[t][i]=sum[t][i+1];
		sum[t][cyc-1]=tmp;
		return;
	}
	int mid=(tl+tr)>>1;
	if(l<=mid)add(l,r,tl,mid,lson);
	if(r>mid)add(l,r,mid+1,tr,rson);
	for(int i=0;i<cyc;i++)
	{
		int ti=i+delta[t];if(ti>=cyc)ti-=cyc;
		sum[t][i]=sum[lson][ti]+sum[rson][ti];
		if(sum[t][i]>=mod)sum[t][i]-=mod;
	}
}
int query(int l,int r,int tl,int tr,int t,int p=0)
{
	if(l<=tl&&tr<=r)return sum[t][p];
	p+=delta[t];if(p>=cyc)p-=cyc;
	int mid=(tl+tr)>>1,ret=0;
	if(l<=mid){ret+=query(l,r,tl,mid,lson,p);if(ret>=mod)ret-=mod;}
	if(r>mid){ret+=query(l,r,mid+1,tr,rson,p);if(ret>=mod)ret-=mod;}
	return ret;
}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		a[i]%=mod;
	}
	build(1,n,1);
	get1(q);
	for(int i=1,tp,l,r;i<=q;i++)
	{
		get3(tp,l,r);
		if(tp==2)add(l,r,1,n,1);
		else printf("%d\n",query(l,r,1,n,1));
	}
	return 0;
}