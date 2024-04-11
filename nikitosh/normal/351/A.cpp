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

#define FNAME "1"
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

int n, a[4005], sum, l, m1 = (int) 1e9, m2, s, k;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%d.%d", &k, &a[i]);
		sum += a[i];
		if (a[i] != 0)
			l++;
	}
	//printf("%d\n", sum);
	//l = min(l, n);
	//m1 = abs(sum - l * 1000);
	for (int i = max(0, l - n); i <= min(l, n); i++)
		m1 = min(m1, abs(sum - i * 1000));
	printf("%d.", m1 / 1000);
	m2 = m1 % 1000;
	if (m2 < 100)
		printf("0");
	if (m2 < 10)
		printf("0");
	printf("%d\n", m2);
	return 0;
}