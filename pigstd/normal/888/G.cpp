#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e5+10;
int n,ans;
map<int,int>t;

struct tire
{
	struct tree
	{
		int son[2];
	}t[M<<6];int cnt;
	void insert(int x)
	{
		int now=0;
		for (int i=30;i>=0;i--)
		{
			int p=(x&(1<<i))?1:0;
			if (!t[now].son[p])t[now].son[p]=++cnt;
			now=t[now].son[p];
		}
	}
	int find(int a,int b,int k)
	{
		if (k<=0)return 0;
		int a1=inf,a2=inf;
		if (t[a].son[0]&&t[b].son[0])a1=find(t[a].son[0],t[b].son[0],k-1);
		if (t[a].son[1]&&t[b].son[1])a2=find(t[a].son[1],t[b].son[1],k-1);
		if (min(a1,a2)!=inf)return min(a1,a2);
		if (t[a].son[0]&&t[b].son[1])a1=(1<<(k-1))+find(t[a].son[0],t[b].son[1],k-1);
		if (t[a].son[1]&&t[b].son[0])a2=(1<<(k-1))+find(t[a].son[1],t[b].son[0],k-1);
		return min(a1,a2);
	}
	void dfs(int now,int k)
	{
		if (k<=0)return;
		if (t[now].son[0]&&t[now].son[1])ans+=(1<<(k-1))+find(t[now].son[0],t[now].son[1],k-1);
		if (t[now].son[0])dfs(t[now].son[0],k-1);
		if (t[now].son[1])dfs(t[now].son[1],k-1);
	}
}T;


signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (t[x])continue;
		T.insert(x);t[x]=1;
	}
	T.dfs(0,31);cout<<ans<<endl;
	return 0;
}