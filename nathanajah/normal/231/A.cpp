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

int n,i,j;
int tmp;
int res;
int cnt;
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		cnt=0;
		for (j=0;j<3;++j)
		{
			scanf("%d",&tmp);
			cnt+=tmp;
		}
		if (cnt>1)
			++res;
	}
	printf("%d\n",res);
}