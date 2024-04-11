#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &x : p) {
    cin >> x;
    --x;
  }
  for (int i = 0; i < n; ++i)
    if (i % 2 != p[i] % 2) {
      cout << -1 << '\n';
      return;
    }

  vector<int> ret;

  for (int i = n - 1; i >= 2; i -= 2) {
    if (p[i] == i and p[i - 1] == i - 1)
      continue;
    auto findPos = [&]() -> pair<int, int> {
      int posR = 0;
      while (p[posR] != i)
        posR += 2;
      int posL = 1;
      while (p[posL] != i - 1)
        posL += 2;
      return {posL, posR};
    };

    auto applyOp = [&](int pos) {
      ret.push_back(pos);
      reverse(p.begin(), p.begin() + pos + 1);
    };
    auto [posL, posR] = findPos();
    if (posL < posR) {
      applyOp(posR);
      tie(posL, posR) = findPos();
      if (posL > 1)
        applyOp(posL - 1);
      tie(posL, posR) = findPos();
      applyOp(posL + 1);
      tie(posL, posR) = findPos();
      if (posR > 0)
        applyOp(posR);
      applyOp(i);
    } else {
      if (posR > 0)
        applyOp(posR);
      tie(posL, posR) = findPos();
      if (posL > 1)
        applyOp(posL - 1);
      tie(posL, posR) = findPos();
      applyOp(posL + 1);
      tie(posL, posR) = findPos();
      if (posR > 0)
        applyOp(posR);
      applyOp(i);
    }
    /*if (p[i] != i) {
      for (int x : ret)
        cout << x + 1 << ' ';
      cout << endl;
      return;
    }*/
    assert(p[i] == i);
    assert(p[i - 1] == i - 1);
  }
  cout << ret.size() << '\n';
  for (int x : ret)
    cout << x + 1 << ' ';
  cout << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}