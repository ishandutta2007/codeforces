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

const int M=3e5+10;
int n,q,a[M],ans[M],opt[M],l[M],r[M],x[M],tot,t2[M<<1],b[M];
map<int,int>t;
mt19937 rnd(time(0));
//naotanb 

inline int lowbit(int x){return x&(-x);}

struct BIT
{
	int c[M];
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))c[i]+=x;
	}
	void clear(){memset(c,0,sizeof(c));}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
	int ask(int l,int r){return ask(r)-ask(l-1);}
}T;


signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (!t[a[i]])t[a[i]]=++tot;
		a[i]=t[a[i]];
	}
	memcpy(b,a,sizeof(b));
	for (int i=1;i<=q;i++)
	{
		ans[i]=1;opt[i]=read();
		if (opt[i]==1)
		{
			l[i]=read(),r[i]=read();
			if (!t[r[i]])t[r[i]]=++tot;
			r[i]=t[r[i]];
		}
		else l[i]=read(),r[i]=read(),x[i]=read();
	}
//	for (int i=1;i<=n;i++)cerr<<a[i]<<(i==n?'\n':' ');
	int TT=30;
	while(TT--)
	{
		for (int i=1;i<=tot;i++)t2[i]=rnd();
		memcpy(a,b,sizeof(a));
		T.clear();
		for (int i=1;i<=n;i++)T.add(i,t2[a[i]]);
		for (int i=1;i<=q;i++)
		{
			if (opt[i]==1)
				T.add(l[i],t2[r[i]]-t2[a[l[i]]]),a[l[i]]=r[i];
			else if (ans[i]==1)
				if (T.ask(l[i],r[i])%x[i]!=0)ans[i]=0;
		}
	}
	for (int i=1;i<=q;i++)if (opt[i]==2)cout<<(ans[i]?"YES":"NO")<<'\n';
	return 0;
}