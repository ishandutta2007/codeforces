#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int n,de[M];double ans;
vector<int> e[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void dfs(int u,int fa)
{
	de[u]=de[fa]+1,ans+=1.0/de[u];
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to!=fa)dfs(to,u);
	}
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),to=read();
		e[u].push_back(to),e[to].push_back(u);
	}
	dfs(1,0);printf("%.10lf",ans);
	return 0;
}