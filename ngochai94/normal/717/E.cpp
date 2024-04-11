#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

#define MAX 200111

int n;
vector<int> a[MAX];
int c[MAX];

vector<int> res;
bool visited[MAX];

void goTo(int u) {
  res.push_back(u);
  c[u] = -c[u];
}

int dfs(int u) {
  visited[u] = true;

  vector<int> children;
  REP (i, a[u].size()) {
    int v = a[u][i];

    if (!visited[v]) {
      goTo(v);
      dfs(v);
      goTo(u);
      if (c[v] == -1) {
        children.push_back(v);
      }
    }
  }

  REP (i, children.size()) {
    int v = children[i];

    goTo(v);

    if (u != 1) {
      goTo(u);
    } else {
      if (i + 1 < children.size()) {
        goTo(u);
      } else {
        if (c[u] == -1) {
          goTo(u);
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  FOR (i, 1, n) {
    scanf("%d", &c[i]);
  }

  REP (i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }

  res.push_back(1);
  dfs(1);

  REP (i, res.size()) printf("%d ", res[i]);
}