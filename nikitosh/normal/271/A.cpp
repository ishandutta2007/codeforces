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

int k, used[20];

bool foo (int k)
{
	for (int i = 0; i < 10; i++)
		used[i] = 0;
	while (k > 0)
	{                
		if (used[k % 10] > 0)
			return 0;
		used[k % 10] = 1;
		k /= 10;
	}
	return 1;  
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &k);
	while(1)
	{
		k++;
		if (foo(k))
		{
			printf("%d\n", k);
			return 0;
		}	
	}
	return 0;
}