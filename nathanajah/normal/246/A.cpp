//nathanajah's template
//25-10-2012
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
#define LL long long
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int arr[10];
int n;
int i,j;
int tmp;
int main()
{
	scanf("%d",&n);
	if (n<=2)
		printf("-1\n");
	else
		for (i=n;i>=1;--i)
			printf("%d ",i);
}