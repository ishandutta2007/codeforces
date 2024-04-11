#include <cstdio>
using namespace std;

bool dem[10000001];
int A[5000];
int N,K;
int main()
{
	for(int i=0;i<=10000000;i++)
		dem[i] = 0;
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		dem[A[i]] = 1;
	}
	dem[0] = 1;
	int Q;
	scanf("%d",&Q);
	int x;
	int cur;
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&x);
		bool good = 0;
		for(int k=1;k<=K;k++)
		{
			for(int j=0;j<N;j++)
			{
				for(int c=0;c<k;c++)
					if(((x-c*A[j])>=0)&&(!((x-c*A[j])%(k-c)))&&(((x-c*A[j])/(k-c))<=10000000)&&(dem[(x-c*A[j])/(k-c)]))
					{
						printf("%d\n",k);
						good = 1;
						break;
					}
				if(good)
					break;
				if(x==k*A[j])
				{
					printf("%d\n",k);
					good = 1;
					break;
				}
				if(good)
					break;
			}
			if(good)
				break;
		}
		if(!good)
			printf("-1\n");
	}
}