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
const int INT_INF = 2*(int)1e9;
const i64 I64_INF = (i64)1e18;
const double PI = acos(-1.0);
const int MAXN = 1000;

using namespace std;

struct edge {
 int v, to, cap, c, flow;
 edge(int v = 0, int to = 0, int cap = 0, int c = 0) : v(v), to(to), cap(cap), c(c) { flow = 0; }
};

struct graph {
 vector <edge> e;
 vi g[MAXN];
 int d[MAXN];
 int prevE[MAXN];
 int s, t;
 int N;

 graph() { N = 0; s = t = -1; }

 void addE ( int a, int b, int cap, int c ) {                                  
    g[a].pb((int)e.size());
    e.pb(edge(a, b, cap, c));

    g[b].pb((int)e.size());
    e.pb(edge(b, a, 0, -c));

    N = max(N, max(a, b));
 }

 void ass(int S, int T) {
    s = S; t = T;
 }

 int IncFlow() {
    for (int i = 0; i <= N; i++) d[i] = INT_INF, prevE[i] = -1;
    d[s] = 0;
        
        forn(i, N + 1)
            forn(j, e.size()) {
                int a = e[j].v; int b = e[j].to;
                if  (e[j].cap == e[j].flow || d[a] == INT_INF || d[b] <= d[a] + e[j].c) continue;
                d[b] = d[a] + e[j].c;
                prevE[b] = j;
            }

        if  (d[t] == INT_INF) return 0;

        int v = t;

        int flow = INT_INF;
        while (v != s) {
            flow = min(e[prevE[v]].cap - e[prevE[v]].flow, flow);
            v = e[prevE[v]].v;
        }

        v = t;
        while (v != s) {
            e[prevE[v]].flow += flow;
            e[prevE[v]^1].flow -= flow;
            v = e[prevE[v]].v;
        }
        
        return flow;
 }

 pii MinCostMaxFlow() {
  if  (s == -1)
    s = 0, t = N;
  
  int Flow = 0;
  while (1) {
    int pushed = IncFlow();
    if  (pushed > 0)
        Flow += pushed;
    else
        break;
  }

  int Cost = 0;

  forn(i, e.size())
    if  (e[i].flow > 0)
        Cost += e[i].flow * e[i].c;

  return mp(Cost, Flow);
 }

} g;

char t[110];
char s[110][110];
int n;
int a[110];
int cnt[110][30];
int cntt[30];

int main() {
  gets(t);

  memset(cntt, 0, sizeof cntt);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; t[i]; i++)
    cntt[t[i] - 'a']++;

  scanf("%d\n", &n);
  forn(i, n) {
    int sz = 0; char c = getchar();
    while (c != ' ') s[i][sz++] = c, c = getchar();
    scanf("%d\n", &a[i]);

    for (int j = 0; j < sz; j++)
        cnt[i][s[i][j] - 'a']++;

    g.addE(0, i + 1, a[i], 0);

    for (int j = 'a'; j <= 'z'; j++)
        g.addE(i + 1, n + 1 + j - 'a', cnt[i][j - 'a'], i + 1);
  }

  for (int i = 'a'; i <= 'z'; i++)
    g.addE(n + 1 + i - 'a', n + 'z' - 'a' + 2, cntt[i - 'a'], 0);

  pii r = g.MinCostMaxFlow();
  if  (r.s < (int)strlen(t)) 
    puts("-1");
  else
    printf("%d ", r.f);
  return 0;
}