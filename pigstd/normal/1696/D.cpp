#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=2.5e5+10;
int n,a[M],top1,top2,st1[M],st2[M],f[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return inf;
		return min(query(lson,l,r),query(rson,l,r)); 
	}
	void update(int k,int x)
	{
		k=ed[k];val(k)=x;
		while(k!=1)k>>=1,val(k)=min(val(lson),val(rson));
	}
}T1,T2;

void solve()
{
	n=read();top1=top2=0;st1[0]=st2[0]=n+1;
	T1.build(1,1,n),T2.build(1,1,n);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=n;i>=1;i--)
	{
		while(top1!=0&&a[st1[top1]]>a[i])top1--;
		while(top2!=0&&a[st2[top2]]<a[i])top2--;
		if (i==n)f[i]=0;
		else
		{
			if (st1[top1]<st2[top2])
			{
				int tl=1,tr=top1,p=top1;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (st1[Mid]<st2[top2])p=Mid,tr=Mid-1;
					else tl=Mid+1;
				}
				f[i]=1+T1.query(1,p,top1);
			}
			else
			{
				int tl=1,tr=top2,p=top2;
				while(tl<=tr)
				{
					int Mid=(tl+tr)>>1;
					if (st2[Mid]<st1[top1])p=Mid,tr=Mid-1;
					else tl=Mid+1;
				}
				f[i]=1+T2.query(1,p,top2);
			}
		}
		st1[++top1]=st2[++top2]=i;T1.update(top1,f[i]),T2.update(top2,f[i]);
	}
	cout<<f[1]<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}