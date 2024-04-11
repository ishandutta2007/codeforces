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
int arr[7] = {1869, 6189, 1689, 6198, 1698, 1986, 1896};
int cnt[50];
int main() {
  string s;
  s = GetString();
  for (int i = 0; i < SZ(s); i++)
    cnt[s[i]-'0']++;
  cnt[1]--;
  cnt[6]--;
  cnt[8]--;
  cnt[9]--;
  int now = 0;
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < cnt[i]; ++j) {
      printf("%d",i);
      now = (10 * now + i)%7;
    }
  }
    now = (now * 10000) % 7;
  printf("%d", arr[(7 - now)%7]);
  for (int i = 0; i < cnt[0]; ++i)
    printf("0");
  printf("\n");
}