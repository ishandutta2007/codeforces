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

int n, m, a[505][505], used[100105], min1 = (int) 1e9, ans; 

bool prime (int k)
{
	if (k == 1)
		return 0;
	for (int i = 2; i * i <= k; i++)
		if (k % i == 0)
			return 0;
	return 1;
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = (int) 1e5 + 100; i > 0; i--)
		if (prime(i))
			used[i] = i;
		else
			used[i] = used[i + 1]; 
	for (int i = 0; i < n; i++)
	{
		ans = 0;
		for (int j = 0; j < m; j++)
			ans += used[a[i][j]] - a[i][j];
		min1 = min(min1, ans);
	}
	for (int i = 0; i < m; i++)
	{
		ans = 0;
		for (int j = 0; j < n; j++)
			ans += used[a[j][i]] - a[j][i];
		min1 = min(min1, ans);
	}
	printf("%d\n", min1);
	return 0;
}