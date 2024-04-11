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

int x;
int i;

int main()
{
	scanf("%d",&x);
	if (x==1)
		printf("1\n");
	else if (x==2)
		printf("3\n");
	else if (x==3)
		printf("5\n");
	else
	{
		if (x%2==1)
			--x;
		if (x%4==2)
			x+=2;
		for (i=1;i<1000;i+=2)
		{
			int maxi=((i*i)+1)/2;
			if (x<=maxi)
				break;
		}
		printf("%d\n",i);
	}
}