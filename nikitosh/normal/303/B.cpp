#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, x, y, a, b, l, g, len_x, len_y, min_x, min_y, max_x, max_y;

int gcd (int k, int l)
{
	if (l == 0)
		return k;
	else
		return gcd(l, k % l);
}                                     

int main()
{
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
	g = gcd(a, b);
	a /= g;
	b /= g;
	l = min(n / a, m / b);
	len_x = l * a;
	len_y = l * b;
	min_x = max(0, x - len_x / 2 - len_x % 2);
	min_y = max(0, y - len_y / 2 - len_y % 2);
	max_x = min(n, x + len_x / 2);
	max_y = min(m, y + len_y / 2);
	if (min_x == 0)
		max_x = len_x;
	if (max_x == n)
		min_x = max_x - len_x;
	if (min_y == 0)
		max_y = len_y;
	if (max_y == m)
		min_y = max_y - len_y;
	printf("%d %d %d %d\n", min_x, min_y, max_x, max_y);
	return 0;
}