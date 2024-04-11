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

int n,i,j,k,l;
int p;
int arr[60];
double dp[60][60][60];
double faktorial[60];
int sum;

int main()
{
	faktorial[0]=1;
	for (i=1;i<=50;++i)
		faktorial[i]=faktorial[i-1]*(double)i;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	scanf("%d",&p);
	if (sum<=p)
	{
		printf("%.20lf\n",(double)n);
		return 0;
	}
	double res=0;
	for (i=0;i<n;++i)
	{
		dp[i][0][0]=1;
		for (j=0;j<n;++j)
			if (j!=i)
			{
				for (k=50;k>=arr[j];--k)
					for (l=n;l>=0;--l)
					{
						dp[i][k][l]=dp[i][k-arr[j]][l-1]+dp[i][k][l];
					}
			}
		for (j=max(0,p-arr[i]+1);j<=p;++j)
			for (k=0;k<=n;++k)
			{
				res=res+(((faktorial[k]*faktorial[n-k-1])/faktorial[n])*dp[i][j][k]*(double)k);
			}
	}
	printf("%.20lf\n",res);
}