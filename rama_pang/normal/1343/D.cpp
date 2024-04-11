#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class BIT {
 private:
  vector<int> tree;

 public:
  BIT() {}
  BIT(int n) {
    tree.assign(n, 0);
  }

  void Update(int p, int x) {
    for (int i = p + 1; i <= tree.size(); i += (i & -i)) {
      tree[i - 1] += x;
    }
  }

  int Query(int p) {
    int res = 0;
    for (int i = p + 1; i > 0; i -= (i & - i)) {
      res += tree[i - 1];
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    BIT cost(2 * k + 100);
    for (int i = 0; i < n / 2; i++) {
      // vector<pair<int, pair<int, int>>> segs;
      if (a[i] > a[n - i - 1]) swap(a[i], a[n - i - 1]);
      // segs.push_back({0, {a[i] + a[n - i - 1], a[i] + a[n - i - 1]}});
      // segs.push_back({1, {a[i] + 1, a[i] + k}});
      // segs.push_back({1, {1 + a[n - i - 1], k + a[n - i - 1]}});
      cost.Update(1, 2);
      if (a[i] + k < 1 + a[n - i - 1]) {
        cost.Update(a[i] + 1, -1);
        cost.Update(a[i] + k + 1, 1);
        cost.Update(1 + a[n - i - 1], -1);
        cost.Update(k + a[n - i - 1] + 1, 1);
      } else {
        cost.Update(a[i] + 1, -1);
        cost.Update(a[n - i - 1] + k + 1, 1);
      }
      cost.Update(a[i] + a[n - i - 1], -1);
      cost.Update(a[i] + a[n - i - 1] + 1, 1);
    }

    int ans = 1e9;
    for (int i = 1; i <= 2 * k; i++) {
      ans = min(ans, cost.Query(i));
    }
    cout << ans << "\n";
  }

}