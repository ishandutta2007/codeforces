#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,m,p,a[M];
struct segment_tree
{
	struct tree
	{
		int tl,tr,a[6],cnt[6],tag,sum;
		void clear()
		{
			tl=tr=tag=sum=0;
			memset(a,0,sizeof(a));
			memset(cnt,0,sizeof(cnt));
		}
	}t[M<<2],ans;
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define tag(x) t[(x)].tag
	#define sum(x) t[(x)].sum
	#define a(x,y) t[(x)].a[(y)]
	#define cnt(x,y) t[(x)].cnt[(y)]
	#define len(x) (t[(x)].tr-t[(x)].tl+1)
	#define lson (k<<1)
	#define rson (k<<1|1)
	tree add(tree a,tree b)
	{
		for (int i=1;i<=a.sum;i++)
		{
			int f=0;
			for (int j=1;j<=b.sum;j++)
				if (a.a[i]==b.a[j]){f=1,b.cnt[j]+=a.cnt[i];continue;}
			if (f==1)
				continue;
			if (b.sum<p)
			{
				b.a[++b.sum]=a.a[i],b.cnt[b.sum]=a.cnt[i];
				continue;
			}int p=1;
			for (int j=2;j<=b.sum;j++)
				if (b.cnt[j]<b.cnt[p])p=j;
			if (b.cnt[p]<=a.cnt[i])
			{
				int tmp=b.cnt[p];b.a[p]=a.a[i],b.cnt[p]=a.cnt[i];
				for (int j=1;j<=b.sum;j++)
					b.cnt[j]-=tmp;
			}
			else
			{
				for (int j=1;j<=b.sum;j++)
					b.cnt[j]-=a.cnt[i];
			}
		}
		b.tl=min(b.tl,a.tl),b.tr=max(b.tr,a.tr);
		b.tag=0;
		return b;
	}
	void pushdown(int k)
	{
		if (tag(k))
		{
			tag(lson)=tag(rson)=tag(k);
			sum(lson)=sum(rson)=1;
			a(lson,1)=a(rson,1)=tag(k);
			cnt(lson,1)=len(lson),cnt(rson,1)=len(rson);
			tag(k)=0;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r; 
		if (l==r)
		{
			cnt(k,1)=sum(k)=1,a(k,1)=a[l];
			return;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		t[k]=add(t[lson],t[rson]);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			sum(k)=1;a(k,1)=z;
			cnt(k,1)=len(k);tag(k)=z;
			return;
		}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		t[k]=add(t[lson],t[rson]);
	}
	void query(int k,int l,int r)
	{
		if (k==1)ans.clear();
		if (l(k)>=l&&r(k)<=r){ans=add(t[k],ans);return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		query(lson,l,r),query(rson,l,r);
	}
}T;

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("qwq.out","w",stdout);
	n=read(),m=read(),p=read(),p=100/p;
	for (int i=1;i<=n;i++)a[i]=read();
	T.build(1,1,n);
//	return 0;
//	puts("qwq");
	while(m--)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read(),z=read();
			T.update(1,l,r,z);
		}
		else
		{
			int l=read(),r=read();
//			for (int i=1;i<=n;i++)
//			{
//				T.query(1,i,i);
//				cout<<T.ans.a[1]<<' ';
//			}puts("");
			T.query(1,l,r);
			printf("%d",T.ans.sum);
			for (int i=1;i<=T.ans.sum;i++)
				printf(" %d",T.ans.a[i]);
			puts("");
		}
	}
	return 0;
}