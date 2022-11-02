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
vector <LL> daftar[100005];
LL n,m;
LL i;
LL arr[100005];
long long mini = 1000000000000000LL;
LL j;
int main()
{
  scanf("%I64d %I64d",&n, &m);
  for (i=0;i<m;++i) {
    scanf("%I64d",&arr[i]);
  }
  for (i=0;i<m;++i) {
    if (i < m-1 && arr[i] != arr[i+1])
      daftar[arr[i]].pb(arr[i+1]);
    if (i > 0 && arr[i] != arr[i-1])
      daftar[arr[i]].pb(arr[i-1]);
  }
  LL awal = 0;
  for (i=0;i<m-1;++i) {
    awal += (LL)abs(arr[i] - arr[i+1]);
  }
  
  for (i=1;i<=n;++i) {
    if (SZ(daftar[i])>0) {
      LL sumright = 0;
      LL sumleft = 0;
      sort(daftar[i].begin(),daftar[i].end());
      for (j=0;j<SZ(daftar[i]);++j)
        sumright += daftar[i][j];
      LL reg = 0;
      for (j=0;j<SZ(daftar[i]);++j)
        reg+=abs(i-daftar[i][j]);
      //first, di kiri daftar
      LL mininow = 1000000000000LL;
      if (daftar[i][0] > 1)
        mininow = sumright - ((LL)daftar[i][0]-1)*(LL)SZ(daftar[i]);
      for (j=0;j<SZ(daftar[i])-1;++j) {
        sumleft += daftar[i][j];
        sumright -= daftar[i][j];
        //possible value is from daftar[i][j] to daftar[i][j+1]]-1
        if (daftar[i][j+1]-1 >= daftar[i][j]) {
          //(j+1) * x - sumleft + sumright - (SZ(daftar[i][j])-j-1)*x
          if (2*j+2-SZ(daftar[i]) < 0){  //to minimize x must be as large as possible
            mininow = min(mininow, sumright - sumleft + ((LL)2*j+2-SZ(daftar[i]))*((LL)daftar[i][j+1]-1));
          }
          else {
            mininow = min(mininow, sumright - sumleft + ((LL)2*j+2-SZ(daftar[i]))*((LL)daftar[i][j]));
          }
        }
      }
      sumleft += daftar[i][SZ(daftar[i])-1];
      sumright -= daftar[i][SZ(daftar[i])-1];
      mininow = min(mininow, (LL)SZ(daftar[i])*((LL)daftar[i][SZ(daftar[i])-1]) - sumleft);
      mini = min(mini, mininow - reg);
    }
  }
  printf("%I64d\n",min(awal, awal + mini));
}