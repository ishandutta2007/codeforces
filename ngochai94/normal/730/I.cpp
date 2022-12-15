#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl;}
#define PB push_back
#define MP make_pair
#define BIT(s,i) (((s)&(1<<(i)))>0)
#define TWO(x) (1<<(x))
#define FI first
#define SE second
#define SZ(x) ((int)x.size())

const int MOD = 1000000007;
const double E = 1e-8;
const double PI = acos(-1);
const int NMAX = 5000;

struct edge {
  int x, y;
  int c, f, ts;
  int rev;
  edge(int x, int y, int c, int ts, int rev): x(x), y(y), c(c), ts(ts), rev(rev), f(0) {}
  edge() {}
};

int p, s;


int n;
bool Fre[NMAX];
int d[NMAX];
queue<int> Q;
vector<edge> head[NMAX];
pii trace[NMAX];

void addEdge(int x, int y, int c, int ts) {
  int nx = SZ(head[x]);
  int ny = SZ(head[y]);
  head[x].PB(edge(x, y, c, ts, ny));
  head[y].PB(edge(y, x, 0, -ts, nx));
}

bool findpath(int st, int fn) {
  FOR (i, 0, fn) {
    Fre[i] = true;
    d[i] = -MOD;
  }
  while (!Q.empty()) Q.pop();
  Q.push(st); Fre[st] = false;
  d[st] = 0;

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    Fre[u] = true;
    REP (i, SZ(head[u])) {
      int v = head[u][i].y;
      if (head[u][i].f < head[u][i].c && d[v] < d[u] + head[u][i].ts) {
        d[v] = d[u] + head[u][i].ts;
        trace[v] = pii(u, i);
        if (Fre[v]) {
          Fre[v] = false;
          Q.push(v);
        }
      }
    }
  }
  return d[fn] != -MOD;
}

pii flow(int st, int fn) {
  int res = 0;
  int cost = 0;
  while (findpath(st, fn)) {
    res++;
    cost += d[fn];
    int u = fn;
    while (u != st) {
      int v = trace[u].FI, i = trace[u].SE, j = head[v][i].rev;
      head[v][i].f ++;
      head[u][j].f --;
      u = v;
    }
  }
  return pii(res, cost); // max flow and its cost
}

int main() {
  cin >> n >> p >> s;
  FOR (i, 1, n) {
    int u; cin >> u;
    addEdge(i, n + 1, 1, u);
  }

  FOR (i, 1, n) {
    int u; cin >> u;
    addEdge(i, n + 2, 1, u);
  }

  FOR (i, 1, n) addEdge(0, i, 1, 0);
  addEdge(n + 1, n + 3, p, 0);
  addEdge(n + 2, n + 3, s, 0);

  pii res = flow(0, n + 3);
  vector<int> ans_p, ans_s;
  FOR (u, 1, n) {
    REP (i, SZ(head[u])) if (head[u][i].f > 0){
      if (head[u][i].y == n + 1)
        ans_p.PB(u);
      else if (head[u][i].y == n + 2)
        ans_s.PB(u);
    }
  }

  cout << res.SE << endl;
  REP (i, SZ(ans_p)) cout << ans_p[i] << " ";
  cout << endl;
  REP(i, SZ(ans_s)) cout << ans_s[i] << " ";
  cout << endl;
}