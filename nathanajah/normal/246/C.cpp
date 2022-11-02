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

int n,m,i,j,k;
set <int> sudah;
vector <vector <int> > daftar;
vector <vector <int> > add;
vector <int> jumlahadd;
vector <int> jumlah;
vector <int> tmp;
int arr[100];

int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	sudah.insert(0);
	daftar.push_back(tmp);
	jumlah.push_back(0);
	for (i=0;i<n;++i)
	{
		for (j=0;j<add.size();++j)
		{
			daftar.push_back(add[j]);
			jumlah.push_back(jumlahadd[j]);
			if (daftar.size()>m)
				break;
		}
		add.clear();
		jumlahadd.clear();
		if (daftar.size()>m)
			break;
		for (j=0;j<jumlah.size();++j)
		{
			if (sudah.find(jumlah[j]+arr[i])==sudah.end())
			{
				jumlahadd.push_back(jumlah[j]+arr[i]);
				sudah.insert(jumlah[j]+arr[i]);
				tmp.clear();
				for (k=0;k<daftar[j].size();++k)
					tmp.push_back(daftar[j][k]);
				tmp.push_back(arr[i]);
				add.push_back(tmp);
			}
		}
	}
	for (j=0;j<add.size();++j)
	{
		daftar.push_back(add[j]);
		jumlah.push_back(jumlahadd[j]);
		if (daftar.size()>m)
			break;
	}
	for (i=1;i<daftar.size();++i)
	{
		printf("%d",daftar[i].size());
		for (j=0;j<daftar[i].size();++j)
			printf(" %d",daftar[i][j]);
		printf("\n");
	}
	printf("\n");
}