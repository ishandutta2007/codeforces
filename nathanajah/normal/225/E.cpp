#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

long long MOD=1000000007;
long long moddiv (long long x, long long y)
{
	if (y==0)
		return 1;
	else
	{
		long long res=moddiv(x,y/2);
		res=(res*res)%MOD;
		if (y%2==1)
			res=(res*x)%MOD;
		return res;
	}
}
int p[50]={2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583};
int n;
long long hasil;

int main()
{
	scanf("%d",&n);
	--n;
	hasil=moddiv(2,p[n]-1);
	hasil=(hasil+MOD-1)%MOD;
	printf("%I64d\n",hasil);
}