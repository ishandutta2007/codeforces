#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()

const int MAXK = 45;
const int MAXN = 1005;

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int A[MAXN * MAXN];
int dist[MAXK][MAXN * MAXN]; // dist from color k to cell (i, j)
vector<pair<int, int>> color[MAXK];

int vis[MAXN * MAXN];
int used[MAXK];
int mark = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;


  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> A[i * MAXN + j];
      color[A[i * MAXN + j]].emplace_back(i, j);
    }
  }

  for (int k = 1; k <= K; k++) {
    mark++;
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (A[i * MAXN + j] == k) {
          q.emplace(i, j);
          vis[i * MAXN + j] = mark;
        }
      }
    }


    int step = -1;
    used[k] = mark;
    while (!q.empty()) {
      step++;
      int sz = sz(q);
      while (sz--) {
        pair<int, int> c = q.front();
        q.pop();
        dist[k][c.first * MAXN + c.second] = step;

        int cc = A[c.first * MAXN + c.second];
        if (used[cc] != mark) {
          for (auto &nxt : color[cc]) {
            if (vis[nxt.first * MAXN + nxt.second] == mark) {
              continue;
            }
            vis[nxt.first * MAXN + nxt.second] = mark;
            q.emplace(nxt);            
          }
          used[cc] = mark;
        }


        for (auto &d : dir) {
          pair<int, int> nxt = {c.first + d.first, c.second + d.second};
          if (!(1 <= nxt.first && nxt.first <= N && 1 <= nxt.second && nxt.second <= M)) {
            continue;
          }
          if (vis[nxt.first * MAXN + nxt.second] == mark) {
            continue;
          }
          vis[nxt.first * MAXN + nxt.second] = mark;
          q.emplace(nxt);
        }
      }
    }
  }

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans = abs(r2 - r1) + abs(c2 - c1);
    for (int k = 1; k <= K; k++) {
      ans = min(ans, dist[k][r1 * MAXN + c1] + dist[k][r2 * MAXN + c2] + 1);
    }
    cout << ans << "\n";
  }
  return 0;
}