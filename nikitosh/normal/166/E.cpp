#include<cstdio>

int i, N;
long long z, ps[10000001];
                        
int main()
{
	scanf("%d", &N);
	ps[1] = 3;
	for (i = 2; i < N; i++)
		ps[i] = (ps[i - 1] * 3) % 1000000007;
	for (i = N - 1; i >= 1; i--)
	{
		if ((N - 1 - i) % 2 == 0)
			z = z + ps[i];
		else
			z = z - ps[i]; 
	}
	z = z % 1000000007;
	if (z < 0)
		z += 1000000007; 

	printf("%I64d", z);
	return 0;
}