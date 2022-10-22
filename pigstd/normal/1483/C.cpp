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
const int M=3e5+10;
int n,h[M],b[M],dp[M];
struct segment_tree// max max 
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
	void pushup(int k){val(k)=max(val(lson),val(rson));}
	void pushdown(int k)
	{
		tag(lson)=max(tag(lson),tag(k)),tag(rson)=max(tag(rson),tag(k));
		val(lson)=max(val(lson),tag(k)),val(rson)=max(val(rson),tag(k));
		tag(k)=-inf;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag(k)=-inf;
		if (l==r){val(k)=-inf;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r){val(k)=max(val(k),z),tag(k)=max(tag(k),z);return;}
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return -inf;
		if (l(k)>=l&&r(k)<=r)return val(k);
		pushdown(k);
		return max(query(lson,l,r),query(rson,l,r));
	}
}T1,T2;
struct ST
{
	int f[M][25],lg2[M];
	void RMQ()// 
	{
		for (int i=1;i<=n;i++)f[i][0]=h[i];
		for (int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<(i-1))<=n;j++)
				f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}T;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)h[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	T.RMQ();T1.build(1,0,n),T2.build(1,0,n);
	dp[0]=0,T1.update(1,0,0,0);
	for (int i=1;i<=n;i++)
	{
		int tl=1,tr=i,p1,p2;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (T.query(Mid,i)==h[i])p1=Mid,tr=Mid-1;
			else tl=Mid+1;
		}
		tl=i,tr=n;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (T.query(i,Mid)==h[i])p2=Mid,tl=Mid+1;
			else tr=Mid-1;
		}//cout<<p1<<' '<<p2<<endl;
		T2.update(1,i,p2,T1.query(1,p1-1,i)+b[i]);
//		cout<<T1.query(1,p1-1,i)+b[i]<<endl;
		dp[i]=T2.query(1,i,i);T1.update(1,i,i,dp[i]);
	}cout<<dp[n]<<endl;
//	for (int i=1;i<=n;i++)cout<<dp[i]<<' ';
	return 0;
}