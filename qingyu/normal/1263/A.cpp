#include <cstdio>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a > b) std::swap(a, b);
		if (a > c) std::swap(a, c);
		if (b > c) std::swap(b, c);
		int ans = 0, delta = c - b;
		c -= std::min(a, delta); ans += std::min(a, delta);a -= std::min(a, delta); 
		int remain = a / 2;
		b -= remain; a -= remain; ans += 2 * remain;
		ans += std::min(b, c);
		printf("%d\n", ans);
	}
}