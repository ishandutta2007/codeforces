#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,val1=-1,vis1,val2=-1,vis2;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m+1;i++)
	{
		printf("? ");
		for(int j=1;j<=m+1;j++)
			if(j!=i) printf("%d ",j);
		printf("\n");
		fflush(stdout);
		int x,y;
		scanf("%d%d",&x,&y);
		if(val1==-1||val1==y)
		{
			vis1++;
			val1=y;
		}
		else if(val2==-1||val2==y)
		{
			vis2++;
			val2=y;
		}
	}
	if(val1>val2) swap(vis1,vis2),swap(val1,val2);
	printf("! %d\n",vis2);
	return 0;
}