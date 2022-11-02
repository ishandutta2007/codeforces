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

int n,m,k;
int i,j;
deque <int> kerja;
vector <int> jawab;

int hitung(int x)
{
	if (kerja.size()==0)
		return 0;
	int i;
	i=0;
	int res=0;
	while (x-kerja[i]<n)
	{
		++res;
		++i;
		if (i==kerja.size())
			break;
	}
	return res;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (i=0;i<n+m;++i)
	{
		
		while (i-kerja[0]>=n)
		{
			kerja.pop_front();
			if (kerja.size()==0)
				break;
		}
		int tmp=hitung(i);
		if (tmp<k)
		{
			for (j=0;j<k-tmp;++j)
			{
				kerja.push_back(i);
				jawab.push_back(i);
			}
		}
		while (i+1-kerja[0]>=n)
		{
			kerja.pop_front();
			if (kerja.size()==0)
				break;
		}
		if (hitung(i+1)==0)
		{
			kerja.push_back(i);
			jawab.push_back(i);
		}
	}
	printf("%d\n",jawab.size());
	for (i=0;i<jawab.size();++i)
		printf("%d ",jawab[i]+1);
	printf("\n");
}