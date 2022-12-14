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

int h1, m1, h2, m2, t1, t2, t3;

void foo (int k)
{
	if (k >= 10)
		printf("%d", k);
	else
		printf("0%d", k);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
	t1 = 60 * h1 + m1;
	t2 = 60 * h2 + m2;
	t3 = t1 - t2;
	if (t3 < 0)
		t3 += 24 * 60;
	foo(t3 / 60);
	printf(":");	
	foo(t3 % 60);
	return 0;
}