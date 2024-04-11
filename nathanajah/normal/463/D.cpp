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
int n,k;
int arr[10][2005];
int i,j;
map <int,int> balik;
int pos[10][2005];
int dp[2005];
int main()
{
  scanf("%d %d", &n, &k);
  for (i=0;i<k;i++) {
    for (j=0;j<n;j++)
      scanf("%d",  &arr[i][j]);
  }
  for(i=0;i<n;i++) {
    balik[arr[0][i]] = i;
  }
  for (i=0;i<k;i++) {
    for (j=0;j<n;j++) {
      arr[i][j] = balik[arr[i][j]];
    }
  }
  for (i=0;i<k;i++) {
    for (j=0;j<n;j++)
      pos[i][arr[i][j]] = j;
  }
  dp[0] = 1;
  int maxi = 1;
  for (i=1;i<n;i++) {
    dp[i] = 1;
    for (j=0;j<i;j++) {
      bool can = true;
      for (int x = 0; x < k; x++) {
        if (pos[x][j] > pos[x][i])
          can = false;
      }
      if (can) {
        dp[i] = max(dp[i], dp[j]+1);
        maxi = max(maxi, dp[i]);
      }
    }
  }
  printf("%d\n", maxi);
}