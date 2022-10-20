#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
bool b[N + N];
vector <int> val;
vector <int> ans[1000];

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      val.push_back(i);
      if (i * i != n) {
        val.push_back(n / i);
      }
    }
  }
  sort(val.begin(), val.end());
  val.pop_back();
  for (int i = 1; i < n; i++) {
    int x = __gcd(i, n);
    x = lower_bound(val.begin(), val.end(), x) - val.begin();
    ans[x].push_back(i);
  }
  long long res = 0;
  for (int it = 0; it < val.size(); it++) {
    int u = val[it];
    for (int i = 0; i < u; i++) {
      int maxval = 0;
      for (int j = i; j < n; j += u) {
        maxval = max(maxval, a[j]);
      }
      for (int j = i; j < n; j += u) {
        b[j] = (a[j] == maxval);
        b[j + n] = b[j];
      }
    }
    int cur = n;
    while (b[cur]) {
      cur++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (!b[i]) {
        cur = i;
      } else {
        res += upper_bound(ans[it].begin(), ans[it].end(), cur - i) - ans[it].begin();
      }
    }
  }
  printf("%I64d", res);
  return 0;
}