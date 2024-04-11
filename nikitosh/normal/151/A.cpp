#include<cstdio>
#include<algorithm>

using namespace std;

int n, k, l, c, d, p, nl, np, z;

int main()
{
	scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
	z = min((k * l) / nl, min(c * d, p / np));
	printf("%d\n", z / n);
	return 0;
}