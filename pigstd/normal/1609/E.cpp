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
int n,q,a[M];
string s;

int min(int a,int b,int c){return min(min(a,b),c);}

struct segment_tree
{
	struct node
	{
		int tl,tr,val[8];
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val(k)[1]=val(lson)[1]+val(rson)[1],
		val(k)[2]=val(lson)[2]+val(rson)[2],
		val(k)[3]=val(lson)[3]+val(rson)[3],
		val(k)[4]=min(val(lson)[4]+val(rson)[2],val(rson)[4]+val(lson)[1]),
		val(k)[5]=min(val(lson)[5]+val(rson)[3],val(rson)[5]+val(lson)[2]),
		val(k)[6]=min(val(lson)[6]+val(rson)[3],val(rson)[6]+val(lson)[1],
		val(lson)[4]+val(rson)[5]);
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)[a[l]]=1;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){val(k)[1]=val(k)[2]=val(k)[3]=0,val(k)[a[l]]=1;return;}
		update(lson,l),update(rson,l);
		pushup(k);
	}
	int query(){return val(1)[6];}
}T;

signed main()
{
	n=read(),q=read();cin>>s;
	for (int i=1;i<=n;i++)a[i]=s[i-1]-'a'+1;
	T.build(1,1,n);
	while(q--)
	{
		int p=read();cin>>s;
		a[p]=s[0]-'a'+1;
		T.update(1,p);
		printf("%lld\n",T.query());
	}
	return 0;
}