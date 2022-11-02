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

int n,c[200];
int arr[200][200];
int i,j;
int k,l;
vector <pair<pair<int,int>,pair<int,int> > > sswap;

int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&c[i]);
	for (i=0;i<n;++i)
		for (j=0;j<c[i];++j)
			scanf("%d",&arr[i][j]);
	for (k=0;k<n;++k)
		for (l=0;l<c[k];++l)
		{
			int mini=arr[k][l],numminx,numminy;
			for (i=0;i<n;++i)
				for (j=0;j<c[i];++j)
				{
					if (i>k || (i==k && j>l))
					{
						if (arr[i][j]<mini)
						{
							mini=arr[i][j];
							numminx=i;
							numminy=j;
						}
					}
				}
			if (mini<arr[k][l])
			{
				sswap.push_back(make_pair(make_pair(k+1,l+1),make_pair(numminx+1,numminy+1)));
				int tmp=arr[k][l];
				arr[k][l]=arr[numminx][numminy];
				arr[numminx][numminy]=tmp;
			}
		}
	printf("%d\n",sswap.size());
	for (i=0;i<sswap.size();++i)
		printf("%d %d %d %d\n",sswap[i].first.first,sswap[i].first.second,sswap[i].second.first,sswap[i].second.second);
}