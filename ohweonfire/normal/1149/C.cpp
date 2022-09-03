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
#define rs ((t<<1)|1)
namespace sgt
{
	struct node
	{
		int mx,sa,sb,mxl,mxll,mxr,mxrr;
		node(){mx=sa=sb=mxl=mxll=mxr=mxrr=0;}
	};
	node a[600111];
	void pull(int t)
	{
		a[t].sa=a[ls].sa+max(a[rs].sa-a[ls].sb,0);
		a[t].sb=a[rs].sb+max(a[ls].sb-a[rs].sa,0);
		a[t].mx=max(max(a[ls].mx,a[rs].mx),max(a[ls].mxrr+a[rs].mxl,a[ls].mxr+a[rs].mxll));
		a[t].mxl=max(a[ls].mxl,max(a[ls].sa+a[ls].sb+a[rs].mxll,a[ls].sa-a[ls].sb+a[rs].mxl));
		a[t].mxr=max(a[rs].mxr,max(a[rs].sb-a[rs].sa+a[ls].mxr,a[rs].sa+a[rs].sb+a[ls].mxrr));
		a[t].mxrr=max(a[rs].mxrr,a[rs].sa-a[rs].sb+a[ls].mxrr);
		a[t].mxll=max(a[ls].mxll,a[ls].sb-a[ls].sa+a[rs].mxll);
	}
	void modify(int p,int v,int l,int r,int t)
	{
		if(l==r)
		{
			a[t].mx=a[t].mxl=a[t].mxr=1;
			if(v==-1)//A
			{
				a[t].sa=1;a[t].sb=0;
				a[t].mxll=0;a[t].mxrr=1;
			}
			else//B
			{
				a[t].sa=0;a[t].sb=1;
				a[t].mxll=1;a[t].mxrr=0;
			}
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)modify(p,v,l,mid,ls);
		else modify(p,v,mid+1,r,rs);
		pull(t);
	}
	void debug(int l,int r,int t)
	{
		if(l<r)
		{
			int mid=(l+r)>>1;
			debug(l,mid,ls);
			debug(mid+1,r,rs);
		}
		printf("l= %d r= %d mx= %d\n",l,r,a[t].mx);
	}
};

int n,q,m;
char s[200111];
int main()
{
	get2(n,q);scanf("%s",s+1);m=strlen(s+1);
	for(int i=1;s[i];i++)sgt::modify(i,s[i]=='('?1:-1,1,m,1);
	//sgt::debug(1,m,1);
	printf("%d\n",sgt::a[1].mx);
	
	for(int i=1,l,r;i<=q;i++)
	{
		get2(l,r);
		swap(s[l],s[r]);
		sgt::modify(l,s[l]=='('?1:-1,1,m,1);
		sgt::modify(r,s[r]=='('?1:-1,1,m,1);
		printf("%d\n",sgt::a[1].mx);
		//printf("%s\n",s+1);
	}
	return 0;
}