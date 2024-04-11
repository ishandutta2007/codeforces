#include<cstdio>
#include<algorithm>

using namespace std;

int n, k, a[100];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j >= 0; j--)
		{
			if (k == 0)
				break;
			k--;
			printf("%d ", i + 1);
			for (int g = 0; g < i; g++)
				printf("%d ", a[n - g - 1]);
			printf("%d\n", a[j]);
		}
	}
	return 0;
}