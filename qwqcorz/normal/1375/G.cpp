#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int tot[2];
vector<int>e[N];
void dfs(int now,int father,int c)
{
	tot[c]++;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now,!c);
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
	dfs(1,0,0);
	print(min(tot[0],tot[1])-1);
	
	return 0;
}