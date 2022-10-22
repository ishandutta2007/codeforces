#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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
int a[M],cnt[30],q,n;string s;
struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void pushdown(int k)
	{
		if (tag(k)!=-1)
		{
			tag(lson)=tag(rson)=tag(k);
			val(lson)=tag(k)*len(lson);
			val(rson)=tag(k)*len(rson);
			tag(k)=-1;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,tag(k)=-1;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l>r)return;
		if (l(k)>=l&&r(k)<=r)
		{
			val(k)=z*len(k);
			tag(k)=z;
			return;
		}if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l>r) return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T[27];

signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),q=read();cin>>s;
	for (int i=1;i<=n;i++)
		a[i]=s[i-1]-'a'+1;
	for (int i=1;i<=26;i++)T[i].build(1,1,n);
	for (int i=1;i<=n;i++)
		T[a[i]].update(1,i,i,1);
	while(q--)
	{
		int l=read(),r=read();int sum=0;
		for (int i=1;i<=26;i++)
			cnt[i]=T[i].query(1,l,r),sum+=cnt[i]&1;
		if (sum>=2)continue;
		for (int i=1;i<=26;i++)T[i].update(1,l,r,0);
		int p=l;
		for (int i=1;i<=26;i++)
		{
			T[i].update(1,p,p+cnt[i]/2-1,1);
			p+=cnt[i]/2;
		}
		for (int i=1;i<=26;i++)
		{
			T[i].update(1,p,p+(cnt[i]&1)-1,1);
			p+=cnt[i]&1;
		}
		for (int i=26;i>=1;i--)
		{
			T[i].update(1,p,p+cnt[i]/2-1,1);
			p+=cnt[i]/2;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=26;j++)
			if (T[j].query(1,i,i))cout<<(char)(j+'a'-1);
	return 0;
}
/*
3 1
aab
1 3
*/