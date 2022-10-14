#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  long long ans = 0;
  for (int fs = 0; fs + k - 1 < n; fs++) {
    int fl = fs, fr = fs + k - 1;
    vector<int> init(m);
    int mid = 5 * n;
    vector<long long> pref(10 * n);
    long long score = 0;
    for (int i = 0; i < m; i++) {
      if (r[i] < fl || l[i] > fr) {
        init[i] = 0;
      } else {
        init[i] = min(r[i], fr) - max(l[i], fl) + 1;
      }
      score += init[i];
    }
    
    for (int i = 0; i < m; i++) {
      int high = min(k, r[i] - l[i] + 1) - init[i];
      if (high <= 0 || l[i] + init[i] - k + 1 > r[i] - init[i] + 2) {
        continue;
      }
      // assert(mid + l[i] + init[i] - k + high <= mid + r[i] - init[i] - high);
      // x - l[i] + k - init[i] = 1 -> x = l[i] + init[i] - k + 1
      // x - l[i] + k - init[i] = high -> x = l[i] + init[i] - k + high
      pref[mid + l[i] + init[i] - k + 1] += 1;
      pref[mid + l[i] + init[i] - k + high + 1] -= 1;

      // -x + r[i] + 1 - init[i] = high -> x = r[i] - init[i] + 1 - high
      // -x + r[i] + 1 - init[i] = 1 -> x = r[i] - init[i]
      pref[mid + r[i] - init[i] - high + 2] -= 1;
      pref[mid + r[i] - init[i] + 2] += 1;
    }

    for (int i = 1; i < 10 * n; i++) {
      pref[i] += pref[i - 1];
    }
    for (int i = 1; i < 10 * n; i++) {
      pref[i] += pref[i - 1];
    }

    // for (int i = 0; i < 10 * n; i++) {
    //   cout << pref[i] << " \n"[i + 1 == 10 * n];
    // }
    // cout << score << " ";
    score += *max_element(begin(pref), end(pref));
    ans = max(ans, score);
    // cout << score << "\n";
  }
  cout << ans << '\n';
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