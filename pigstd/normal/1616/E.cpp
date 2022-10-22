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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=1e5+10;
int n;
char s1[M],s2[M];
int q[30][M],l[30],r[30];

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
		l(k)=l,r(k)=r;tag(k)=val(k)=0;
		if (l==r){val(k)=l;return;}
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

signed main()
{
	WT
	{
		cin>>n>>s1+1>>s2+1;T.build(1,1,n);
		for (int i=1;i<=26;i++)l[i]=1,r[i]=0;
		for (int i=1;i<=n;i++)q[s1[i]-'a'+1][++r[s1[i]-'a'+1]]=i;
		int ans=inf,res=0;
		for (int i=1;i<=n;i++)
		{
			int c=s2[i]-'a'+1;
			for (int j=1;j<c;j++)
			{
				if (l[j]<=r[j])
				{
					int pos=q[j][l[j]];
					ckmin(ans,res+T.query(1,pos,pos)-i);
				}
			}
			if (l[c]>r[c])break;
			int pos=q[c][l[c]];l[c]++;
			res+=T.query(1,pos,pos)-i,T.update(1,1,pos,1);
		}
		if (ans==inf)puts("-1");
		else cout<<ans<<'\n';
	}
	return 0;
}
/*
*/