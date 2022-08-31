# include <cstdio>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int sum1=0,sum2=0;
	for(int i=0;i<N;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		if(sum1+A>sum2+500)
		{
			printf("G");
			sum2+=B;
		}
		else
		{
			printf("A");
			sum1+=A;
		}
	}
	printf("\n");
	return 0;
}