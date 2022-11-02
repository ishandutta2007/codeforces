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
#define LL long long
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,m,i,j,k;
char c[500][500];
int suma[500][500];
int banyakchara[30];
int banyakcharb[30];
int atas,bawah;
LL res;

char getc()
{
	char c;
	c=' ';
	while (c==' ' || c=='\r' || c=='\t' || c=='\n')
		c=getchar();
	return c;
}
int getsum(int x1,int y1, int x2, int y2)
{
	return suma[x2][y2]-suma[x1-1][y2]-suma[x2][y1-1]+suma[x1-1][y1-1];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j)
		{
			c[i][j]=getc();
			if (c[i][j]=='a')
				suma[i][j]=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1]+1;
			else
				suma[i][j]=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1];
		}
	}
	for (i=1;i<=n;++i)
		for (j=i;j<=n;++j)
		{
			for (bawah=0;bawah<26;++bawah)
			{
				banyakchara[bawah]=0;
				banyakcharb[bawah]=0;
			}
			atas=1;
			for (bawah=1;bawah<=m;++bawah)
			{
				while (getsum(i,atas,j,bawah)>k)
				{
					if (c[i][atas]==c[j][atas])
						++banyakchara[c[i][atas]-'a'];
					++atas;
				}
				if (c[i][bawah]==c[j][bawah])
				{
					if (i!=j && bawah>atas)
					{
						res+=(LL)(banyakcharb[c[i][bawah]-'a']-banyakchara[c[i][bawah]-'a']);
					}
					++banyakcharb[c[i][bawah]-'a'];
				}
			}
		}
	printf("%I64d\n",res);
}