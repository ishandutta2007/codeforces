#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e5+10;
int n,m,a[M],sum[M];

struct segment_tree1
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=max(val(lson),val(rson));}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=sum[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return -inf;
		return max(query(lson,l,r),query(rson,l,r));
	}
}T1;
struct segment_tree2
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=min(val(lson),val(rson));}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=sum[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return inf;
		return min(query(lson,l,r),query(rson,l,r));
	}
}T2;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)a[i]-=read(),sum[i]=a[i]+sum[i-1];
	T1.build(1,1,n),T2.build(1,1,n);
	while(m--)
	{
		int l=read(),r=read();
		if (sum[r]-sum[l-1]!=0){puts("-1");continue;}
		if (T1.query(1,l,r)-sum[l-1]>0){puts("-1");continue;}
		cout<<sum[l-1]-T2.query(1,l,r)<<endl;
	}
	return 0;
}