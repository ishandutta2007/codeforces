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
int n,s[M],a[M],t[M],p[M];
map<int,int>tt;

struct segment_tree
{
	struct tree{int tl,tr,val;}t[M<<2];
	int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=-inf;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int k,int z)
	{
		k=ed[k];ckmax(val(k),z);
		while(k!=1)k>>=1,ckmax(val(k),z);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return -inf;
		return max(query(lson,l,r),query(rson,l,r));
	}
}T1,T2;


void solve()
{
	n=read();s[0]=0;tt.clear();
	for (int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	for (int i=0;i<=n;i++)p[i]=s[i];
	sort(p,p+n+1);int tot=0;
	for (int i=0;i<=n;i++)
		if (i==0||p[i]!=p[i-1])tt[p[i]]=++tot,t[tot]=-inf;
	for (int i=0;i<=n;i++)s[i]=tt[s[i]];
//	puts("qwq");
	T1.build(1,1,tot),T2.build(1,1,tot);
	T1.upd(s[0],0),T2.upd(s[0],0);t[s[0]]=0;
//	puts("qwq");
	for (int i=1;i<=n;i++)
	{
		int tmp=t[s[i]];
		ckmax(tmp,T1.query(1,s[i]+1,tot)-i);
		ckmax(tmp,T2.query(1,1,s[i]-1)+i);
		if (i!=n)T1.upd(s[i],tmp+i),T2.upd(s[i],tmp-i),ckmax(t[s[i]],tmp); 
		else cout<<tmp<<'\n';
	}
}

signed main()
{
	WT solve();
	return 0;
}