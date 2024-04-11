#include<bits/stdc++.h>
//#define int long long
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

const int Mod=998244353;
const int M=2e5+10;
int n,a[M],m,p[M],s[M],x[M],y[M];
int fac[M<<1],inv[M<<1],ifac[M<<1];
set<pair<int,int> >t;
void init(int n)
{
	inv[1]=1;fac[0]=ifac[0]=1;
	for (int i=2;i<=n;i++)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for (int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%Mod,ifac[i]=1ll*ifac[i-1]*inv[i]%Mod;
}
int C(int m,int n){return 1ll*fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

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
		if (tag(k)!=-1)
		{
			val(lson)=len(lson)*tag(k),tag(lson)=tag(k);
			val(rson)=len(rson)*tag(k),tag(rson)=tag(k);
			tag(k)=-1;
		}
	}
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag(k)=-1;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			tag(k)=z,val(k)=len(k)*z;
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
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

int find(int x)
{
	int tl=1,tr=n,p=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (T.query(1,1,Mid)>=x)p=Mid,tr=Mid-1;
		else tl=Mid+1;
	}
	assert(p!=-1);return p;
}

signed main()
{
	init(4e5);
	T.build(1,1,2e5);
	WT
	{
		n=read(),m=read();int sum=0;t.clear();
		T.update(1,1,n,1);
		for (int i=1;i<=m;i++)x[i]=read(),y[i]=read();
		for (int i=m;i>=1;i--)
		{
			int sum=(i==m)?n-x[i]:x[i+1]-x[i]-1;
			if (sum!=0)
			{
				int tl=1,tr=n,p=-1;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (T.query(1,Mid,n)>=sum)p=Mid,tl=Mid+1;
					else tr=Mid-1;
				}assert(p!=-1);
				T.update(1,p,n,0);
			}
			p[i]=find(y[i]);T.update(1,p[i],p[i],0);
			s[i]=find(y[i]-1);
		}
//		for (int i=1;i<=m;i++)cout<<p[i]<<' '<<s[i]<<endl;
		t.clear();t.insert(mp(0,1));
		for (int i=1;i<=m;i++)
		{
			auto x=t.lower_bound(mp(p[i],0));x--;
			pair<int,int>pp=*x;
			if (pp.y==0&&pp.x==s[i])
			{
				t.erase(pp);sum++;
				t.insert(mp(pp.x,1));
			}t.insert(mp(p[i],0));
		}//cout<<sum<<' ';
		sum+=n-m-1;printf("%d\n",C(sum+n,n));
//		cout<<sum<<endl;
	}
	return 0;
}
// 2600 