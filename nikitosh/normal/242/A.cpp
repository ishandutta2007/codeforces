#include<cstdio>
#include<algorithm>

using namespace std;

int x, y, a, b, ans = 0;

int main()
{
	scanf("%d%d%d%d", &x, &y, &a, &b);
	for (int i = a; i <= x; i++)
		for (int j = b; j <= min(y, i - 1); j++) 
			ans++;
	printf("%d\n", ans);		
	for (int i = a; i <= x; i++)
		for (int j = b; j <= min(y, i - 1); j++) 
			printf("%d %d\n", i, j);
	return 0;
}