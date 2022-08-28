#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,x,nw,vis[1000005];
int main()
{
	scanf("%d%d",&m,&x);
	for(int i=1;i<=m;i++)
	{
		int nx;
		scanf("%d",&nx);
		vis[nx%x]++;
		while(vis[nw%x]) vis[nw%x]--,nw++;
		printf("%d\n",nw);
	}
	return 0;
}