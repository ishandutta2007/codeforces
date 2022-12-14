#include<cstdio>
#include<algorithm>

using namespace std;

int N, l[200000], r[200000], min1 = (int) 1E9 + 10, max1 = -1;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		min1 = min(min1, l[i]);
		max1 = max(max1, r[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (l[i] == min1 && r[i] == max1)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("%d\n", -1);
	return 0;
}