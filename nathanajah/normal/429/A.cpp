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
vector <int> adj[100005];
int init[100005];
int goal[100005];
int res = 0;
bool sudah[100005];
int ans[100005];

void dfs(int x, int prev2, int prev1) {
  int now = 0;
  if ((init[x] ^ prev2) != goal[x]) {
    now = 1;
    ans[x] = 1;
  }
  res += now;
  for (int i = 0;i < SZ(adj[x]); ++i) {
    if (!sudah[adj[x][i]]) {
      sudah[adj[x][i]] = true;
      dfs(adj[x][i], prev1, prev2 ^ now);  
    }
  }
}

int main()
{
  scanf("%d", &n);
  for (i=0;i<n-1;i++) {
    int a,b;
    scanf("%d %d", &a, &b);
    adj[a-1].pb(b-1);
    adj[b-1].pb(a-1);
  }
  for (i=0;i<n;i++)
    scanf("%d", &init[i]);
  for (i=0;i<n;i++)
    scanf("%d", &goal[i]);
  sudah[0] = true;
  dfs(0,0,0);
  printf("%d\n", res);
  for (i=0;i<n;i++)
    if (ans[i] == 1)
      printf("%d\n", i+1);
}