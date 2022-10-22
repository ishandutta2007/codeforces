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

const int M=2e5+10;
const int N=1e6+10;
int n,q,a[M],t[M],t1[M],t2[M],ans[N],top;
vector<pii>b[M];
pii st[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,sum,val,tag1,tag2,tag3;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define tag1(x) t[(x)].tag1
	#define tag2(x) t[(x)].tag2
	#define tag3(x) t[(x)].tag3
	#define len(x) (r(x)-l(x)+1)
	#define sum(x) t[(x)].sum
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void add1(int k,int x){sum(k)+=len(k)*x,tag3(k)-=x*tag2(k),tag1(k)+=x;}
	void add2(int k,int x){tag2(k)+=x,val(k)+=x*sum(k);}
	void add3(int k,int x){tag3(k)+=x,val(k)+=x*len(k);}
	void pushdown(int k)
	{
		if (tag1(k))add1(lson,tag1(k)),add1(rson,tag1(k)),tag1(k)=0;
		if (tag2(k))add2(lson,tag2(k)),add2(rson,tag2(k)),tag2(k)=0;
		if (tag3(k))add3(lson,tag3(k)),add3(rson,tag3(k)),tag3(k)=0;
	}
	void pushup(int k){val(k)=val(lson)+val(rson),sum(k)=sum(lson)+sum(rson);}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd1(int k,int l,int r,int z)
	{
//		if (k==1)cout<<l<<' '<<r<<' '<<z<<'\n';
		if (l(k)>=l&&r(k)<=r)return add1(k,z),void();
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		upd1(lson,l,r,z),upd1(rson,l,r,z);
		pushup(k);
	}
	void upd2(){add2(1,1);/*puts("qwq");*/}
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
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),q=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		b[r].pb(mp(l,i));
	}
	for (int i=1;i<=n;i++)
	{
		while(top&&a[i]>st[top].y)T.upd1(1,st[top].x,min(t2[st[top].y],t[st[top].y]),-1),t1[st[top].y]=0,top--;
		st[top+1]=mp(t[st[top].y]+1,a[i]);t1[a[i]]=++top;
		if (t2[a[i]]>=st[top].x)T.upd1(1,st[top].x,t2[a[i]],1);
		for (int j=1;j*a[i]<=n;j++)
			if (t2[j*a[i]]<t[j])
			{
				if (t1[j*a[i]])
				{
					T.upd1(1,st[t1[j*a[i]]].x,min(t2[j*a[i]],t1[j*a[i]]==top?i:t[st[t1[j*a[i]]].y]),-1);
					T.upd1(1,st[t1[j*a[i]]].x,min(t[j],t1[j*a[i]]==top?i:t[st[t1[j*a[i]]].y]),1);
				}
				t2[j*a[i]]=t[j];
			}
		T.upd2();t[a[i]]=i;
		for (auto x:b[i])
			ans[x.y]=T.query(1,x.x,i);
	}
	for (int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
/*
12 2
8 10 1 9 12 4 11 3 2 7 5 6 
1 11
1 12

*/