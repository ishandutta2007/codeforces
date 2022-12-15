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
const int NMAX = 1000;

int n;
int a[NMAX], b[NMAX];
vector<int> head[NMAX];
int deg[NMAX], res[NMAX], Fre[NMAX];

void add(int u, int v) {
  head[u].PB(v);
  deg[v]++;
  //cout << u << " " << v << endl;
}

bool lower(int i, int j, int ai ,int aj) {
  return ai > aj || (ai == aj && i < j);
}

int calc(int i, int j) {
  int tmp = 0;
  tmp += (lower(i, j, a[i], a[j]) && lower(j, i, a[j], b[i])) ||
         (lower(j, i, a[j], a[i]) && lower(i, j, b[i], a[j]));
  tmp += (lower(j, i, a[j], b[i]) && lower(i, j, b[i], b[j])) ||
         (lower(i, j, b[i], a[j]) && lower(j, i, b[j], b[i]));
  return tmp;
}

int main() {
  cin >> n;
  FOR (i, 1, n) {
    int u;
    cin >> a[i] >> u;
    b[i] = a[i] + u;
  }

  FOR (i, 1, n) FOR (j, 1, n) if (lower(i, j, a[i], a[j])) {
    if (lower(j, i, a[j], b[i]) && lower(i, j, b[i], b[j]))
      add(i, j);
    if (lower(j, i, b[j], a[i]) && lower(i, j, b[i], b[j]))
      add(j, i);
  }

  int ans = 0;
  FOR (i, 1, n) Fre[i] = true;
  FOR (i, 1, n) {
    int u = 0;
    FOR (j, 1, n) if (Fre[j] && deg[j] == 0) {
      u = j;
      break;
    }

    res[i] = u;
    Fre[u] = false;

    // calc result
    FOR (j, 1, i - 1) {
      ans += calc(res[j], res[i]);
    }

    REP (j, SZ(head[u])) {
      int v = head[u][j];
      deg[v]--;
    }
  }

  cout << ans << endl;
  // PR(res, 1, n);
  // PR(a, 1, n);
  // PR(b, 1, n);
}