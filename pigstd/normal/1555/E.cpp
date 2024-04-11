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

const int M=1e6+10;
int n,m;
pair<int,pair<int,int>>a[M]; 
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
	void pushdown(int k)
	{
		val(lson)+=tag(k),val(rson)+=tag(k),
		tag(lson)+=tag(k),tag(rson)+=tag(k),tag(k)=0;
	}
	void pushup(int k)
	{
		val(k)=min(val(lson),val(rson));
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r); 
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r){val(k)+=z,tag(k)+=z;return;}
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(){return val(1);}
}T;

signed main()
{
	n=read(),m=read();T.build(1,1,m);
//	for (int i=1;i<m;i++)
//		T.update(1,i,i+1,1);
//	cout<<T.query()<<endl;
	for (int i=1;i<=n;i++)a[i].y.x=read(),a[i].y.y=read(),a[i].x=read();
	sort(a+1,a+1+n);
//	for (int i=1;i<=n;i++)
//		cout<<a[i].y.x<<' '<<a[i].y.y<<' '<<a[i].x<<endl;
	int ans=1e18;
	for (int l=1,r=1;l<=n;l++)
	{
		T.update(1,a[l].y.x+(a[l].y.x!=1),a[l].y.y,1);
		while(T.query()!=0&&r<=l)
			T.update(1,a[r].y.x+(a[r].y.x!=1),a[r].y.y,-1),r++;
		if (r!=1)ans=min(ans,a[l].x-a[r-1].x); 
//		cout<<l<<' '<<r<<endl;
	}cout<<ans<<endl; 
	return 0;
}