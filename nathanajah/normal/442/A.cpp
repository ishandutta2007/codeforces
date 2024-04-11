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

bool ada[25];


int conv(char c) {
  if (c == 'R')
    return 0;
  if (c == 'G')
    return 1;
  if (c == 'B')
    return 2;
  if (c == 'Y')
    return 3;
  if (c == 'W')
    return 4;
}

int main()
{
  int n;
  string s;
  int i,j,k;
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    s = GetString();
    ada[conv(s[0])*5 + s[1]-'1'] = true;
  }
  int mini = 1000000000;
  for (i=0; i < (1<<10); i++) {
    bool can = true;
    for (j=0;j<25;j++) {
      for (k = j+1; k < 25; k++)
        if (ada[j] && ada[k]) {
          int aj = j/5;
          int bj = j%5;
          int ak = k/5;
          int bk = k%5;
          int cj = (i & (1<<(aj+5))) == 0? 0 : 1;
          int dj = (i & (1<<bj)) == 0? 0 : 1;
          int ck = (i &  (1<<(ak+5))) == 0? 0 : 1;
          int dk = (i & (1<<bk)) == 0 ? 0 : 1;
          if (aj == ak &&  dj == 0 && dk == 0)
            can = false;
          if (bj == bk && cj == 0 && ck == 0)
            can = false;
          if (aj != ak && bj != bk && cj == 0 && ck == 0 && dk == 0 && dj == 0)
            can = false;
        }
    }
    if (can)
      mini = min (mini, __builtin_popcount(i));
  }
  printf("%d\n",mini);
}