#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &v : a)
    cin >> v;
  for (auto &v : b)
    cin >> v;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 1; i < n; ++i)
    a[i] += a[i - 1];
  for (int i = 1; i < n; ++i)
    b[i] += b[i - 1];

  auto getDiff = [&](void) {
    int k = a.size();
    int take = k - k / 4;
    int fst = a[k - 1] - (k - take > 0 ? a[k - take - 1] : 0);
    int snd = 0;
    if (take > n)
      snd = b.back();
    else
      snd = b[n - 1] - (n - take > 0 ? b[n - take - 1] : 0);
    return fst - snd;
  };

  while (getDiff() < 0) {
    a.push_back(100 + a.back());
  }
  cout << (int)a.size() - n << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}