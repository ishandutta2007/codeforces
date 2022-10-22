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

const int M=1e5+10;
int n,a[M],f[M],l[M],r[M];
vector<int>ans;

struct segment_tree
{
	struct tree{int tl,tr,val,tag;}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{val(k)=val(lson)+val(rson);}
	void pushdown(int k)
	{val(lson)+=tag(k)*len(lson),val(rson)+=tag(k)*len(rson);tag(lson)+=tag(k),tag(rson)+=tag(k);tag(k)=0;}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag(k)=0;
		if (l==r){val(k)=0;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z*len(k),tag(k)+=z;return;}
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
}T;

void del(int x)
{
	ans.pb(x);
	int rr=r[x],ll=l[x];
	r[ll]=rr,l[rr]=ll;
	T.update(1,x,x,-1),f[x]=0;
	if (__gcd(a[ll],a[rr])==1&&f[rr]==0)f[rr]=1,T.update(1,rr,rr,1);
	if (__gcd(a[ll],a[rr])!=1&&f[rr]==1)f[rr]=0,T.update(1,rr,rr,-1);
}

signed main()
{
	int rrrr=read(),ccnt=0;
	for (int kkk=1;kkk<=rrrr;kkk++)
	{
		n=read();ans.clear();T.build(1,1,n);
		for (int i=1;i<=n;i++)a[i]=read(),f[i]=0,l[i]=i-1,r[i]=i+1;
//		if (ccnt==204)cout<<n<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
		l[1]=n,r[n]=1;
		for (int i=1;i<=n;i++)
			if (__gcd(a[i],a[l[i]])==1)f[i]=1,T.update(1,i,i,1);
		int now=r[1];
		while(ans.size()!=n)
		{
			if (T.query(1,1,n)==0)break;
//			cout<<T.query(1,0,n-1)<<endl;
			
			int tl,tr,p;
			if (T.query(1,now,n)!=0)
			{
				tl=now,tr=n;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (T.query(1,tl,Mid)!=0)p=Mid,tr=Mid-1;
					else tl=Mid+1;
				}
			}
			else
			{
				tl=1,tr=now;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (T.query(1,1,Mid)!=0)p=Mid,tr=Mid-1;
					else tl=Mid+1;
				}
			}
			del(p);now=r[r[p]];
		}
		cout<<ans.size()<<' ';
		for (int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
		puts("");
		ccnt+=ans.size()+1; 
	}
	return 0;
}