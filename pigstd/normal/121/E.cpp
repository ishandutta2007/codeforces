#include<bits/stdc++.h>
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

const int inf=1e9;
const int M=1e5+10;
int n,q,a[M],cnt,opt[M],l[M],r[M],ans[M],z[M],f[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
char s[M][15];

struct segment_tree
{
	int a[M];
	struct tree
	{
		int tl,tr,val,maxn,tag;
	}t[M<<2];
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define val(k) t[(k)].val
	#define tag(k) t[(k)].tag
	#define maxn(k) t[(k)].maxn
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val(k)=val(lson)+val(rson);
		maxn(k)=max(maxn(lson),maxn(rson));
	}
	void pushdown(int k)
	{
		if (tag(k)==0)return;
		maxn(lson)+=tag(k),maxn(rson)+=tag(k);
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		tag(k)=0;
	}
	void upd(int k)
	{
		if (maxn(k)<0)return;
		if (l(k)==r(k))
		{
			if (maxn(k)>0)maxn(k)=-inf,val(k)=0;
			if (maxn(k)==0)val(k)=1;cnt++;
			return;
		}
		pushdown(k);
		upd(lson),upd(rson);
		pushup(k);
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,tag(k)=val(k)=0;
		if (l==r){maxn(k)=a[l]>0?-inf:a[l],val(k)=a[l]==0;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (z==0)return;
		if (l(k)>r||r(k)<l)return;
//		cnt++;
		if (l(k)>=l&&r(k)<=r)
		{
			tag(k)+=z,maxn(k)+=z;
			if (maxn(k)>=0)upd(k);
			return;
		}
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (maxn(k)<0)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=q;i++)
	{
		scanf("%s",s[i]);l[i]=read(),r[i]=read();
		if (s[i][0]!='c')z[i]=read(),opt[i]=1;
	}
//	if (a[1]==5&&a[2]==2&&a[3]==1&&a[4]==5)
//	{
//		for (int i=0;i<=0;i++)
//		{
//			for (int j=1;j<=n;j++)T.a[j]=a[j];
//			T.build(1,1,n);
//			for (int j=1;j<=q;j++)
//			{
//				if (opt[j]==0)
//					ans[j]+=T.query(1,l[j],r[j]);
//				else
//					T.update(1,l[j],r[j],z[j]);
//			}
//		}
//		cout<<"qwqwqwq"<<cnt<<endl;
//		for (int i=1;i<=q;i++)
//			if (opt[i]==0)printf("%d\n",ans[i]);
//		return 0;
//	}
	for (int i=0;i<30;i++)
	{
		for (int j=1;j<=n;j++)T.a[j]=a[j]-f[i];
		T.build(1,1,n);
		for (int j=1;j<=q;j++)
		{
			if (opt[j]==0)
				ans[j]+=T.query(1,l[j],r[j]);
			else
				T.update(1,l[j],r[j],z[j]);
		}
	}
	for (int i=1;i<=q;i++)
		if (opt[i]==0)printf("%d\n",ans[i]);
	return 0;
}