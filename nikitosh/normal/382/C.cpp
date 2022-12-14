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

int n, a[100005], b[100005];
vector <int> ans;

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
	if (n == 1)
	{
		puts("-1");
		return 0;
	}
	int boo = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != a[0])
			boo = 1;
	if (boo == 0)
	{
		printf("1\n%d\n", a[0]);
		return 0;
	}
	for (int i = 1; i < n; i++)
		b[i] = a[i] - a[i - 1];
	sort(b, b + n);
	if (n == 2)
	{              
		ans.pb(a[0] - (a[1] - a[0]));
		if ((a[0] + a[1]) % 2 == 0)
			ans.pb((a[0] + a[1]) / 2);
		ans.pb(a[1] + (a[1] - a[0]));
		printf("%d\n", (int) ans.size());
		for (int i = 0; i < (int) ans.size(); i++)
			printf("%d ", ans[i]);
		return 0;
	}
	if (b[1] == b[n - 1])
	{
		printf("2\n%d %d\n", a[0] - b[1], a[n - 1] + b[1]);
		return 0;
	}
	if (b[1] == b[n - 2] && b[n - 1] == 2 * b[1])
	{
		for (int i = 1; i < n; i++)
			if (a[i] - a[i - 1] == b[n - 1])
			{
				printf("1\n%d\n", (a[i] - a[i - 1]) / 2 + a[i - 1]);
				return 0;
			}	
	}
	puts("0");
	return 0;
}