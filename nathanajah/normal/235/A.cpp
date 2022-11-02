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

long long n,i;

int main()
{
	scanf("%I64d",&n);
	if (n==1)
		printf("1\n");
	else if (n==2)
		printf("2\n");
	else
	{
		if (n%2==0)
		{
			if (n%3==0)
				printf("%I64d\n",(n-1)*(n-2)*(n-3));
			else
				printf("%I64d\n",n*(n-1)*(n-3));
		}
		else
		{
			printf("%I64d\n",n*(n-1)*(n-2));
		}
	}
}