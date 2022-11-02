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
int n, m;
int arr[100005];
long long dp[100005][2];
int num[100005];
int cnt[100005];

long long hitung(int ind, int prev) {
  if (ind == -1)
    return 0;
  long long &ret = dp[ind][prev];
  if (ret >= 0)
    return ret;
  ret = hitung(ind - 1, 0);
  if ((ind == m-1) || (num[ind] != num[ind+1]-1) ||
      (num[ind] == num[ind+1]-1 && prev == 0)){
    ret = max(ret, (long long)cnt[ind] * (long long)num[ind] + 
        hitung(ind - 1, 1));
  }
  return ret;
}
int main()
{
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  memset(dp,-1,sizeof(dp));
  sort(arr, arr+n);
  m = 0;
  num[m] = arr[0];
  cnt[m] = 1;
  m = 1;

  for (int i = 1; i < n; i++){
    if (arr[i] == arr[i-1])
      cnt[m-1] = cnt[m-1] + 1;
    else {
      num[m] = arr[i];
      cnt[m] = 1;
      ++m;
    }
  }
  printf("%I64d\n", hitung(m-1, 0));
}