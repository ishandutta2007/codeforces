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
const int NMAX = 5555;

int n, m, w, q;
vector<pii> stores[NMAX];
vector<int> head[NMAX];
int d[NMAX];
queue<int> Q;
priority_queue<pii> H;

int calc(int g, int r, int a) {
  while (!Q.empty()) Q.pop();
  while (!H.empty()) H.pop();
  FOR (i, 1, n) d[i] = -1;
  Q.push(g);
  d[g] = 0;
  ll prices = 0;
  int cnt = 0;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    //BUG(u);
    // add shovel
    for (pii v : stores[u]) {
      //cout << v.FI << " " << v.SE << endl;

      if (cnt < r) {
        int take = min(r - cnt, v.SE);
        prices += (ll) take * v.FI;
        cnt += take;
        v.SE -= take;
        H.push(pii(v.FI, take));
      }

      while (v.SE > 0) {
        pii t = H.top();
        if (v.FI >= t.FI) break;
        H.pop();
        int replace = min(v.SE, t.SE);
        prices += (ll) replace * (v.FI - t.FI);
        v.SE -= replace;
        H.push(pii(v.FI, replace));
        if (t.SE > replace) H.push(pii(t.FI, t.SE - replace));
      }
    }

    // if ans found
    if (cnt == r && prices <= a) return d[u];

    // add nodes
    for (int v : head[u]) if (d[v] == -1) {
      d[v] = d[u] + 1;
      Q.push(v);
    }
  }
  return -1;
}

int main() {
  cin >> n >> m;
  FOR (i, 1, m) {
    int u, v;
    cin >> u >> v;
    head[u].PB(v); head[v].PB(u);
  }

  cin >> w;
  FOR (i, 1, w) {
    int u, v, t;
    cin >> u >> v >> t;
    stores[u].PB(pii(t, v));
  }

  FOR (i, 1, n) sort(stores[i].begin(), stores[i].end());

  cin >> q;
  FOR (i, 1, q) {
    int u, v, t;
    cin >> u >> v >> t;
    cout << calc(u, v, t) << endl;
  }
}