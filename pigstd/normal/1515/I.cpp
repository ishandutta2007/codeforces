#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=2e5+10;
const int B=60;
int n,p[M],v[M],a[M],w[M],q,lg2[1<<16],t[M];

inline int LG2(int k)
{
	int res=0;
	while(k>=(1<<16))res+=16,k>>=16;
	return res+lg2[k];
}

struct segment_tree
{
	struct tree
	{
		int tl,tr,ls,rs,s[64],sv[64],mn[64],fa;
	}t[M<<1];int ed[M],tot=1;
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr 
	#define s(k) t[(k)].s
	#define sv(k) t[(k)].sv
	#define mn(k) t[(k)].mn
	#define fa(k) t[(k)].fa
	#define lson t[(k)].ls
	#define rson t[(k)].rs
	void pushup(int k)
	{
		for (int i=0;i<=B;i++)
		{
			s(k)[i]=s(lson)[i]+s(rson)[i],sv(k)[i]=sv(lson)[i]+sv(rson)[i],
			mn(k)[i]=min(mn(rson)[i]+(i?s(lson)[i-1]:0),mn(lson)[i]);
		}
	}
	void build(int k,int l,int r,int f=0)
	{
		fa(k)=f,l(k)=l,r(k)=r;
		if (l==r)
		{
			ed[l]=k;int L=LG2(w[p[l]]);
			for (int i=0;i<=B;i++)mn(k)[i]=inf;
			if (a[p[l]])mn(k)[L]=w[p[l]];
			for (int i=L;i<=B;i++)
				s(k)[i]=a[p[l]]*w[p[l]],sv(k)[i]=a[p[l]]*v[p[l]];
			return;
		}
		int Mid=(l+r)>>1;
		lson=++tot,rson=++tot;
		build(lson,l,Mid,k),build(rson,Mid+1,r,k);
		pushup(k);
	}
	void solve(int k,int &S,int &res)
	{
//		cerr<<l(k)<<' '<<r(k)<<' '<<S<<' '<<res<<'\n';
		if (l(k)==r(k))
		{
			if (w[p[l(k)]]*a[p[l(k)]]<=S)S-=w[p[l(k)]]*a[p[l(k)]],res+=v[p[l(k)]]*a[p[l(k)]];
			else
			{
				int cnt=S/w[p[l(k)]];
				S-=cnt*w[p[l(k)]],res+=cnt*v[p[l(k)]];
			}
			return;
		}
		int L=LG2(S);
//		cerr<<L<<'\n';
		if (mn(k)[L]>S&&(L==0||s(k)[L-1]<=S))
		{
			if (L)
			{
				res=res+sv(k)[L-1],
				S-=s(k)[L-1];
			}
			return;
		}
		solve(lson,S,res),solve(rson,S,res);
	}
	void upd(int l)
	{
		int k=ed[l];//cerr<<l<<'\n';
		for (int i=0;i<=B;i++)s(k)[i]=sv(k)[i]=0,mn(k)[i]=inf;
		int L=LG2(w[p[l]]);
		if (a[p[l]])mn(k)[L]=w[p[l]];
		for (int i=L;i<=B;i++)
			s(k)[i]=a[p[l]]*w[p[l]],sv(k)[i]=a[p[l]]*v[p[l]];
		while(k!=1)k=fa(k),pushup(k);
	}
}T;

bool cmp(int a,int b){return v[a]>v[b]||(v[a]==v[b]&&w[a]<w[b]);}

signed main()
{
	for (int i=2;i<(1<<16);i++)lg2[i]=lg2[i>>1]+1;
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read(),w[i]=read(),v[i]=read(),p[i]=i;
	sort(p+1,p+1+n,cmp);
	for (int i=1;i<=n;i++)t[p[i]]=i,cerr<<p[i]<<(i==n?'\n':' ');
	T.build(1,1,n);
	while(q--)
	{
		int opt=read();
		if (opt==1)
		{
			int k=read(),d=read();
			a[d]+=k,T.upd(t[d]);
		}
		else if (opt==2)
		{
			int k=read(),d=read();
			a[d]-=k,T.upd(t[d]);
		}
		else
		{
			int c=read(),res=0;
			T.solve(1,c,res);
			cout<<res<<'\n';
		}
	}
	return 0;
}
/*
5 1
5 1 4
5 2 5
8 1 2
0 5 2
3 5 1
3 8
*/