#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

const int maxn = 10000;

long long  n, m, k, r[maxn], p1[maxn], p2[maxn], A, B, maxr, l;
long double max1 = -1e9;

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &r[i]);
	sort(r, r + n);
	int maxr = r[n - 1];
	scanf("%I64d", &m);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &p1[i]);
	scanf("%I64d", &k);
	for (int i = 0; i < k; i++)
		scanf("%I64d", &p2[i]);
	sort(p2, p2 + k);
	l = p2[0];
	scanf("%I64d%I64d", &A, &B);
	for (int i = 0; i < m; i++)      
		if (sqrt((long double) (maxr * maxr * p1[i] * B) / (long double) (l * A + p1[i] * B)) > max1)
			max1 = sqrt((long double) (maxr * maxr * p1[i] * B) / (long double) (l * A + p1[i] * B));
	cout.precision(20);
	cout << max1 << endl;
	return 0;
}