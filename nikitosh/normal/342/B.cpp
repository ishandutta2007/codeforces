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

int n, m, s, f, t[100005], l[100005], r[100005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &n, &m, &s, &f);
	t[0] = 0;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &t[i], &l[i], &r[i]);	
	t[m + 1] = (int) 1e9;
	for (int i = 1; i <= m + 1; i++)
	{
		for (int j = t[i - 1] + 1; j < t[i]; j++)
		{
			if (s == f)
				return 0;
			if (s < f)
			{
				s++;
				printf("R");
			}	
			else
			{
				s--;
				printf("L");
			}
		}
		if (s == f)
			return 0;
		if (s < f)
		{
			if (s + 1 < l[i] || s > r[i])
			{
				s++;
				printf("R");
			}
			else
				printf("X");
		}
		else
		{
			if (s - 1 > r[i] || s < l[i])
			{
				s--;
				printf("L");
			}
			else
				printf("X");
		}
	}	
	return 0;
}