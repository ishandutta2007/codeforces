#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int temp, n, k, pig = 0;
	freopen("input.txt", "r", stdin);
	scanf(" %d %d", &n, &k);
	for(int i = 0; i < n; i ++)
	{
		scanf(" %d", &temp);
		if(temp > 3 * k)
			pig += temp - 3 * k;
		else
			pig += temp % k;
	}
	fclose(stdin);
	freopen("output.txt", "w", stdout);
	printf("%d\n", pig);
	fclose(stdout);
	return 0;
}