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
int n,k,d;
int res[1005][1005];
int main()
{
  scanf("%d %d %d",&n, &k, &d);
  LL tmp  = 1;
  int i;
  bool can = false;
  for (i= 1; i <= d; i++) {
    tmp = tmp * k;
    if (tmp >= n) {
      can = true;
      break;
    }
  }
  if (!can) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int haha = i;
    for (int j = 0; j< d; j++) {
      res[j][i] = (haha%k)+1;
      haha = haha / k;
    }
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j< n; j++) {
      if ( j> 0)
        printf(" ");
      printf("%d",res[i][j]);
    }
    printf("\n");
  }
}