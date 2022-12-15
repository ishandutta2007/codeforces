#include<cstdio>
#include<cstring>

int x,n,ans[300001],po;
bool bo[300001];

int main()
{
	scanf("%d",&n); ans[0]=1;
	memset(bo,0,sizeof(bo)); po=n;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x); bo[x]=1;
		while (bo[po]) po--;
		ans[i]=i-(n-po)+1;
	}
	for (int i=0; i<=n; i++) printf("%d ",ans[i]);
	return 0;
}