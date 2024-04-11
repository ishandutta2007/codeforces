#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    if (i < l) {
      cnt[a]++;
    } else {
      cnt[a]--;
    }
  }

  int ans = 0;
  int oddpos = 0;
  int oddneg = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2 != 0) {
      if (cnt[i] < 0) oddneg++;
      else oddpos++;
    }
  }
  if (oddpos < oddneg) {
    swap(oddpos, oddneg);
    for (int i = 0; i < n; i++) {
      cnt[i] *= -1;
    }
  }
  oddpos -= oddneg;
  for (int i = 0; i < n; i++) {
    if (oddneg > 0 && cnt[i] % 2 != 0 && cnt[i] > 0) {
      cnt[i]--;
      oddneg--;
      ans += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2 != 0 && cnt[i] < 0) {
      cnt[i] += 1;
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2 != 0) {
      assert(cnt[i] > 0);
    }
  }
  int sumneg = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] < 0) sumneg += abs(cnt[i]);
  }
  // cout << oddpos << ' ';
  int delneg = 0;
  assert(oddpos % 2 == 0);
  while (sumneg >= 2 && oddpos > 0) {
    oddpos -= 2;
    sumneg -= 2;
    delneg += 2;
    ans += 1;
  }
  ans += oddpos;
  for (int i = 0; i < n; i++) {
    // if (cnt[i] >= 0) {
      ans += abs(cnt[i]) / 2;
    // } else {

    // }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}