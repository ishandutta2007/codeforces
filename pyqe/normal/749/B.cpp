#include <iostream>

using namespace std;

int main()
{
	long long a[3][2],i,j,x,y;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	printf("3\n");
	for(i=0;i<3;i++)
	{
		x=a[i][0]+a[(i+1)%3][0]-a[(i+2)%3][0];
		y=a[i][1]+a[(i+1)%3][1]-a[(i+2)%3][1];
		printf("%lld %lld\n",x,y);
	}
}