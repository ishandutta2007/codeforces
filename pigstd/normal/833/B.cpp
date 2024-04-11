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

const int M=35010;
const int N=55;
int dp[N][M],n,k,a[M],t[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,maxn,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define maxn(x) t[(x)].maxn
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k)
	{
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		maxn(lson)+=tag(k),maxn(rson)+=tag(k);
		tag(k)=0;
	}
	void pushup(int k){maxn(k)=max(maxn(lson),maxn(rson));}
	void build(int k,int l,int r)
	{
		maxn(k)=tag(k)=0,l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){tag(k)+=z,maxn(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return maxn(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return max(query(lson,l,r),query(rson,l,r));
	}
}T;/*
struct jkjehsfk
{
	int c[M];
	void build(int k,int l,int r){memset(c,0,sizeof(c));}
	void update(int k,int l,int r,int z)
	{
		for (int i=l;i<=r;i++)c[i]+=z;
	}
	int query(int k,int l,int r)
	{
		int maxn=0;
		for (int i=l;i<=r;i++)maxn=max(maxn,c[i]);
		return maxn;
	}
}T;*/

signed main()
{
	n=read(),k=read();int res=0;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (!t[a[i]])t[a[i]]=1,res++;
		dp[1][i]=res;
	}
	for (int i=2;i<=k;i++)
	{
		T.build(1,0,n);memset(t,0,sizeof(t));
		for (int j=1;j<=n;j++)
		{
			T.update(1,t[a[j]],j-1,1);t[a[j]]=j;
			dp[i][j]=T.query(1,0,j-1);T.update(1,j,j,dp[i-1][j]);
		}
	}cout<<dp[k][n]<<endl;
	return 0;
}