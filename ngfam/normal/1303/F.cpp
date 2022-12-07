#include<bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct DSU{
  int edges;
  vector<int> par;
  vector<pair<int, int>> edges_change;
  DSU(){}
  DSU(int N){
    edges = 0;
    par.reserve(N);
    par.resize(N, -1);
  }
  int find(int x, int t) {
    return par[x] < 0 ? x : par[x] = find(par[x], t);
  }
  bool join(int x, int y, int t) {
    assert(x < par.size());
    assert(y < par.size());
    x = find(x, t); y = find(y, t );
    if(x == y) return false;
    if(par[x] > par[y]) swap(x, y);
    edges_change.emplace_back(t, edges++);
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  void rollback(int t) {
    while(edges_change.size() && edges_change.back().first >= t) {
      edges = edges_change.back().second;
      edges_change.pop_back();
    }
  }
};

const int MAXM = 305;
const int MAXN = 2000200;

int c[MAXN];
int x[MAXN];
int y[MAXN];
vector<pair<int, int>> query[MAXN], cells[MAXN];

vector<DSU> dsu;
int t[MAXM][MAXM], a[MAXM][MAXM], have[MAXM][MAXM];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;

  dsu.resize(MAXN);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j) {
      cells[0].emplace_back(i, j);
    }
  }

  for(int i = 0; i < q; ++i) {
    cin >> x[i] >> y[i] >> c[i];
    --x[i]; --y[i];
    if(a[x[i]][y[i]] == c[i]) continue;

    assert(c[i] < dsu.size());

    query[a[x[i]][y[i]]].emplace_back(x[i], y[i]);
    cells[c[i]].emplace_back(x[i], y[i]);
    a[x[i]][y[i]] = c[i];
  }

  for(int i = 0; i < MAXN; ++i) {
    if(!cells[i].size()) continue;
    dsu[i] = DSU(cells[i].size());
    sort(cells[i].begin(), cells[i].end());
  }

  auto getid = [&](int c, int x, int y) {
    assert(c < MAXN);
    return lower_bound(cells[c].begin(), cells[c].end(), make_pair(x, y)) - cells[c].begin();
  };

  auto work = [&](int c) {
    dsu[c].rollback(0);
    fill(dsu[c].par.begin(), dsu[c].par.end(), -1);
    for(int i = 0; i < query[c].size(); ++i) {
      t[query[c][i].first][query[c][i].second] = query[c].size() - i;
    }
    sort(cells[c].begin(), cells[c].end(), [&](pair<int, int> x, pair<int, int> y){
      return t[x.first][x.second] < t[y.first][y.second];
    });
    for(int i = 0; i < cells[c].size(); ++i) {
      int x = cells[c][i].first, y = cells[c][i].second;
      have[x][y] = i + 1;
      for(int d = 0; d < 4; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx == n || ny < 0 || ny == m || !have[nx][ny]) continue;
        if(dsu[c].join(have[x][y] - 1, have[nx][ny] - 1, t[x][y]));
      }
    }
    for(auto &p : cells[c]) {
      have[p.first][p.second] = 0;
    }
    for(int i = 0; i < query[c].size(); ++i) {
      t[query[c][i].first][query[c][i].second] = 0;
    }
  };

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) a[i][j] = 0;
  }

  int prep = 0, ans = 0;
  for(int i = 0; i < q; ++i) {
    while(prep < c[i]) {
      ans -= dsu[prep].edges;
      work(prep);
      ans += dsu[prep].edges;
      prep++;
    }
    if(c[i] == a[x[i]][y[i]]) {
      cout << n * m - ans << "\n";
      continue;
    }

    int cx = x[i], cy = y[i], last_color = a[cx][cy], new_color = c[i];

    ans -= dsu[last_color].edges;
    dsu[last_color].rollback(query[last_color].size());
    assert(query[last_color].size());
    query[last_color].pop_back();
    ans += dsu[last_color].edges;

    ans -= dsu[new_color].edges;
    for(int d = 0; d < 4; ++d){
      int nx = cx + dx[d], ny = cy + dy[d];
      if(nx < 0 || nx == n || ny < 0 || ny == m || a[nx][ny] != new_color) continue;
      dsu[new_color].join(getid(new_color, cx, cy), getid(new_color, nx, ny), 0);
    }
    ans += dsu[new_color].edges;
    a[cx][cy] = new_color;

    cout << n * m - (ans) << "\n";
  }

  return 0;
}