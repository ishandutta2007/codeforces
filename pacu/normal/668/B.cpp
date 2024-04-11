#include <cstdio>
using namespace std;

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	int tp,x;
	int c0 = 0;
	int c1 = 0;
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d",&x);
			c0 = (c0+N+x)%N;
			c1 = (c1+N+x)%N;
		}
		else
		{
			if(c0%2 == 0)
			{
				c0 = (c0+1)%N;
				c1 = (c1+N-1)%N;
			}
			else
			{
				c1 = (c1+1)%N;
				c0 = (c0+N-1)%N;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(((i+N-c0)%N)%2 == 0) printf("%d ",(i+N-c0)%N + 1);
		else printf("%d ",(i+N-c1)%N + 1);
	}
	printf("\n");
}