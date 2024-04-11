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
LL n,m,w;
LL arr[100005];
LL i;
LL tambah[100005];

LL hitung(LL x) {
  LL res = 0;
  memset(tambah,0,sizeof(tambah));
  LL i;
  LL now = 0;
  for (i=0;i<n;i++) {
    now += tambah[i];
    tambah[min(n,i+w)] += -max(0LL, x - arr[i] - now);
    res += max(0LL, x - arr[i] - now);
    now += max(0LL, x - arr[i] - now);
  }
  return res;
}
int main()
{
  scanf("%I64d %I64d %I64d",&n, &m, &w);
  for (i=0;i<n; i++)
    scanf("%I64d", &arr[i]);
  LL l,mid,r;
  l = 0;
  r = 2000000000;
  
  while (l < r) {
    mid = (l+r + 1)/2;
    if (hitung(mid) <= m) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  printf("%I64d\n",l);
}