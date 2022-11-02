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
int n,q;
int i;
int currentzero;
int bit[100005];

void upd(int x, int y) {
  while (x <=100000) {
    bit[x] += y;
    x += (x&(-x));
  }
}

int get(int x) {
  if (x == 0)
    return 0;
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= (x&-x);
  }
  return ret;
}

int main()
{
  scanf("%d %d", &n, &q);
  int front = 1;
  int back = n;
  bool reversed = false;
  for (i=1;i<=n;i++)
    upd(i,1);
  while (q--) {
    int qtyp;
    scanf("%d", &qtyp);
    if (qtyp == 1) {
      //fold
      int len;
      scanf("%d", &len);
      int num = back - front + 1;
      if (2 * len > num) {
        reversed = !reversed;
        len = num - len;
      }
      if (2*len <= num) {
        //just fold normally
        if (!reversed) {
          for (i=0;i<len; i++) {
            int prev = get(front + len - i - 1) - get(front + len - i - 2);
            upd(front + len + i, prev);
          }
          front += len;
        } else {
          for (i=0;i<len; i++) {
            int prev = get(back - len + i + 1) - get(back - len + i);
            upd(back - len - i, prev);
          }
          back -= len;
        }
      } 
    } else {
      int a,b;
      scanf("%d %d", &a, &b);
      //convert to my own coordinate
      if (!reversed) {
        a = front + a - 1;
        b = front + b - 1;
      } else {
        int tmpa = a;
        int tmpb = b;
        a = back - tmpb ;
        b = back - tmpa ;
      }
      printf("%d\n", get(b) - get(a));
    }
  }
}