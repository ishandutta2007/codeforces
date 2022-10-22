#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int n,m,a[M],l[M],r[M],ans=0,p;
vector<int>v1[M],v2[M];

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
	void pushup(int k)
	{
		val(k)=min(val(lson),val(rson));
	}
	void pushdown(int k)
	{
		tag(lson)+=tag(k),tag(rson)+=tag(k),
		val(lson)+=tag(k),val(rson)+=tag(k);
		tag(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=a[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			tag(k)+=z,val(k)+=z;
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

/*struct trtrt
{
	int a[M];
	void build(int k,int l,int r){}
	void update(int k,int l,int r,int z)
	{
		for (int i=l;i<=r;i++)a[i]+=z;
	}
	int query(int k,int l,int r)
	{
		int minn=inf;
		for (int i=l;i<=r;i++)
			minn=min(minn,a[i]);
		return 0;
	}
}T;*/

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	T.build(1,1,n);
	for (int i=1;i<=m;i++)
		l[i]=read(),r[i]=read(),v1[r[i]].pb(i),v2[l[i]].pb(i),
		T.update(1,l[i],r[i],-1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v2[i].size();j++)
			T.update(1,l[v2[i][j]],r[v2[i][j]],1);
		for (int j=0;j<v1[i-1].size();j++)
			T.update(1,l[v1[i-1][j]],r[v1[i-1][j]],-1);
		if (a[i]-T.query(1,1,n)>ans)ans=a[i]-T.query(1,1,n),p=i;
//		cout<<a[i]<<' '<<T.query(1,1,n)<<endl;
	}
	cout<<ans<<endl;
	int cnt=0;
	for (int i=1;i<=m;i++)
		if (l[i]>p||r[i]<p)cnt++;
	cout<<cnt<<endl;
	for (int i=1;i<=m;i++)
		if (l[i]>p||r[i]<p)cout<<i<<endl;
	return 0;
}