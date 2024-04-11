#include<bits/stdc++.h>
using namespace std;

int n,m,fa[100010],x,y;

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) fa[i]=i;
	int ans=0;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y),x=ask(x),y=ask(y);
		if (x==y) ans++; else fa[x]=y;
	}
	printf("%d\n",ans);
	return 0;
}