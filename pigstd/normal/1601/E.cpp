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

const int M=3e5+10;
int n,a[M],b[M],ans[M],k,q,st[M],top;
vector<pair<int,int>>e[M];
vector<int>p[M];
struct ST
{
	int f[25][M],lg2[M];
	void init()
	{
		for (int i=1;i<=n;i++)f[0][i]=a[i];
		for (int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<i)-1<=n;j++)
				f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return min(f[k][l],f[k][r-(1<<k)+1]);
	}
}T;
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
	#define len(x) (r(x)-l(x)+1)
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k)
	{
		if (tag(k)==-1)return;
		tag(lson)=tag(rson)=tag(k),
		val(lson)=len(lson)*tag(k),
		val(rson)=len(rson)*tag(k),
		tag(k)=-1;
	}
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,tag(k)=-1,val(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){tag(k)=z,val(k)=len(k)*z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T2;

signed main()
{
	n=read(),q=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	T.init();
	for (int i=1;i<=n-k;i++)b[i]=T.query(i,i+k);
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		e[l].pb(mp(r,i)),ans[i]=a[l];
	}
	for (int i=1;i<=n;i++)p[(i-1)%k+1].pb(i);
	for (int i=1;i<=k;i++)reverse(p[i].begin(),p[i].end());
	for (int i=1;i<=k;i++)
	{
		st[top=0]=n+1;T2.build(1,1,p[i].size()+1);
		for (auto pos:p[i])
		{
			while(b[pos]<b[st[top]])top--;
			st[++top]=pos,T2.update(1,(pos-1)/k+1,(st[top-1]-1)/k,b[pos]);
			for (auto y:e[pos])
				ans[y.y]+=T2.query(1,(pos-1)/k+1,(y.x-i)/k);
//				cout<<pos<<' '<<y.x<<' '<<(pos-1)/k+1<<' '<<(y.x-i)/k<<'\n';
		}
	}
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
///fn/fn/fn