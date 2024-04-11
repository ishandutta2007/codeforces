#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int S = 2048;

struct Query {
  int l, r, t, k, i;
  bool operator < (const Query &other) const {
    if (l/S != other.l/S) return l < other.l;
    if (r/S != other.r/S) return r < other.r;
    return t < other.t;
  }
};

int n, m;
int a[N];

int b[N];
vector<Query> queries;
vector<pair<int, int>> updates;

int ans[N];

namespace Mo {

int cnt[N], lft[N], rgt[N];
vector<int> nums;

void reset() {
  for (int i = 0; i < n; ++i) b[i] = a[i];
  for (int i = 0; i < N; ++i) {
    cnt[i] = 0;
    lft[i] = rgt[i] = 0;
  }
  nums.clear();
}

void add(int x) {
  if (cnt[x] == 0) nums.push_back(0);
  int pos = lft[cnt[x]++]++;
  ++nums[pos];
  ++rgt[cnt[x]];
  // cerr << "Add " << x << ": "; for (int num : nums) cerr << num << " "; cerr << endl;
}

void del(int x) {
  int pos = --rgt[cnt[x]--];
  --nums[pos];
  --lft[cnt[x]];
  if (cnt[x] == 0) nums.pop_back();
  // cerr << "Del " << x << ": "; for (int num : nums) cerr << num << " "; cerr << endl;
}

int eval(int k) {
  vector<pair<int, int>> cums;
  for (int i = 0; i < nums.size(); i = rgt[nums[i]]) {
    cums.emplace_back(nums[i], rgt[nums[i]] - lft[nums[i]]);
  }

  int cur = 0, ret = -1;
  for (int i = 0, j = 0; i < cums.size(); ++i) {
    while (j < cums.size() && cur < k) cur += cums[j++].second;
    if (cur >= k) {
      if (ret == -1 || cums[i].first - cums[j - 1].first < ret) {
        ret = cums[i].first - cums[j - 1].first;
      }
    } else {
      break;
    }
    cur -= cums[i].second;
  }

  // cerr << "Eval " << k << ": "; for (int num : nums) cerr << num << " "; cerr << " = " << ret << endl;
  return ret;
}

} // namespace Mo

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  for (int i = 0; i < m; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      queries.push_back({--l, r, (int) updates.size(), k, (int) queries.size()});
    } else if (t == 2) {
      int p, x;
      scanf("%d %d", &p, &x);
      updates.emplace_back(--p, x);
    }
  }

  sort(queries.begin(), queries.end());

  int l = 0, r = 0, t = m + 1;;
  for (Query query : queries) {
    if (query.t < t) {
      Mo::reset();
      t = 0;
      l = r = query.l;
    }
    while (l > query.l) Mo::add(b[--l]);
    while (r < query.r) Mo::add(b[r++]);
    while (l < query.l) Mo::del(b[l++]);
    while (r > query.r) Mo::del(b[--r]);
    while (t < query.t) {
      if (l <= updates[t].first && updates[t].first < r) {
        Mo::del(b[updates[t].first]); Mo::add(updates[t].second);
      }
      b[updates[t].first] = updates[t].second;
      ++t;
    }

    ans[query.i] = Mo::eval(query.k);
  }

  for (int i = 0; i < queries.size(); ++i) printf("%d\n", ans[i]);
  return 0;
}