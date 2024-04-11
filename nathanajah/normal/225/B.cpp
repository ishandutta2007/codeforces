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

int n,m;
vector <int> bonac;
queue <int> now;
int i,j;
vector <int> hasil;
int sumnow;

int main()
{
	scanf("%d %d",&n,&m);
	bonac.push_back(1);
	now.push(1);
	sumnow=1;
	while (sumnow<=n)
	{
		now.push(sumnow);
		bonac.push_back(sumnow);
		sumnow+=sumnow;
		while (now.size()>m)
		{
			sumnow-=now.front();
			now.pop();
		}
	}
	for (i=bonac.size()-1;i>=0;--i)
	{
		if (n>=bonac[i])
		{
			n-=bonac[i];
			hasil.push_back(bonac[i]);
		}
	}
	if (hasil.size()==1)
		hasil.push_back(0);
	printf("%d\n",hasil.size());
	for (i=0;i<hasil.size();++i)
		printf("%d ",hasil[i]);
	printf("\n");
}