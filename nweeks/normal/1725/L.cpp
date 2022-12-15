#include <bits/stdc++.h>
#define int long long
using namespace std;

template <class T> class Fenwick {
public:
  int lim;
  vector<T> bit;

  Fenwick(int n) : lim(n + 1), bit(lim) {}

  void upd(int pos, T val) {
    for (pos++; pos < lim; pos += pos & -pos)
      bit[pos] += val;
  }

  T sum(int r) { // < r
    T ret = 0;
    for (; r; r -= r & -r)
      ret += bit[r];
    return ret;
  }

  T sum(int l, int r) { // [l, r)
    return sum(r) - sum(l);
  }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int &x : A)
    cin >> x;
  vector<int> partial(N);
  for (int i = 0; i < N; ++i) {
    partial[i] = A[i];
    if (i)
      partial[i] += partial[i - 1];
  }
  if (partial.back() < *max_element(partial.begin(), partial.end()) or
      *min_element(partial.begin(), partial.end()) < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<pair<int, int>> toSort(N);
  for (int i = 0; i < N; ++i)
    toSort[i] = pair(partial[i], i);
  sort(toSort.begin(), toSort.end());
  vector<int> perm(N);
  for (int i = 0; i < N; ++i)
    perm[toSort[i].second] = i;
  Fenwick<int> fen(N);
  int sol = 0;
  for (int i : perm) {
    sol += fen.sum(N) - fen.sum(i);
    fen.upd(i, 1);
  }
  cout << sol << endl;
}