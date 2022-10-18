#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define forn(i, n) for (int i = 0; i < (int)n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = (int) 1e5 + 10;
const int MAXLEN = 3 * (int) 1e5 + 10;

int n;
string s[MAXN];
vector <int> g[MAXN];
string t;
int ans = 0;

char a[MAXLEN];
int p[MAXLEN];
int sza = 0, szp = 0;

void push (char c) {
  a[sza++] = c;

  int i = sza - 1;
  int j = p[i - 1];
  while (j > 0 && a[j] != a[i]) j = p[j - 1];
  if  (a[j] == a[i]) j++;

  p[szp++] = j;

  if  (j == (int) t.length())
    ans++;
}

void pop () {
  sza--;
  szp--;
}

void dfs (int v, int p = -1) {
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];

    if  (to == p) continue;

    for (int j = 0; j < (int) s[to].length(); j++)
      push(s[to][j]);

    dfs(to, v);

    for (int j = 0; j < (int) s[to].length(); j++)
      pop(); 
  } 
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int p; scanf("%d ", &p); p--;
    g[p].pb(i);
    getline(cin, s[i]);
  }
  getline(cin, t);

  a[sza++] = t[0];
  p[szp++] = 0;

  for (int i = 1; i < (int) t.length(); i++)
    push(t[i]);
  push('#');

  dfs(0);

  printf("%d\n", ans);
  return 0;
}