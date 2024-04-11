#include<cstdio>
#include<algorithm>

using namespace std;

int N, x, k, i, z = 0, K, a[100000];

int main()
{
	scanf("%d%d", &N, &x);
	k = 0;
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < N; i++)
		if (a[i] == x)
			k = 1;
	K = N;
	if (k == 0)
	{
		z++;
		a[N] = x;          
		K++;
	}
	sort(a, a + K);
	if (a[(K + 1) / 2 - 1] == x)
	{
		printf("%d", z); 	
		return 0;
	}
	while (a[(K + 1) / 2 - 1] > x)
	{
		a[K] = 1;
		K++;
		z++;
		sort(a, a + K);
		if (a[(K + 1) / 2 - 1] == x)
		{
			printf("%d", z);
			return 0;
		}		
	}
	while (a[(K + 1) / 2 - 1] < x)
	{
		a[K] = 100000;
		K++;
		z++;
		sort(a, a + K);
		if (a[(K + 1) / 2 - 1] == x)
		{
			printf("%d", z);
			return 0;
		}		
	}
	return 0;
}