#include <bits/stdc++.h>

constexpr int N = 1e6 + 50;

int p[N];

void outtt(int x)
{
	if (p[x]) outtt(p[x]);
	printf("%d ", x);	
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		scanf("%d", p + i);
	outtt(n);
	return 0;	
}