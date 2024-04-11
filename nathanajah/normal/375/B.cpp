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
char c[5005][5005];
int tmp[5005];
int cnt[5005];
int main()
{
  scanf("%d %d",&n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      c[i][j] = getc();
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (c[j][i] == '0')
        cnt[j] = 0;
      else
        cnt[j]++;
    }
    for (int j = 0; j < n; j++)
      tmp[j] = cnt[j];
    sort(tmp, tmp+n, greater<int>());
    for (int j = 0; j < n; j++) {
      ans = max(ans, tmp[j] * (j+1));
    }
  }
  printf("%d\n",ans);
}