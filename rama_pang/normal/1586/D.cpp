#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N, -1);
  const auto Query = [&](vector<int> v) {
    int mn = *min_element(begin(v), end(v));
    int add = 1 - mn;
    cout << "? ";
    for (auto &a : v) a += add;
    for (auto a : v) cout << a << ' '; cout << endl;
    int k;
    cin >> k;
    return k - 1;
  };

  vector<int> nxt(N, -1);
  vector<int> prv(N, -1);
  vector<pair<int, int>> edge;
  for (int r = 0; r < N; r++) {
    vector<int> v(N, 1);
    v[r] = 0;
    int q = Query(v);
    assert(q <= r);
    if (q != -1 && q < r) {
      assert(nxt[q] == -1);
      nxt[q] = r;
      prv[r] = q;
    }
    v = vector<int>(N, 0);
    v[r] = 1;
    q = Query(v);
    if (q != -1 && q < r) {
      assert(nxt[r] == -1);
      nxt[r] = q;
      prv[q] = r;
    }
  }
  
  int big = -1;
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (nxt[i] == -1) {
      assert(big == -1);
      big = i;
    }
  }

  while (big != -1) {
    ans.emplace_back(big);
    big = prv[big];
  }

  assert(ans.size() == N);
  reverse(begin(ans), end(ans));
  vector<int> out(N);
  for (int i = 0; i < N; i++) {
    out[ans[i]] = i + 1;
  }
  cout << "! ";
  for (int i = 0; i < N; i++) {
    cout << out[i] << " \n"[i + 1 == N];
  }
  cout << endl;
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