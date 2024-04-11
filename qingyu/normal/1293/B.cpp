#include <bits/stdc++.h>

const int N = 5e5 + 50;

int main()
{
	int n;
	scanf("%d", &n);
	long double f = 0;
	for (int i = 1; i <= n; ++i) f += 1.0L / i;
	double answer = f;
	printf("%.12f", answer);
}