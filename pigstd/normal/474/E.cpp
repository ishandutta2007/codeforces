#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int f[M],id[M],a[M],p[M],pp[M],cnt,n,P;
map<int,int>t;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct node
{
	struct tree
	{
		int tl,tr,val,id;
	}t[M<<2];int maxn,id;
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define val(k) t[(k)].val
	#define id(k) t[(k)].id
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		if (val(rson)>val(lson))id(k)=id(rson),val(k)=val(rson);
		else id(k)=id(lson),val(k)=val(lson);
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)
		{
//			id(k)=l;
			return;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int z,int id)
	{
		if (l(k)==r(k)&&l(k)==l)
		{
			if (z>val(k))val(k)=z,id(k)=id;
			return;
		}
		if (l(k)>l||r(k)<l)return;
		update(lson,l,z,id),update(rson,l,z,id);
		pushup(k);
	}
	void query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)
		{
			if (val(k)>maxn)maxn=val(k),id=id(k);
			return;
		}
		query(lson,l,r),query(rson,l,r);
	}
	void clear(){maxn=id=0;}
}T;

int find(int k)
{
	int tl=1,tr=cnt,ans=0;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (pp[Mid]>k)tr=Mid-1;
		else tl=Mid+1,ans=Mid;
	}
	if (k>pp[cnt])return n+1;
	if (k<pp[1])return 0;
	return ans;
}

int ans[M];

void dfs(int k,int t)
{
	if (t==0)return;
	ans[t]=k;
	dfs(id[k],t-1);
}

signed main()
{
	n=read(),P=read();
	for (int i=1;i<=n;i++)a[i]=p[i]=read();
	sort(p+1,p+1+n);
	pp[++cnt]=p[1];
	for (int i=2;i<=n;i++)
		if (p[i]!=pp[cnt])pp[++cnt]=p[i];
	T.build(1,1,cnt);
//	cout<<find(1)<<' ';
	for (int i=1;i<=n;i++)
	{
		int k=a[i]-P;
		int l=find(k);
		T.clear();
		T.query(1,1,l);
		f[i]=T.maxn,id[i]=T.id;
		k=a[i]+P;l=find(k);
		if (pp[l]<k)l++;
		T.clear(),T.query(1,l,cnt);
		if (T.maxn>f[i])f[i]=T.maxn,id[i]=T.id;
		f[i]++;
		l=find(a[i]);
		T.update(1,l,f[i],i);
	}int p=0;
	for (int i=1;i<=n;i++)if (f[i]>f[p])p=i;
	cout<<f[p]<<endl;
	dfs(p,f[p]);
	for (int i=1;i<=f[p];i++)cout<<ans[i]<<' ';
//	puts("");
//	for (int i=1;i<=n;i++)cout<<i<<' '<<f[i]<<' '<<id[i]<<endl;
	return 0;
}