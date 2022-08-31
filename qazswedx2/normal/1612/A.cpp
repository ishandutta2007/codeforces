#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,x,y;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if((x+y)%2) printf("-1 -1\n");
		else
		{
			printf("%d %d\n",x/2,(y+x%2)/2);
		}
	}
	return 0;
}