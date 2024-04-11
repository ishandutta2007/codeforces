#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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
const int M=35010;
const int N=110;
int n,a[M],t[M],k,dp[N][M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=min(val(lson),val(rson));}
	void pushdown(int k)
	{
		val(lson)+=tag(k),val(rson)+=tag(k),
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		tag(k)=0; 
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=tag(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			val(k)+=z,tag(k)+=z;
			return;
		}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return inf;
		pushdown(k);
		return min(query(lson,l,r),query(rson,l,r));
	}
}T;

/*struct caicaiwodexianduanshushibushiyouxieguale
{
	int c[M];
	void build(int k,int l,int r)
	{
		for (int i=l;i<=r;i++)c[i]=0;
	}
	void update(int k,int l,int r,int z)
	{
		for (int i=l;i<=r;i++)
			c[i]+=z;
	}
	int query(int k,int l,int r)
	{
		int minn=inf;
		for (int i=l;i<=r;i++)minn=min(minn,c[i]);
		return minn;
	}
}T;*/

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read(),dp[0][i]=inf;
	for (int i=1;i<=k;i++)
	{
		T.build(1,0,n);
		for (int j=1;j<=n;j++)t[j]=0;
		for (int j=1;j<=n;j++)
		{
			T.update(1,j,j,dp[i-1][j-1]);
			if (t[a[j]])T.update(1,0,t[a[j]],j-t[a[j]]);
			t[a[j]]=j;dp[i][j]=T.query(1,0,j);
		}
	}cout<<dp[k][n]<<endl;
	return 0;
}