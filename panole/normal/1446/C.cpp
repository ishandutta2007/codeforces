#include<bits/stdc++.h>
using namespace std;

int n,ch[10000010][2],tot,x,ans;

void dfs(int x,int nw)
{
	if (ch[x][0]&&ch[x][1]) dfs(ch[x][0],nw+1),dfs(ch[x][1],nw+1);
	else if (ch[x][0]||ch[x][1]) dfs(ch[x][ch[x][1]>0],nw);
	else ans=max(ans,nw+1);
}

int main()
{
	ans=0;
	scanf("%d",&n),tot=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&x);
		int nw=0;
		for (int i=29; i>=0; i--)
		{
			if (!ch[nw][x>>i&1]) ch[nw][x>>i&1]=++tot;
			nw=ch[nw][x>>i&1];
		}
	}
	dfs(0,0);
	printf("%d\n",n-ans);
	return 0;
}