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

int n,q,i;
vector <int> adj[100005];
int l[100005];
int r[100005];
int k[100005];
int ans[100005];
int le[100005];
int ri[100005];
int ind[100005];
int num[100005];
int sum[100005];
int balik[100005];
int color[100005];
int now = 0;
int kBuk = 400;
int co[100005];
void dfs(int x, int p) {
  int i;
  co[now] = color[x];
  le[x] = now++;
  for (i = 0; i < SZ(adj[x]); ++i) {
    if (adj[x][i] != p)
      dfs(adj[x][i], x);
  }
  ri[x] = now;
}

bool cmp(int a, int b) {
  if (l[a]/kBuk != l[b]/kBuk)
    return l[a]/kBuk < l[b]/kBuk;
  return r[a] < r[b];
}
int main()
{
  scanf("%d",&n);
  scanf("%d",&q);
  for (i = 0; i < n; i++)
    scanf("%d",&color[i]);
  for (i = 0; i < n - 1; i++) {
    int a,b;
    scanf("%d %d", &a, &b);
    --a;--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  for (i = 0; i < q; i++) {
    int tmp;
    scanf("%d %d", &tmp, &k[i]);
    --tmp;
    l[i] = le[tmp];
    r[i] = ri[tmp];
    ind[i] = i;
  }
  sort(ind, ind + q, cmp);
  int lenow = 0;
  int rinow = 0;
  
  for (i = 0; i < q; i++) {
    while (lenow < l[ind[i]]) {
      sum[num[co[lenow]]]--;
      num[co[lenow]]--;
      lenow++;
    }
    while (lenow > l[ind[i]]) {
      --lenow;
      num[co[lenow]]++;
      sum[num[co[lenow]]]++;
    }
    while (rinow < r[ind[i]]) {
      num[co[rinow]]++;
      sum[num[co[rinow]]]++;
      rinow++;
    }
    while (rinow > r[ind[i]]) {
      rinow--;
      sum[num[co[rinow]]]--;
      num[co[rinow]]--;
    }
    ans[ind[i]] = sum[k[ind[i]]];
  }
  for ( i = 0; i < q; i++)
    printf("%d\n",ans[i]);
}