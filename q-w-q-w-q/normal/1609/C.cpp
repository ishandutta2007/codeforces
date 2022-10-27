#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200005, V = 1000005;
int n, e, lt[N], gu[N];
int op[N];
bool np[V];
void init() {
  static int p[V], s;
  for (int i = 2; i <= 1000000; i++) {
    if (!np[i])
      p[++s] = i;
    for (int j = 1; j <= s && i * p[j] <= 1000000; j++)
      np[i * p[j]] = 1;
  }
}

void solve() {
  cin >> n >> e;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int j = i % e;

    if (np[x]) {
      op[j] = 0;
      lt[j] = gu[j] = 0;
      continue;
    }

    if (x == 1) {
      if (op[j])
        ans += lt[j] + 1;
      gu[j]++;
    } else {
      lt[j] = gu[j], gu[j] = 0;
      ans += lt[j];
      op[j] = 1;
    }
  }

  for (int i = 0; i <= n; i++)
    op[i] = lt[i] = gu[i] = 0;

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  init();

  int t;
  cin >> t;
  while (t--)
    solve();
}