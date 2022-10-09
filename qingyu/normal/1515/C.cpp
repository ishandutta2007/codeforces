#include <bits/stdc++.h>

const int N = 1e5 + 50;

int g[N], h[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		std::priority_queue<std::pair<int, int>,
			std::vector<std::pair<int, int>>,
			std::greater<std::pair<int, int>>> q;
		int n, m, x;
		scanf("%d%d%d", &n, &m, &x);
		for (int i = 1; i <= n; ++i)
			scanf("%d", h + i);
		for (int i = 1; i <= m; ++i) q.emplace(0, i);
		for (int i = 1; i <= n; ++i)
		{
			auto [v, z] = q.top(); q.pop();
			g[i] = z;
			q.emplace(v + h[i], z);
		}
		puts("YES");
		for (int i = 1; i <= n; ++i) printf("%d ", g[i]); 
		putchar('\n');
	}
}