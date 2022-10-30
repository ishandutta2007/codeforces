#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <deque>

using namespace std;

struct segm{
  int left, right, cost;
  segm(int _l, int _r, int _c){
    left = _l;
    right = _r;
    cost = _c;
  }
};

const int INF = 1000000000;

vector<int> tree;

int get(int p, int left, int right, int x, int y){
  if (y <= left || right <= x)
    return INF;
  if (x <= left && right <= y)
    return tree[p];
  int mid = (left + right) / 2;
  return min(get(2 * p + 1, left, mid, x, y), get(2 * p + 2, mid, right, x, y));
}

void upd(int p, int left, int right, int i, int val){
  if (i < left || right <= i)
    return;
  if (left + 1 == right){
    tree[p] = val;
    return;
  }
  int mid = (left + right) / 2;
  upd(2 * p + 1, left, mid, i, val);
  upd(2 * p + 2, mid, right, i, val);
  tree[p] = min(tree[2 * p + 1], tree[2 * p + 2]);
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<segm> all;
  for (int i = 0; i < n; ++i){
    int x, s;
    cin >> x >> s;
    int j = 0;
    while (j == 0 || x - s - j >= 1 || x + s + j <= m){
      all.emplace_back(max(1, x - s - j), min(x + s + j, m), j);
      ++j;
    }
  }
  sort(all.begin(), all.end(), [](const segm &a, const segm &b){
    return a.right < b.right;
    });
  vector<int> dp(m + 1, INF);
  tree.resize(4 * m + 4, INF);
  dp[0] = 0;
  upd(0, 0, m + 1, 0, 0);
  int j = 0;
  for (int i = 1; i <= m; ++i){
    while (j < all.size() && all[j].right == i){
      dp[i] = min(dp[i], get(0, 0, m + 1, all[j].left - 1, i) + all[j].cost);
      ++j;
    }
    upd(0, 0, m + 1, i, dp[i]);
  }
  cout << dp.back();
  return 0;
}