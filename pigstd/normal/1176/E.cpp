#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int T,n,a[M];
struct edge
{
	int to,next;
}e[M<<1];int cnt,head[M];

void add(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

void dfs(int u)
{
	for (int i=head[u];i;i=e[i].next)
	{
		int to=e[i].to;
		if (a[to])continue;
		a[to]=a[u]+1;
		dfs(to);
	}
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();int m=read();cnt=0;
		for (int i=1;i<=n;i++)head[i]=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			add(u,v),add(v,u);
		}
		for (int i=1;i<=n;i++)a[i]=0;
		a[1]=1;dfs(1);int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]&1)cnt++;
//			cout<<a[i]<<' ';
		}
		if (cnt<=n/2)
		{
			cout<<cnt<<endl;
			for (int i=1;i<=n;i++)
				if (a[i]&1)cout<<i<<' ';
		}
		else
		{
			cout<<n-cnt<<endl;
			for (int i=1;i<=n;i++)
				if (!(a[i]&1))cout<<i<<' ';
		}
		puts("");
	}
	return 0;
}