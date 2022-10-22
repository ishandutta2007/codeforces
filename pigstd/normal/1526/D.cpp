#pragma GCC optimize(3)
#pragma GCC optimize(2)
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

//ANTO 1 2 3 4
const int M=1e5+10;
int n,a[M],p[5],f[M],ans[5];
string s;

void work(int x)
{
	if (x==1)cout<<'A';
	if (x==2)cout<<'N';
	if (x==3)cout<<'T';
	if (x==4)cout<<'O';
}

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	void clear()
	{
		for (int i=1;i<=n;i++)c[i]=0;
	}
}T;

signed main()
{
	WT
	{
		cin>>s;n=s.size(); 
		for (int i=1;i<=n;i++)
		{
			if (s[i-1]=='A')a[i]=1;
			else if (s[i-1]=='N')a[i]=2;
			else if (s[i-1]=='T')a[i]=3;
			else a[i]=4;
		}int maxn=-1;
		for (int i=1;i<=4;i++)p[i]=i;
		for (int i=1;i<=24;i++)
		{
			int cnt=0;
			for (int j=1;j<=4;j++)
				for (int k=1;k<=n;k++)
					if (a[k]==p[j])f[++cnt]=k;
			int res=0;T.clear(); 
			for (int j=n;j>=1;j--)
			{
				res+=T.ask(f[j]-1);
				T.add(f[j],1);
			}
			if (res>maxn)
			{
				for (int i=1;i<=4;i++)ans[i]=p[i];
				maxn=res;
			}
			if (i!=24)
			next_permutation(p+1,p+1+4);
//			if (i==24)
//			{for (int i=1;i<=n;i++)cout<<f[i]<<' ';puts("");cout<<res<<endl;}
		}
//		for (int i=1;i<=4;i++)
//			cout<<ans[i]<<' ';
		for (int i=1;i<=4;i++)
			for (int j=1;j<=n;j++)
				if (a[j]==ans[i])work(ans[i]);
		puts("");//cout<<maxn<<endl;
	}
	return 0;
}
/*
1
OAANTTON

*/