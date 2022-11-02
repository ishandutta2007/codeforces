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

int n;
LL arr[2005][2005];
LL sumdiag1[5000];
LL sumdiag2[5000];
int i,j;
int main()
{
  scanf("%d", &n);
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      scanf("%I64d", &arr[i][j]);
      sumdiag1[i-j + 2005] += arr[i][j];
      sumdiag2[i+j] += arr[i][j];
    }
  }
  LL maxgen = 0,maxgan=0;
  LL xgen, xgan, ygan, ygen;
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      if ((i+j)%2 == 0) {

        maxgen = max(maxgen, sumdiag1[i-j+2005] + sumdiag2[i+j] - arr[i][j]);
        if (maxgen ==  sumdiag1[i-j+2005] + sumdiag2[i+j] - arr[i][j]) {
          xgen = i;
          ygen = j;
        }
      }
      else {
        maxgan = max(maxgan, sumdiag1[i-j+2005] + sumdiag2[i+j] - arr[i][j]);
        if (maxgan ==  sumdiag1[i-j+2005] + sumdiag2[i+j] - arr[i][j]) {
          xgan = i;
          ygan = j;
        }
      }
    }
  }
  printf("%I64d\n", maxgen + maxgan);
  printf("%I64d %I64d %I64d %I64d\n", xgen+1, ygen+1, xgan+1, ygan+1);
}