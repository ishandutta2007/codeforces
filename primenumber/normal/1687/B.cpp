#include <bits/stdc++.h>

#include <variant>

#define rep2(i, k, n) for (i64 i = (i64)(k); i < (i64)(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)
#ifdef ENV_LOCAL
#define dump \
  if (1) cerr
#else
#define dump \
  if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

// using namespace harudake;

i64 query(const string& s) {
  cout << "? " << s << endl;
  i64 ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n, m;
  cin >> n >> m;
  vector<pair<i64, i64>> edges;
  rep(i, m) {
    string s(m, '0');
    s[i] = '1';
    edges.emplace_back(query(s), i);
  }
  sort(all(edges));
  i64 prev = 0;
  string s(m, '0');
  for (auto&& [len, idx] : edges) {
    s[idx] = '1';
    i64 new_cost = query(s);
    if (new_cost - prev < len) {
      s[idx] = '0';
    } else {
      prev = new_cost;
    }
  }
  cout << "! " << prev << endl;
  return 0;
}