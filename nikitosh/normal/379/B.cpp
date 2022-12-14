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

int n, a[1005];

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);    
	for (int g = 0; g < 1000; g++)
    {
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > 0)
			{
				printf("P");
	    		a[i]--;
	    	}
	    	printf("R");
	    }
	    for (int i = n - 1; i > 0; i--)
		{
			if (a[i] > 0)
			{
				printf("P");
	    		a[i]--;
	    	}
	    	printf("L");
	    }
	}
	return 0;
}