#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, a[1000005], g[1000005], ans = 0, c[1000005];

int abs (int k)
{
	if (k < 0)
		k *= -1;
	return k;
}                      

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &a[i], &g[i]);
	for (int i = 0; i < N; i++)
	{
		ans += a[i];
		if (ans > 500)
		{
			c[i] = 2;
			ans -= 1000;
		}
		else               
			c[i] = 1;   
	}
	if (abs(ans) > 500)
	{
		printf("-1\n");
		return 0;
	}	
	for (int i = 0; i < N; i++)
		if (c[i] == 1)
			printf("A");
		else
			printf("G");
	return 0;
}