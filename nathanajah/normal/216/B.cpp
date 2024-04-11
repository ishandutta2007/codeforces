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

vector <int> arc[200];
bool sudah[200];
int n,m;
int i,j;
int v1,v2;
int sznow;
int res;
bool cyc;

void dfs(int x)
{
	++sznow;
	int i;
	int banyak;
	for (i=0;i<arc[x].size();++i)
	{
		if (!sudah[arc[x][i]])
		{
			sudah[arc[x][i]]=true;
			++banyak;
			dfs(arc[x][i]);
		}
	}
	if (arc[x].size()!=2)
		cyc=false;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<m;++i)
	{
		scanf("%d %d",&v1,&v2);
		arc[v1].push_back(v2);
		arc[v2].push_back(v1);
	}
	for (i=1;i<=n;++i)
	{
		if (!sudah[i])
		{
			cyc=true;
			sznow=0;
			sudah[i]=true;
			dfs(i);
			if (cyc && sznow%2==1)
				++res;
		}
	}
	if ((n-res)%2==1)
		++res;
	printf("%d\n",res);
}