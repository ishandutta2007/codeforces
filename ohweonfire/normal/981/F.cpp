// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
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

int n,L,a[200111],b[400111],tl[400111],tr[400111],v[400111];

int getv(int l,int r){if(l<=r)return r-l+1;else return n-l+r+1;}
bool check(int x)
{
	if(x>=L/2)return true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)a[i]+=L;
		tl[i]=lower_bound(b+1,b+n+n+1,a[i]-x)-b;
		tr[i]=upper_bound(b+1,b+n+n+1,a[i]+x)-b-1;
		if(tl[i]>tr[i])return false;
		tl[i]=tl[i+n]=(tl[i]-1)%n+1;
		tr[i]=tr[i+n]=(tr[i]-1)%n+1;
	}
	if(n==1)return true;
	for(int i=1;i<=n;i++)
	{
		int j=i-1;if(j==0)j=n;
		v[i]=v[i+n]=getv(tr[j],tr[i])-2;
		if(getv(tl[i],tr[i])<v[i])return false;
//		printf("j= %d i= %d v= %d\n",j,i,v[i]);
	}
	for(int i=1;i<=n+n;i++)v[i]+=v[i-1];
	int mn=inf;
	for(int i=n+n;i>=1;i--)
	{
		if(getv(tl[i],tr[i])-1<v[i]-mn)return false;
		mn=min(mn,v[i]);
	}
	return true;
}
int main()
{
	get2(n,L);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)b[i+n]=b[i]+L;
	int l=-1,r=L,mid;
	while(l<r-1)
	{
		mid=(l+r+1)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printendl(r);/**/
	return 0;
}