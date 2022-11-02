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

LL mini;
vector <LL> nummin;
LL l,r,k;
int main()
{
  mini = 1000000000000000LL;
  scanf("%I64d %I64d %I64d", &l, &r, &k);
  if (k >= 1) {
    if (l < mini) {
      mini = l;
      nummin = {l};
    }
  }
  if (k >= 2) {
    if ((l^(l+1)) < mini) {
      mini = l ^(l+1);
      nummin = {l, l+1};
    }
    if (l+2 <= r && ((l+1)^(l+2)) < mini) {
      mini = (l+1)^(l+2);
      nummin = {l+1, l+2};
    }
  }
  if (k >= 3) {
    for (LL i = 1; i<=45; i++){
      LL a = (1LL<<i) + (1LL << (i-1));
      LL b = a - 1;
      LL c = (1LL<<i) - 1;
      if (l <= c && a <= r) {
        if ((a^b^c) < mini) {
          mini = a^b^c;
          nummin = {a,b,c};
        }
      }
    }
  }
  if (k>=4) {
    if ((l^(l+1)^(l+2)^(l+3)) < mini) {
      mini = l^(l+1)^(l+2)^(l+3);
      nummin = {l, l+1, l+2, l+3};
    }
    if (l+4 <= r && ((l+1)^(l+2)^(l+3)^(l+4)) < mini) {
      mini = (l+1)^(l+2)^(l+3)^(l+4);
      nummin = {l+1, l+2, l+3, l+4};
    }
  }
  printf("%I64d\n",mini);
  printf("%d\n",nummin.size());
  for (auto a : nummin)
    printf("%I64d ",a);
}