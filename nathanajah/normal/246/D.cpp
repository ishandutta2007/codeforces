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

int n,m;
vector <int> vertices[100005];
vector <int> adj[100005];
int col[100005];
int i,j,k;
set <int> tmp;
int ctmp;
int v1,v2;
int maxi,nummax;

int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<n;++i)
	{
		scanf("%d",&ctmp);
		--ctmp;
		col[i]=ctmp;
		vertices[ctmp].push_back(i);
	}
	for (i=0;i<m;++i)
	{
		scanf("%d %d",&v1,&v2);
		--v1;--v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	maxi=-1;
	for (i=0;i<100005;++i)
	{
		if (vertices[i].size()!=0)
		{
			tmp.clear();
			for (j=0;j<vertices[i].size();++j)
			{
				for (k=0;k<adj[vertices[i][j]].size();++k)
				{
					if (col[adj[vertices[i][j]][k]]!=i)
						tmp.insert(col[adj[vertices[i][j]][k]]);
				}
			}
			if ((int)tmp.size()>maxi)
			{
				maxi=(int)tmp.size();
				nummax=i;
			}
		}
	}
	printf("%d\n",nummax+1);
}