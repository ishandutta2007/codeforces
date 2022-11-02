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
int i,j;
LL arr[1005][1005];
LL ul[1005][1005];
LL ur[1005][1005];
LL dl[1005][1005];
LL dr[1005][1005];
int main()
{
  scanf("%d %d", &n, &m);
  for (i=1;i<=n; i++)
    for (j=1;j<=m; j++)
      scanf("%I64d", &arr[i][j]);
  for (i=1;i<=n; i++)
    for (j=1;j<=m;j++)
      ul[i][j] = max(ul[i-1][j], ul[i][j-1]) + arr[i][j];
  for (i=1;i<=n; i++)
    for (j=m;j>=1;j--)
      ur[i][j] = max(ur[i-1][j], ur[i][j+1]) + arr[i][j];
  for (i=n;i>=1; i--)
    for (j=1;j<=m;j++)
      dl[i][j] = max(dl[i+1][j], dl[i][j-1]) + arr[i][j];
  for (i=n;i>=1; i--)
    for (j=m;j>=1;j--)
      dr[i][j] = max(dr[i+1][j], dr[i][j+1]) + arr[i][j];
  LL res = -1;
  for (i=2;i<n; i++)
    for (j=2;j<m;j++){
      res = max(res, ul[i-1][j] + dr[i+1][j] + ur[i][j+1] + dl[i][j-1]);
      res = max(res, ul[i][j-1] + dr[i][j+1] + ur[i-1][j] + dl[i+1][j]);
    }
  printf("%I64d\n", res);
}