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
vector <int> child[100005];
LL MOD = 1000000007;

LL pow (LL x, LL y) {
  if (y == 0)
    return 1;
  LL tmp = pow(x, y/2);
  tmp = (tmp * tmp)%MOD;
  if (y%2 == 1)
    tmp = (tmp * x)% MOD;
  return tmp;
}

LL inv(LL x) {
  return pow(x, MOD-2);
}

LL dp[100005][2];
int n,i;
int col[100005];

LL hitung(LL x, LL y) {
  int i;
  LL &ret = dp[x][y];
  if (ret >= 0)
    return ret;
  if (y == 0 && col[x] == 1)
    return 0;
  if (SZ(child[x]) == 0) {
    if (col[x] == y)
      return 1;
    return 0;
  }
  ret = 1;
  if (y == 0 || (col[x] == 1 && y == 1)) {
    for (i=0;i<SZ(child[x]); i++) {
      ret = (ret * (hitung(child[x][i], 0) + hitung(child[x][i], 1)))%MOD;
    }
  }
  else {
    LL tmp = 1;
    ret = 0;
    for (i=0;i<SZ(child[x]); i++) {
      tmp = (tmp * (hitung(child[x][i],0) + hitung(child[x][i],1))) % MOD;
    }
    for (i=0;i<SZ(child[x]); i++) {
      LL tmpc;
      tmpc = (tmp * inv(hitung(child[x][i],0) + hitung(child[x][i],1)))%MOD;
      tmpc = (tmpc * hitung(child[x][i], 1))%MOD;
      ret = (ret + tmpc)%MOD;
    }
  }
  return ret;
}
int main()
{
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for (i=1;i<n;i++) {
    int p;
    scanf("%d", &p);
    child[p].pb(i);
  }
  for (i=0;i<n;i++)
    scanf("%d", &col[i]);
  printf("%I64d\n", hitung(0, 1));
}