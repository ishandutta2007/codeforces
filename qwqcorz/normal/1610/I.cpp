#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
bool col[N];
int sg[N],fa[N];
void dfs(int now,int father)
{
	fa[now]=father;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		sg[now]^=sg[to]+1;
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	col[1]=1;
	int ans=sg[1];
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		for (int now=i;!col[now];now=fa[now])
		{
			col[now]=1,tot++;
			ans^=(sg[now]+1)^sg[now];
		}
		ans^=tot&1;
		putchar("21"[!!ans]);
	}
	
	return 0;
}