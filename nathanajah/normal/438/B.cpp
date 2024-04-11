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
int n,m,i;
vector <int> adj[100005];
int v[100005];

int rrank[100005];
int parent[100005];
bool done[100005];
int size[100005];

int root(int x) {
  if (parent[x] == x)
    return parent[x];
  parent[x] = root(parent[x]);
  return parent[x];
}

void join(int x, int y) {
  x = root(x);
  y = root(y);
  if (rrank[x] > rrank[y]) {
    swap(x, y);
  }
  if (rrank[x] == rrank[y])
    ++rrank[y];
  size[y] += size[x];
  parent[x] = y;
}

int ind[100005];


bool cmp(int a, int b) {
  return v[a] > v[b];
}
int main()
{
  scanf("%d %d",&n, &m);
  for (i=0;i<n;++i)
    scanf("%d",&v[i]);
  for (i=0;i<m;++i) {
    int a,b;
    scanf("%d %d",&a, &b);
    --a;--b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for (i=0;i<n;++i)
    ind[i] = i;
  sort(ind, ind+n, cmp);
  for (i=0;i<n;++i) {
    parent[i] = i;
    rrank[i] = 0;
    size[i] = 1;
  }
  LL sum = 0;
  for (i=0;i<n;++i) {
    done[ind[i]] = true;
    for (int j = 0; j < SZ(adj[ind[i]]); ++j) {
      if (done[ind[i]] && done[adj[ind[i]][j]]) {
        int ri = root(ind[i]);
        int rj = root(adj[ind[i]][j]);
        if (ri != rj) {
          sum += (LL)size[ri] * (LL)size[rj] * (LL)v[ind[i]];
          join(ri, rj);
        }
      }
    }
  }
  printf("%.10lf\n", sum / (((LL)n*((LL)n-1))/2.0));
}