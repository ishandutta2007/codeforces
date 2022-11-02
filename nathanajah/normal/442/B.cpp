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

double arr[100005];
int n,i;
int main()
{
  scanf("%d",&n);
  for (i=0;i<n;++i)
    scanf("%lf",&arr[i]);
  sort(arr, arr+n);
  double p0 = 1;
  double p1 = 0;
  for (i=n-1;i >=0;--i) {
    double n0 = p0 * (1-arr[i]);
    double n1 = (p0 * arr[i]) + p1 * (1-arr[i]);
    if (n1 <= p1 )
      break;
    p0 = n0;
    p1 = n1;
  }
  printf("%.10lf\n", p1);
}