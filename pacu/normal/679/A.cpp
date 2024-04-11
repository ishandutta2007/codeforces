#include <cstdio>
using namespace std;

int ps[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main()
{
	int num = 0;
	char ans[10];
	for(int i=0;i<15;i++)
	{
		printf("%d\n",ps[i]);
		fflush(stdout);
		scanf("%s",ans);
		if(ans[0]=='y')
		{
			for(int j=i;j<15 && ps[i]*ps[j] <= 100;j++)
			{
				printf("%d\n",ps[i]*ps[j]);
				fflush(stdout);
				scanf("%s",ans);
				if(ans[0]=='y')
				{
					printf("composite\n");
					return 0;
				}
			}
			printf("prime\n");
			return 0;
		}
	}
	printf("prime\n");
	return 0;
}