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

int n,x;
bool bisa;
int x1,x2;
int i;

int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	bisa=true;
	for (i=0;i<n;++i)
	{
		scanf("%d %d",&x1,&x2);
		if (x1==x || x1==7-x || x2==x || x2==7-x)
			bisa=false;
	}
	if (bisa)
		printf("YES\n");
	else
		printf("NO\n");
}