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

int n, k;
char s[105];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d\n", &n, &k);
	gets(s);
	if (k <= n - k)
	{
		for (int i = 0; i < k - 1; i++)
			printf("LEFT\n");
		for (int i = 0; i < n - 1; i++)
		{
			printf("PRINT %c\n", s[i]);
			printf("RIGHT\n");	
		}
		printf("PRINT %c\n", s[n - 1]);
	}
	else
	{
		for (int i = 0; i < n - k; i++)
			printf("RIGHT\n");
		for (int i = n - 1; i > 0; i--)
		{
			printf("PRINT %c\n", s[i]);
			printf("LEFT\n");	
		}
		printf("PRINT %c\n", s[0]);
	}
	return 0;
}