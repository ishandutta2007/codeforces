#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,col[105],num[105],k[105],i;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&col[i]);
	for(i=1;i<=m;i++) scanf("%d",&k[i]);
	for(i=1;i<=n;i++)
	{
		int u,j;
		memset(num,0,sizeof(num));
		for(j=i;j<=n;j++)
		{
			num[col[j]]++;
			for(u=1;u<=m;u++)	if(num[u]!=k[u]) break;
			if(u>m) break;
		}
		if(u>m) break;
	}
	if(i<=n) printf("YES");
	else printf("NO");
	return 0;
}