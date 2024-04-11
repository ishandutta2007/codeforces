#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tans[1000005],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int nw=(i-1)/2;
		if(nw<=m)
		{
			tans[++t]=i;
			m-=nw;
			continue;
		}
		tans[++t]=i+(i-(m+1)*2);
		m=0;
		break;
	}
	if(m)
	{
		printf("-1");
		return 0;
	}
	for(int i=t+1;i<=n;i++)
		tans[i]=1e8+i*(tans[t]+1);
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}