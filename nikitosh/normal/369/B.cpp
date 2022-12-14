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

int n, k, l, r, s_all, s_k;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &s_all, &s_k);
	for (int i = 0; i < (s_k % k); i++)
		printf("%d\n", s_k / k + 1);		
	for (int i = 0; i < k - (s_k % k); i++)
		printf("%d\n", s_k / k);
	k = n - k;
	s_k = s_all - s_k;		
	if (k != 0)
	{
		for (int i = 0; i < (s_k % k); i++)
			printf("%d\n", s_k / k + 1);		
		for (int i = 0; i < k - (s_k % k); i++)
			printf("%d\n", s_k / k);
	}
	return 0;
}