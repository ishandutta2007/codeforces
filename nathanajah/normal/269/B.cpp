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
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
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
//ENDOFTEMPLATE

int n,m;
vector <double> daftar[100005];
int s[100005];
double x[100005];
int i,j;
int v1;
double v2;

int dp[6000][6000];
int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<n;++i)
	{
		scanf("%d %lf",&v1,&v2);
		daftar[v1].push_back(i);
	}
	for (i=1;i<=m;++i)
	{
		int mininow=dp[i-1][0];
		for (j=0;j<=n;++j)
		{
			int banyakkanan=(lower_bound(daftar[i].begin(),daftar[i].end(),j)-daftar[i].begin());
			banyakkanan=daftar[i].size()-banyakkanan;
			dp[i][j]=mininow+banyakkanan;
			int bkiri=daftar[i].size()-banyakkanan;
			mininow=min(mininow,dp[i-1][j+1]+bkiri);
		}
	}
	int mini=1000000000;
	for (i=0;i<=n;++i)
		mini=min(mini,dp[m][i]);
	printf("%d\n",mini);
}