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

int n,i;
int arr[300005];
map<int,int> tmp;
int maxi,nummax;
int mini,nummin;
int main()
{
  scanf("%d",&n);
  for (i=0;i<n;++i) {
    scanf("%d",&arr[i]);
  }
  maxi = arr[0];
  mini = arr[0];
  for (i=1;i<n;++i) {
    maxi = max(maxi, arr[i]);
    mini = min(mini, arr[i]);
  }
  for (i=0;i<n;++i)
  {
    if (arr[i] == maxi)
      ++nummax;
    if (arr[i] == mini)
      ++nummin;
  }
  if (maxi == mini)
    printf("0 %I64d\n",((LL)n * (LL)(n-1))/2LL);
  else
    printf("%d %I64d\n", maxi-mini, (LL) nummax * (LL) nummin);
}