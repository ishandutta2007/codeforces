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

vector <pair <int,int> > aa;
pair <int,int> tmp;
int a,b,x,y;
int i,j;

int main()
{
	scanf("%d %d %d %d",&x,&y,&a,&b);
	for (i=0;i<=x;++i)
		for (j=0;j<=y;++j)
			if (i>=a && j>=b && i>j)
				aa.push_back(make_pair(i,j));
	printf("%d\n",aa.size());
	for (i=0;i<aa.size();++i)
		printf("%d %d\n",aa[i].first,aa[i].second);
}