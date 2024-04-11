#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n, q;
int a[N];
vector <int> f[N];
int dd[N];
int cnt[500100];

void update(int x, int y) {
  if (f[x].size() == 0) {
    return;
  }
  for (int mask = 1; mask < (1 << f[x].size()); mask++) {
    int num = 1;
    for (int i = 0; i < f[x].size(); i++) {
      if (mask & (1 << i)) {
        num *= f[x][i];
      }
    }
    cnt[num] += y;
  }
}

long long get(int x) {
  long long res = 0;
  if (f[x].size() == 0) {
    return 0;
  }
  for (int mask = 1; mask < (1 << (f[x].size())); mask++) {
    int sl = 0;
    int num = 1;
    for (int i = 0; i < f[x].size(); i++) {
      if (mask & (1 << i)) {
        sl++;
        num *= f[x][i];
      }
    }
    if (sl & 1) {
      res += cnt[num];
    } else {
      res -= cnt[num];
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int foo = a[i];
    for (int j = 2; j * j <= foo; j++) {
      if (foo % j == 0) {
        f[i].push_back(j);
        while (foo % j == 0) {
          foo /= j;
        }
      }
    }
    if (foo > 1) {
      f[i].push_back(foo);
    }
  }
  int cur = 0;
  long long ans = 0;
  while (q--) {
    int x;
    cin >> x;
    if (dd[x]) {
      cur--;
      update(x, -1);
      ans -= cur - get(x);
    } else {
      ans += cur - get(x);
      update(x, 1);
      cur++;
    }
    dd[x] ^= 1;
    cout << ans << endl;
  }
  return 0;
}