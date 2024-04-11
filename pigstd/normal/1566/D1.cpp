//AFO countdown:???
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
int n,cnt,p[M],a[M];
map<int,int>t;

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void update(int k,int x)
	{
		for (int i=k;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);}
}T;

signed main()
{
	WT
	{
		read();n=read();cnt=0;t.clear();int res=0;
		for (int i=1;i<=n;i++)a[i]=p[i]=read();
		sort(p+1,p+1+n);
		for (int i=1;i<=n;i++)
			if (p[i]!=p[i-1])t[p[i]]=++cnt;
		for (int i=1;i<=n;i++)a[i]=t[a[i]];
		for (int i=n;i>=1;i--)
		{
			res+=T.query(a[i]+1,n);
			T.update(a[i],1);
		}
		for (int i=1;i<=n;i++)
			T.update(a[i],-1);
		cout<<res<<endl; 
	}
	return 0;
}