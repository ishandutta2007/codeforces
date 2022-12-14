#include<cstdio>
#include<algorithm>

using namespace std;

int N, a[100000], b[100000], c[100000], z = 0, k = 1, l = 0, i;

int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (i = 0; i < N; i++)
	{
		if (b[i] == 0)                                  
		{               
			c[z] = a[i];
			z++;
		}	
		if (b[i] != 0)
		{
			k += b[i] - 1;
			l+= a[i];
		}
	}
	if (z != 0)
	{
		sort(c, c + z);
		for (i = 0; i < z; i++)
			b[z - i - 1] = c[i];
		for (i = 0; i < min(k, z); i++)
			l += b[i];
	}
	printf("%d", l);
	return 0;
}