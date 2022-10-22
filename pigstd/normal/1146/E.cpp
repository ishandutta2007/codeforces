#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
const int maxn=1e5;
int n,a[M],q;
struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag1,tag2;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag1(x) t[(x)].tag1
	#define tag2(x) t[(x)].tag2
	#define len(x) (r(x)-l(x)+1)
	#define lson (k<<1)
	#define rson (k<<1|1)
	void pushup(int k)
	{
		val(k)=val(lson)+val(rson);
	}
	//tag1 
	//tag2  
	void pushdown(int k)
	{
		if (tag1(k))
		{
			tag1(lson)=tag1(rson)=tag1(k);
			val(lson)=len(lson)*tag1(k);
			val(rson)=len(rson)*tag1(k);
			tag2(lson)=tag2(rson)=0;
			tag1(k)=0;
			
		}
		if (tag2(k))
		{
			tag2(lson)^=1,tag2(rson)^=1,
			val(lson)*=-1,val(rson)*=-1;
			tag2(k)=0;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=1;
		if (l==r){val(k)=1;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update1(int k,int l,int r,int z)// 
	{
//		if (k==1)cout<<1<<' '<<l<<' '<<r<<' '<<z<<endl;
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)
		{
			tag1(k)=z,val(k)=z*len(k);tag2(k)=0;
			return;
		}
		pushdown(k);
		update1(lson,l,r,z),update1(rson,l,r,z);
		pushup(k);
	}
	void update2(int k,int l,int r)
	{
//		if (k==1)cout<<2<<' '<<l<<' '<<r<<endl;
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)
		{
			tag2(k)^=1,val(k)*=-1; 
			return;
		}
		pushdown(k);
		update2(lson,l,r),update2(rson,l,r);
		pushup(k);
	}
	int query(int k,int l)
	{
		if (l(k)>l||r(k)<l)return 0;
		if (l(k)==l&&r(k)==l)return val(k);
		pushdown(k);
		return query(lson,l)+query(rson,l);
	}
}T;

signed main()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)cin>>a[i];
	T.build(1,1,maxn*2+1);
	while(q--)
	{
		string s;cin>>s;int x;cin>>x;
		if (s==">")
		{
			if (x>=0)
			{
				T.update1(1,1,maxn-x,1);
				T.update1(1,2+maxn+x,maxn*2+1,-1);
			}
			else
			{
				T.update1(1,1,maxn+1+x,1);
				T.update1(1,1+maxn-x,maxn*2+1,-1);
				T.update2(1,maxn+2+x,maxn-x);
			}
		}
		else
		{
			if (x>=0)
			{
				T.update2(1,maxn+2-x,maxn+x);
				T.update1(1,1,maxn+1-x,-1);
				T.update1(1,1+maxn+x,maxn*2+1,1);
			}
			else
			{
				T.update1(1,1,maxn+x,-1);
				T.update1(1,2+maxn-x,maxn*2+1,1);
			}
		}
	}
	for (int i=1;i<=n;i++)
		cout<<a[i]*T.query(1,a[i]+maxn+1)<<' ';
	return 0;
}