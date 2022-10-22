#include<bits/stdc++.h>
using namespace std;

const int M=5e5+10;
int n,p[M],ans;
map<int,int>t;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct Tree
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define val(k) t[(k)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val(k)=max(val(lson),val(rson));
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r); 
	}
	void update(int k,int l,int z)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==r(k)&&l(k)==l)
		{
			val(k)=max(val(k),z);
			return;
		}
		update(lson,l,z),update(rson,l,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return 0;
		if (r(k)<=r&&l(k)>=l)return val(k);
		return max(query(lson,l,r),query(rson,l,r));
	}
}T;

struct node
{
	int a,b,c,id;
}a[M];

bool cmp1(int a,int b){return a<b;}
bool cmp2(node a,node b){return a.b>b.b||a.b==b.b&&a.c<b.c;}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)p[i]=a[i].a=read(),a[i].id=i;
	for (int i=1;i<=n;i++)a[i].b=read();
	for (int i=1;i<=n;i++)a[i].c=read();
	sort(p+1,p+1+n);int cjl_AK_IOI=0;
	for (int i=1;i<=n;i++)
		if (i==1||p[i]!=p[i-1])t[p[i]]=++cjl_AK_IOI;
	T.build(1,1,cjl_AK_IOI);
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
	{
		int k=t[a[i].a];
		if (T.query(1,k+1,cjl_AK_IOI)>a[i].c)ans++;
		T.update(1,k,a[i].c);
	}
	cout<<ans;
	return 0;
}