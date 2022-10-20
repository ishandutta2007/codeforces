#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, int> pi;

int n, q, m;
vector <pi> a[750];
long long delta[750];

bool cmp(pi x, pi y) {
  return x.second < y.second;
}

void setup(int x, int b, int l, int r) {
  sort(a[b].begin(), a[b].end(), cmp);
  for (int i = l; i <= r; i++) {
    a[b][i].first += x;
  }
  sort(a[b].begin(), a[b].end());
}

void update(int l, int r, int x) {
  int ll = l / m;
  int rr = r / m;
  if (ll == rr) {
    setup(x, ll, l - ll * m, r - ll * m);
    return;
  }
  setup(x, ll, l - ll * m, a[ll].size() - 1);
  setup(x, rr, 0, r - rr * m);
  for (int i = ll + 1; i < rr; i++) {
    delta[i] += x;
  }
}

long long get(int x) {
  int l = 1000000000, r = -1000000000;
  for (int i = 0; i <= (n - 1) / m; i++) {
    int pos = lower_bound(a[i].begin(), a[i].end(), pi(x - delta[i], -1)) - a[i].begin();
    if (pos >= a[i].size() || a[i][pos].first != x - delta[i]) {
      continue;
    }
    l = min(l, a[i][pos].second);
    pos = lower_bound(a[i].begin(), a[i].end(), pi(x - delta[i] + 1, -1)) - a[i].begin();
    r = max(r, a[i][pos - 1].second);
  }
  if (l > r) {
    return -1;
  }
  return r - l;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef Doflamingo
  freopen("E.inp", "r", stdin);
  //freopen("E.out", "w", stdout);
#endif // Doflamingo
  m = 700;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i / m].push_back(pi(x, i));
  }
  for (int i = 0; i <= (n - 1) / m; i++) {
    sort(a[i].begin(), a[i].end());
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      update(l - 1, r - 1, x);
    } else {
      int x;
      cin >> x;
      cout << get(x) << endl;
    }
  }
  return 0;
}