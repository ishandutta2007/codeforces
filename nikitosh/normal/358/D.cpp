#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int n, a[3005], b[3005], c[3005], d[3005][3];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	d[0][0] = a[0];
	d[1][0] = a[0] + b[1];
	d[1][1] = a[1] + b[0];
	for (int i = 2; i < n; i++)
	{
		d[i][0] = max(d[i - 1][0], d[i - 1][1]) + b[i];
		d[i][1] = max(d[i - 1][0] - b[i - 1] + c[i - 1], d[i - 1][1] - a[i - 1] + b[i - 1]) + a[i];
	}
	printf("%d\n", max(d[n - 1][0], d[n - 1][1]));
	return 0;
}