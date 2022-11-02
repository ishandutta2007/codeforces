#include <set>
#include <map>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct segm{
  int left, right, cost;
  segm(){
  }
  segm(int _left, int _right, int _cost){
    left = _left;
    right = _right;
    cost = _cost;
  }
};

segm combine(segm a, segm b){
  return segm(min(a.left, b.left), max(a.right, b.right), a.cost + b.cost);
}

void dfs1(int u, vector<int> &p, vector<bool> &used, vector<vector<int>> &G){
  used[u] = true;
  if (p[u] != -1){
    G[p[u]].emplace_back(u);
    if (!used[p[u]])
      dfs1(p[u], p, used, G);
  }
}

segm dfs2(int u, map<int, int> &x, vector<vector<int>> &G, vector<segm> &events){
  segm res;
  if (G[u].size() == 0){
    //cout << u << '\n';
    int i = x[u];
    res = segm(i, i, 0);
  } else {
    res = segm(x.size(), 0, 0);
  }
  for (int v: G[u]){
    auto tmp = dfs2(v, x, G, events);
    ++tmp.cost;
    events.emplace_back(tmp);
    res = combine(res, tmp);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<segm> events;

  int a;
  cin >> a;
  vector<int> p(a);
  p[0] = -1;
  for (int i = 1; i < a; ++i){
    cin >> p[i];
    --p[i];
  }
  map<int, int> x1;
  vector<vector<int>> G(a);
  vector<bool> used(a, false);
  for (int i = 0; i < n; ++i){
    int tmp;
    cin >> tmp;
    dfs1(tmp - 1, p, used, G);
    x1[tmp - 1] = i;
  }
  dfs2(0, x1, G, events);

  p.clear();
  used.clear();
  G.clear();

  int b;
  cin >> b;
  p.resize(b);
  p[0] = -1;
  for (int i = 1; i < b; ++i){
    cin >> p[i];
    --p[i];
  }
  map<int, int> x2;
  G.resize(b);
  used.resize(b, false);
  for (int i = 0; i < n; ++i){
    int tmp;
    cin >> tmp;
    dfs1(tmp - 1, p, used, G);
    x2[tmp - 1] = i;
  }
  dfs2(0, x2, G, events);

  sort(events.begin(), events.end(), [](segm a, segm b){
      return a.right < b.right;
    });
  //for (auto tmp: events)
  //  cout << tmp.left << ' ' << tmp.right << ' ' << tmp.cost << '\n';
  vector<int> dp(n + 1);
  int j = 0;
  for (int i = 0; i < n; ++i){
    dp[i + 1] = dp[i];
    while (j < events.size() && events[j].right == i){
      dp[i + 1] = max(dp[i + 1], dp[events[j].left] + events[j].cost);
      ++j;
    }
  }
  cout << dp[n];
  return 0;
}