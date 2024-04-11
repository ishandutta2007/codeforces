#include<cstdio>
#include<algorithm>

using namespace std;

int a, b, c, d, l;

int foo (int x, int y, int z)
{
	int sum = x + y + z;
	if (sum > 2 * max(max(x, y), z))
		return 3;
	if (sum == 2 * max(max(x, y), z))
		return 2;
	return 1;
}

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	l = max(max(max(foo(a, b, c), foo(a, b, d)), foo(a, c, d)), foo(b, c, d));
	if (l == 3)
		puts("TRIANGLE");
	if (l == 2)
		puts("SEGMENT");
	if (l == 1)
		puts("IMPOSSIBLE");
	return 0;
}