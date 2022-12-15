#include<cstdio>

int n,t,x,ans;

int main()
{
	scanf("%d%d",&n,&t); ans=n-1;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		ans+=x;
	}
	if (t!=ans) printf("NO\n"); else printf("YES\n");
	return 0;
}