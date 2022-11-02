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

int n,m,x,y;
int i,j;
char c[1005][1005];
int sum[1005][1005];
int dp[1005][2];

int getkolb(int x, int y)
{
	return sum[n][y]-sum[n][x-1];
}
int hitung(int a, int tip)
{
	int &ret=dp[a][tip];
	if (ret>=0)
		return ret;
	if (a==0)
		return 0;
	int i;
	ret=1000000000;
	for (i=x;i<=y;++i)
	{
		if (a-i>=0)
		{
			if (tip==0)
				ret=min(ret,getkolb(a-i+1,a)+hitung(a-i,!tip));
			else
				ret=min(ret,i*n-getkolb(a-i+1,a)+hitung(a-i,!tip));
		}
	}
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j)
		{
			c[i][j]=' ';
			while (c[i][j]==' ' || c[i][j]=='\n')
				scanf("%c",&c[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if (c[i][j]=='#')
				sum[i][j]+=1;
		}
	}
	printf("%d\n",min(hitung(m,0),hitung(m,1)));
}