#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 200010, L = 18;

int n, m;
int a[N];
pair<int, int> b[N];
vector<pair<int, int>> qry[N];
int ans[N], fw[1 << L];

void ch(int k) {
  for (; k < (1 << L); k += k & -k)
    ++fw[k];
}

int kth(int k) {
  --k;
  int ret = 0;
  for (int i = L - 1; i >= 0; --i)
    if (k >= fw[ret | (1 << i)])
      k -= fw[ret |= 1 << i];
  return ret + 1;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i].first = a[i];
    b[i].second = -i;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int k, p;
    cin >> k >> p;
    qry[k].emplace_back(p, i);
  }
  sort(b + 1, b + n + 1, greater<pair<int, int>>());
  for (int i = 1; i <= n; ++i) {
    ch(-b[i].second);
    for (auto [pos, qid] : qry[i])
      ans[qid] = a[kth(pos)];
  }
  for (int i = 1; i <= m; ++i)
    cout << ans[i] << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}