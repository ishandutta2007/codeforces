#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
#define ld long double
#define sqr(x) ((ld)(x) * (x))
const ld eps = 1e-12;
int n, h;
int X[N], Y[N];
ld Getdis(int i){return sqrt(sqr(X[i + 1] - X[i]) + sqr(Y[i + 1] - Y[i]));}
int main()
{
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &X[i], &Y[i]);
	ld ans = Getdis(n - 1);
	ld w = (ld)(Y[n] + h - Y[n - 1]) / (X[n] - X[n - 1]);
	ld v = Y[n] + h - w * X[n];
	for (int i = n - 2; i >= 1; i--)
	{
		ld k = (ld)(Y[i + 1] - Y[i]) / (X[i + 1] - X[i]);
		ld b = Y[i] - k * X[i];
		if (fabs(k - w) < eps)
		{
			if (v < b + eps)
				ans += Getdis(i);
		}
		else
		{
			if (w > k)
			{
				ld x = (v - b) / (k - w);
				x = min(x, (ld)X[i + 1]);
				x = max(x, (ld)X[i]);
				ans += (x - X[i]) / (X[i + 1] - X[i]) * Getdis(i);
			}
		}
		if (w * X[i] + v < Y[i])
		{
			w = (ld)(Y[n] + h - Y[i]) / (X[n] - X[i]);
			v = Y[n] + h - w * X[n];
		}
	}
	printf("%.12lf\n", (double)ans);
}