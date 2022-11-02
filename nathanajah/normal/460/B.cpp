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
LL a, b, c;
LL i;

LL sumdigit(LL x) {
  LL res = 0;
  while (x > 0) {
    res += x%10;
    x/=10;
  }
  return res;
}
int main()
{
  vector <LL> res;
  scanf("%I64d %I64d %I64d",&a, &b, &c);
  for (i = 0; i<= 81; i++) {
    LL pang = 1;
    for (int j = 0;j < a; j++)
      pang = pang * i;
    LL x = b * pang + c;
    if (x > 0 && x < 1000000000) {
      if (sumdigit(x) == i)
        res.pb(x);
    }
  }
  printf("%d\n",res.size());
  for (i=0;i<SZ(res);++i)
    printf("%I64d ",res[i]);
  printf("\n");
}