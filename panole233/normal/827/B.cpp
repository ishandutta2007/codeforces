#include<bits/stdc++.h>
using namespace std;

int n,k,fa[200010],ans;

int main()
{
	scanf("%d%d",&n,&k),ans=2;
	for (int i=2; i<=k+1; i++) fa[i]=1;
	for (int i=k+2,nw=2; i<=n; i++,nw++)
	{
		if (nw==3) ans++;
		if (nw==k+2||nw==2) nw=2,ans++;
		fa[i]=fa[nw],fa[nw]=i;
	}
	printf("%d\n",ans);
	for (int i=2; i<=n; i++) printf("%d %d\n",i,fa[i]);
	return 0;
}