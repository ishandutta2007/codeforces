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

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

struct graph {
 vi g[500];
 vector <string> names;
 int comp[500];
 bool root[500];
 int tin[500];
 int tout[500];
 int timer;

 graph() { memset(root, 1, sizeof root); };

 int addV ( string it ) {
  names.pb(it);
  return (int)names.size() - 1;
 }

 void addE ( int a, int b ) {
  g[a].pb(b); root[b] = 0;
 }

 void dfs(int v) {
  tin[v] = timer++;

  forn(i, g[v].size())
   comp[g[v][i]]  = comp[v], dfs(g[v][i]);

  tout[v] = timer++;
 }

 bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
 }

 int calc () {
  memset(comp, -1, sizeof comp);

  int comps = 0;
  timer = 0;
  forn(i, names.size())
   if  (root[i])
    comp[i] = comps++, dfs(i);

  int res = 0;
  forn(i, names.size())
   forn(j, names.size())
    if  (i != j && names[i] == names[j] && comp[i] == comp[j] && upper(i, j)) res++;
  return res;
 }

};

char s[1010];
graph g;

pii GetVertex ( int pos ) {

 string name = "";
 int i = pos;
 while (s[i] >= 'A' && s[i] <= 'Z')
  name += s[i++];

 int u = g.addV(name);
 if  (s[i] == '.') return mp(i+1, u);

 
 i++;
 while (1) {
  pii cur = GetVertex(i);
  g.addE(u, cur.s);
  i = cur.f;
  if  (s[i] == '.') break;
  i++;
 }

 return mp(i+1, u);
}
 
int main() {
  gets(s);

  int i = 0;
  while (1) {
   pii cur = GetVertex(i);
   i = cur.f;
   if  (s[i] < 'A' || s[i] > 'Z') break;
  }

  printf("%d\n", g.calc());

  return 0;
}