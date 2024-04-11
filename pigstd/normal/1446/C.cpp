#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=6e6+10;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int son[M][2],tot=1,n;

void insert(int x)
{
	int now=1;
	for (int i=30;i>=0;i--)
	{
		int k=(x>>i)&1;
		if (!son[now][k])son[now][k]=++tot;
		now=son[now][k];
	}
}

int dfs(int now)
{
	if (!son[now][0]&&!son[now][1])return 1;
	if (!son[now][0])return dfs(son[now][1]);
	if (!son[now][1])return dfs(son[now][0]);
	return max(dfs(son[now][0]),dfs(son[now][1]))+1;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		insert(read());
	cout<<n-dfs(1);
	return 0;
}