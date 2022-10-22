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

const int M=310;
int n,m,cnt,p[M*M],a[M*M],ppp[M*M];
map<int,int>t;
pair<int,int>pp[M*M];

struct BIT
{
	int c[M*M];
	int lowbit(int x){return x&(-x);}
	void update(int k,int x)
	{
		for (int i=k;i<=n*m;i+=lowbit(i))
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
		n=read(),m=read();cnt=0;t.clear();int res=0;
		for (int i=1;i<=n*m;i++)a[i]=p[i]=read();
		sort(p+1,p+1+n*m);
		for (int i=1;i<=n*m;i++)
			if (p[i]!=p[i-1])t[p[i]]=++cnt;
		for (int i=1;i<=n*m;i++)
			a[i]=t[a[i]],pp[i]=mp(a[i],i);
		sort(pp+1,pp+1+n*m);
		for (int i=1;i<=n;i++)
		{
			int cnt=1;
			for (int j=2;j<=m;j++)
			{
				if (pp[(i-1)*m+j].x!=pp[(i-1)*m+j-1].x)
					res-=cnt*(cnt-1)/2,cnt=0;
				cnt++;
			}
			res-=cnt*(cnt-1)/2;
		}
		for (int i=1;i<=n*m;i++)
			ppp[i]=pp[i].y;
		for (int i=1;i<=n;i++)
		{
			for (int j=m;j>=1;j--)
				res+=T.query(ppp[(i-1)*m+j]+1,n*m),
				T.update(ppp[(i-1)*m+j],1);
			for (int j=1;j<=m;j++)
				T.update(ppp[(i-1)*m+j],-1);
		}
		cout<<res<<endl;
	}
	return 0;
}
/*
1
4 2
50 50 50 50 3 50 50 50
*/