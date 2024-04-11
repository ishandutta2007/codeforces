#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int N, k, i, sum;

int main()
{
	scanf("%d", &N);
	sum = N;
	while(N != 1)
	{                 
		for (i = 2; i <= sqrt(N); i++)
			if (N % i == 0 && N % (N / i) == 0)
			{
				k = N / i;
				break;
			}
		if (k == N)
		{
			sum += 1;
			break;
		}                
		sum += k;
		N = k;
	}
	printf("%d", sum);
	return 0;
}