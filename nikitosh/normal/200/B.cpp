#include<cstdio>

int N, p[1000], i, sum;

int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &p[i]);  
		sum += p[i];
	}
	printf("%.20lf", (double) sum / (double) N); 
	return 0;
}