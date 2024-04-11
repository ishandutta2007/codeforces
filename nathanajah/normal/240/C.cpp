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

int n;
int i,j;
int x,y;
vector <int> tmp;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	x=1;
	while (x<n)
	{
		x<<=1;
		++y;
	}
	printf("%d\n",y);
	for (i=0;i<y;++i)
	{
		tmp.clear();
		for (j=0;j<n;++j)
			if ((j&(1<<i))!=0)
				tmp.push_back(j+1);
		printf("%d",tmp.size());
		for (j=0;j<tmp.size();++j)
			printf(" %d",tmp[j]);
		printf("\n");
	}
}