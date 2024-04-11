//nathanajah's template
//28-11-2012
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
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE

int n,m;
vector <int> bisa[205];
int parent[205];
int rank[205];
int i,j;
int kosong;
bool sudah[205];
bool adaisi;

int root(int x)
{
	if (parent[x]==x)
		return x;
	parent[x]=root(parent[x]);
	return parent[x];
}

void join(int x, int y)
{
	x=root(x);y=root(y);
	if (x==y)
		return;
	if (rank[x]<rank[y])	
		parent[x]=y;
	else if (rank[x]>rank[y])	
		parent[y]=x;
	else
	{
		++rank[x];
		parent[y]=x;
	}
}


int main()
{
	memset(parent,-1,sizeof(parent));
	scanf("%d %d",&n,&m);
	for (i=0;i<n;++i)
	{
		int banyak=0;
		scanf("%d",&banyak);
		if (banyak==0)
			++kosong;
		else
		{
			adaisi=true;
			int awal;
			scanf("%d",&awal);
			if (parent[awal]==-1)
				parent[awal]=awal;
			int tmp;
			for (j=1;j<banyak;++j)
			{
				scanf("%d",&tmp);
				if (parent[tmp]==-1)
					parent[tmp]=tmp;
				join(awal,tmp);
			}
		}
	}
	for (i=0;i<200;++i)
	{
		if (parent[i]!=-1)
		{
			if (!sudah[root(i)])
			{
				sudah[root(i)]=true;
				++kosong;
			}
		}
	}
	if (!adaisi)
		++kosong;
	printf("%d\n",kosong-1);
}