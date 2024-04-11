#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, s, k, a[N];
std::map<int, int> map;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		map.clear();
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 1; i <= k; ++i) 
		{
			scanf("%d", a + i);
			map[a[i]] = 1;
		}
		for (int i = 0; i <= n; ++i)
		{
			if (map.count(s - i) == 0 && s - i > 0) { printf("%d\n", i); break; }
			if (map.count(s + i) == 0 && s + i <= n) { printf("%d\n", i); break; }
		}
	}
}