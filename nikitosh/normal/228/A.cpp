#include<cstdio>
#include<algorithm>

using namespace std;

int ans, a[10];

int main()
{
	scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
	a[0] = -1;
	sort(a, a + 5);
	for (int i = 1; i < 5; i++)
		if (a[i] != a[i - 1])
			ans++;
	printf("%d\n", 4 - ans);
	return 0;
}