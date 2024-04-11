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
int n,a[M];
char s[M];
struct segment_tree
{
	struct tree
	{
		int tl,tr,sum,maxn,minn;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define sum(x) t[(x)].sum
	#define maxn(x) t[(x)].maxn
	#define minn(x) t[(x)].minn
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void pushup(int k){sum(k)=sum(lson)+sum(rson),maxn(k)=max(maxn(lson),maxn(rson)+sum(lson)),minn(k)=min(minn(lson),minn(rson)+sum(lson));}
	void update(int k,int l)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){sum(k)=a[l],minn(k)=min(0ll,a[l]),maxn(k)=max(0ll,a[l]);return;}
		update(lson,l),update(rson,l);
		pushup(k);
	}
}T;

void query()
{
	if (T.t[1].sum!=0||T.t[1].minn!=0)return puts("-1"),void();
	return printf("%lld ",T.t[1].maxn),void();
}

signed main()
{
	n=read();scanf("%s",s+1);int now=1;
	T.build(1,1,n+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='R')now++;
		else if (s[i]=='L')now=max(1ll,now-1);
		else{
			if (s[i]=='(')a[now]=1;
			else if (s[i]==')')a[now]=-1;
			else a[now]=0;T.update(1,now);
		}
		query();
	}
	return 0;
}