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

int n,m,i,j;

LL coltree[1000000];
LL lazyadd[1000000];
LL lazycol[1000000];

LL getNod(int l, int r, int x) {
  return coltree[x] + (LL)(r-l+1) * lazyadd[x];
}

void upd(int a, int b, int l, int r, int x, int newCol) {
  int m = (l+r)/2;
  if (a == l && b == r) {
    if (lazycol[x] == 0) {
      upd(l, m, l, m, 2*x+1, newCol);
      upd(m+1, r, m+1, r, 2*x+2, newCol);
      lazycol[x] = newCol;
      coltree[x] = getNod(l, m, 2*x+1) + getNod(m+1, r, 2*x+2);
    }
    else {
      lazyadd[x] += abs(lazycol[x] - newCol);
      lazycol[x] = newCol;
    }
  }
  else {
    if (lazycol[x] != 0) {
      lazyadd[2*x+1] += lazyadd[x];
      lazyadd[2*x+2] += lazyadd[x];
      lazycol[2*x+1] = lazycol[x];
      lazycol[2*x+2] = lazycol[x];
      lazycol[x] = 0;
      lazyadd[x] = 0;
    }
    if (b <= m) {
      upd(a, b, l, m, 2*x+1, newCol);
    } else if ( a > m) {
      upd(a, b, m+1, r, 2*x+2, newCol);
    } else {
      upd(a, m, l, m, 2*x+1, newCol);
      upd(m+1, b, m+1, r, 2*x+2, newCol);
    }
    coltree[x] = getNod(l, m, 2*x+1) + getNod(m+1, r, 2*x+2);
  }
}

LL get(int a, int b, int l, int r, int x) {
  if (a == l && b == r){
    return getNod(l, r, x);
  }
  else {
    if (lazycol[x] > 0) {
      lazyadd[2*x+1] += lazyadd[x];
      lazyadd[2*x+2] += lazyadd[x];
      lazyadd[x]= 0;
      lazycol[2*x+1] = lazycol[x];
      lazycol[2*x+2] = lazycol[x];
      lazycol[x] = 0;
    }
    int m = (l+r)/2;
    LL ret = 0;
    if (b <= m)
      ret = get(a, b, l, m, 2*x+1);
    else if (a > m)
      ret = get(a, b, m+1, r, 2*x+2);
    else
      ret = get(a, m, l, m, 2*x+1) + get(m+1, b, m+1, r, 2*x+2);
    coltree[x] = getNod(l, m, 2*x+1) + getNod(m+1, r, 2*x+2);
    return ret;
  }
}

void init(int l, int r, int x) {
  if (l == r)
    lazycol[x] = l+1;
  else {
    int m = (l+r)/2;
    init(l, m, 2*x+1);
    init(m+1, r, 2*x+2);
  }
}
int main()
{
  scanf("%d %d",&n, &m);
  init(0, n-1, 0);
  while (m--) {
    int typ;
    scanf("%d", &typ);
    int l,r,x;
    if (typ == 1) {
      scanf("%d %d %d", &l, &r, &x);
      --l;--r;
      upd(l, r, 0, n-1, 0, x);
    }
    else {
      scanf("%d %d", &l, &r);
      --l;--r;
      LL res = get(l, r, 0, n-1, 0);
      printf("%I64d\n", res);
    }
  }
}