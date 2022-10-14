#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<lint> a(n);
  lint tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i] * a[i];
  }

  // const auto Check = [&](lint mn) {
  //   lint cnt = 0;
  //   lint res = 0;
  //   for (int i = 0; i < n; i++) {
  //     lint lo = 1, hi = a[i];
  //     while (lo < hi) {
  //       lint md = (lo + hi) / 2;
  //       lint mod = a[i] % md;
  //       lint n1, n2, p1, p2;

  //       n1 = a[i] / md;
  //       p1 = md - mod;

  //       n2 = a[i] / md + 1;
  //       p2 = mod;

  //       if (p1 * (p1 - 1) / 2 * n1 * n1 + p2 * (p2 - 1) / 2 * n2 * n2 + p1 * p2 * n1 * n2 >= mn) {
  //         hi = md;
  //       } else {
  //         lo = md + 1;
  //       }
  //     }

  //     lint mod = a[i] % lo;
  //     lint n1, n2, p1, p2;

  //     n1 = a[i] / lo;
  //     p1 = lo - mod;

  //     n2 = a[i] / lo + 1;
  //     p2 = mod;

  //     res += p1 * (p1 - 1) / 2 * n1 * n1 + p2 * (p2 - 1) / 2 * n2 * n2 + p1 * p2 * n1 * n2;
  //     cnt += lo;
  //   }
  //   return make_pair(cnt, res);
  // };


  // lint lo = 0, hi = 1e12;
  // while (lo < hi) {
  //   lint md = (lo + hi + 1) / 2;
  //   if (Check(md).first < k) {
  //     lo = md;
  //   } else {
  //     hi = md - 1;
  //   }
  // }

  // auto res = Check(lo);
  // cout << lo << "\n";
  // lint sub = 0;
  lint sub = 0;

  vector<int> part(n, 1);
  priority_queue<pair<lint, int>> pq;

  const auto Cost = [&](int i, lint x) {
    lint mod = a[i] % x;
    lint n1, n2, p1, p2;

    n1 = a[i] / x;
    p1 = x - mod;

    n2 = a[i] / x + 1;
    p2 = mod;

    return p1 * (p1 - 1) / 2 * n1 * n1 + p2 * (p2 - 1) / 2 * n2 * n2 + p1 * p2 * n1 * n2;
  };

  for (int i = 0; i < n; i++) {
    pq.emplace(Cost(i, part[i] + 1) - Cost(i, part[i]), i);
  }

  int rep = k - n;
  while (rep--) {
    auto t = pq.top();
    pq.pop();
    sub += t.first;
    part[t.second]++;
    pq.emplace(Cost(t.second, part[t.second] + 1) - Cost(t.second, part[t.second]), t.second);
  }

  lint ans = tot - 2 * sub;

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}