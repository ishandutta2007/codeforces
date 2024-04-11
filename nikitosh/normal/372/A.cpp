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

int n, a[600005], l, r, m;

bool check (int k)
{
	for (int i = k - 1; i >= 0; i--)
		if (a[i] * 2 > a[n + i - k])
			return 0;		
	return 1;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	l = 0;
	r = n / 2 + 1;
	while(r - l > 1)
	{
		m = (r + l) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	printf("%d\n", n - l);
	return 0;
}