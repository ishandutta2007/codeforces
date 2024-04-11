#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define pii pair <int, int>

using namespace std;

const int MAXN = 510;
int dist[MAXN][MAXN];
vector <int> ve[MAXN];
vector <int> V;
vector <int> tmp[MAXN];
int rez[MAXN];
int bio[MAXN];
int n;

void solve() {
  V.clear();
  REP(i, n) V.push_back(i);

  while (true) {
   // for (int x : V) cout << x << " "; cout << endl;

    int mini = 1000, sol = 0;
    for (int x : V) {
      int ma = 0, ind = 0;
      for (int y : ve[x]) {
        rez[y] = 0;
        for (int k : V) {
          if (dist[x][k] > dist[y][k]) {
            rez[y]++;
          }
        }
        if (rez[y] > ma) {
          ma = rez[y];
          ind = y;
        }
      }

      if (ma < mini) {
        mini = ma;
        sol = x;
      }
    }

    cout << sol + 1 << endl;

    string s;
    cin >> s;
    if (s == "FOUND") return;

    int y;
    cin >> y;
    y--;

    REP(i, V.size()) {
      int x = V[i];
      if (dist[sol][x] <= dist[y][x]) V.erase(V.begin() + i), i--;
      else if (x == sol) V.erase(V.begin() + i), i--;
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);

  int m;
  cin >> n >> m;

  REP(i, n) {
    REP(j, n) {
      dist[i][j] = MAXN;
    }
    dist[i][i] = 0;
  }

  REP(i, m) {
    int k;
    cin >> k;
    int a;
    cin >> a;
    a--;

    REP(j, k - 1) {
      int b;
      cin >> b;
      b--;

      ve[a].push_back(b);
      ve[b].push_back(a);
      dist[a][b] = 1;
      dist[b][a] = 1;
      a = b;
    }
  }

  REP(k, n) {
    REP(i, n) {
      REP(j, n) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    } 
  }

  REP(i, n) solve();

  return 0;
}