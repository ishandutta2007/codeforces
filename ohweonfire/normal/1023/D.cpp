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

#define ls (t<<1)
#define rs (t<<1|1)
int vs[600111];
void pushdown(int t)
{
	if(vs[t])
	{
		vs[ls]=vs[t];
		vs[rs]=vs[t];
		vs[t]=0;
	}
}
void modify(int l,int r,int v,int tl,int tr,int t)
{
	if(l<=tl&&tr<=r)
	{
		vs[t]=v;
		return;
	}
	pushdown(t);
	int mid=(tl+tr)>>1;
	if(l<=mid)modify(l,r,v,tl,mid,ls);
	if(r>mid)modify(l,r,v,mid+1,tr,rs);
}
int query(int p,int tl,int tr,int t)
{
	if(tl==tr)return vs[t];
	pushdown(t);
	int mid=(tl+tr)>>1;
	if(p<=mid)return query(p,tl,mid,ls);
	else return query(p,mid+1,tr,rs);
}

int n,q,a[200111],b[200111];
int mx[200111],mn[200111];

int main()
{
	get2(n,q);
	for(int i=1;i<=n;i++)get1(a[i]);
	
	if(*max_element(a+1,a+n+1)!=q)
	{
		int t=min_element(a+1,a+n+1)-a;
		if(a[t])
		{
			puts("NO");
			return 0;
		}
		a[t]=q;
	}
	
	for(int i=1;i<=n;i++)
	{
		mx[a[i]]=i;
		if(!mn[a[i]])mn[a[i]]=i;
	}
	mn[1]=1;mx[1]=n;
	for(int i=1;i<=q;i++)if(mx[i])modify(mn[i],mx[i],i,1,n,1);
	
	for(int i=1;i<=n;i++)
	{
		b[i]=query(i,1,n,1);
		if(a[i]&&a[i]!=b[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}