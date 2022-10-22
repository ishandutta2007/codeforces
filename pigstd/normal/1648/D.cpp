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
const int M=5e5+10;
int n,m,s1[M],s2[M],s3[M],f[M],ans=-inf;
multiset<int> s[M];
vector<pii>e[M]; 

inline int min(int a,int b){return a<b?a:b;}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline int max(int a,int b){return a>b?a:b;}
inline int max(int a,int b,int c){return max(a,max(b,c));}


struct node{int f,minn,val1,val2;};
node operator + (node a,node b)
{
	if (a.f==1)return b;if (b.f==1)return a;
	return (node){0,min(a.minn,b.minn),max(a.val1,b.val1),max(a.val2,b.val2,b.val1-a.minn)};
}

struct segment_tree
{
	struct tree
	{
		int tl,tr,val1,val2,minn;
		multiset<int>s;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val1(x) t[(x)].val1
	#define val2(x) t[(x)].val2
	#define minn(x) t[(x)].minn
	#define s(x) t[(x)].s
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		if (l(k)==r(k))
		{
			if (s(k).size())minn(k)=*s(k).begin();
			else minn(k)=inf;
			val1(k)=max(s1[l(k)],f[l(k)-1])-s2[l(k)-1];
			val2(k)=val1(k)-minn(k);
		}
		else
		{
			minn(k)=min(minn(lson),minn(rson));
			val1(k)=max(val1(lson),val1(rson)),val2(k)=max(val2(lson),val2(rson),val1(rson)-minn(lson));
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,val1(k)=val2(k)=-inf,minn(k)=inf;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int k,int w=-1)
	{
		if (k>n)return;
		int now=ed[k];
		if (w!=-1)s(now).erase(s(now).find(w));
		while(now!=0)pushup(now),now>>=1;
	}
	void upd2(int k,int w)
	{
		int now=ed[k];s(now).insert(w);
		while(now!=0)pushup(now),now>>=1;
	}
	node query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return (node){0,minn(k),val1(k),val2(k)};
		if (l(k)>r||r(k)<l)return (node){1,114514,1919810,233333333};
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

signed main()
{
	n=read(),m=read();
	for (int i=0;i<=n;i++)f[i]=-inf;
	for (int i=1;i<=n;i++)s1[i]=s1[i-1]+read();
	for (int i=1;i<=n;i++)s2[i]=s2[i-1]+read();
	for (int i=1;i<=n;i++)s3[i]=s3[i-1]+read();
	T.build(1,1,n);
	while(m--)
	{
		int l=read(),r=read(),w=read();
		T.upd2(l,w);e[r].pb(mp(l,w));
	}
	for (int i=1;i<=n;i++)
	{
		auto x=T.query(1,1,i);
		f[i]=x.val2+s2[i];T.upd(i+1);
		ckmax(ans,f[i]+s3[n]-s3[i-1]);
		for (auto x:e[i])T.upd(x.x,x.y);
	}
	cout<<ans<<'\n';
	return 0;
}