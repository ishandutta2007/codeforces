#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    vector<int> ret;
    const auto Factor = [&](int x) {
      for (int i = 1; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
          ret.emplace_back(i);
          ret.emplace_back(x / i);
        }
      }
    };
    int W, L;
    cin >> W >> L;
    Factor(W);
    Factor(L);
    Factor(W - 1);
    Factor(L - 1);
    vector<int> ans = {1};
    vector<int> op1 = {W, L, W, L};
    vector<int> op2 = {L, W, L, W};
    for (auto len : ret) {
      for (int rep = 0; rep < 2; rep++) {
        int delnext = 0;
        int bad = 0;
        for (auto t : op1) {
          int cur = t - delnext;
          cur -= cur / len * len;
          if (cur == 1) {
            delnext = 0;
          } else if (cur == 0) {
            delnext = 1;
          } else {
            bad = 1;
            break;
          }
        }
        if (!bad && delnext == 0) {
          ans.emplace_back(len);
          break;
        }
        swap(op1, op2);
      }
    }
    sort(begin(ans), end(ans));
    ans.resize(unique(begin(ans), end(ans)) - begin(ans));
    cout << ans.size() << ' ';
    for (auto a : ans) {
      cout << a << ' ';
    }
    cout << '\n';
  }
}