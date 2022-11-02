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
int dp[300005][2];
int last[300005];
int i,j;
vector <pair<int, pair<int,int> > > edgeList;
int main()
{
  scanf("%d %d",&n,&m);
  for (i=0;i<m;i++) {
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    --a;--b;
    edgeList.pb(mp(c,mp(a,b)));
  }
  for (i=0;i<n;++i)
    dp[i][0] = 0;
  for (i=0;i<n;++i)
    last[i] = -1;
  sort(edgeList.begin(), edgeList.end());
  int maxi = 0;
  for (i=0;i<SZ(edgeList);i++) {
    int a,b,c;
    c = edgeList[i].first;
    b = edgeList[i].se.fi;
    a = edgeList[i].se.se;
    if (last[b] < c ) {
      if (dp[b][0]+1 > dp[a][0]){
        if (last[a] < c)
          dp[a][1] = dp[a][0];
        dp[a][0] = dp[b][0] + 1;
        maxi = max (maxi, dp[a][0]);
        last[a] = c;
      }
    }
    else {
      if (dp[b][1]+1 > dp[a][0]){
        if (last[a] < c)
          dp[a][1] = dp[a][0];
        dp[a][0] = dp[b][1] + 1;
        maxi = max (maxi, dp[a][0]);
        last[a] = c;
      }
    }
  }
  printf("%d\n",maxi);
}