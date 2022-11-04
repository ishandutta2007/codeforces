#include <bits/stdc++.h>

#define fi first
#define se second
#define re return
#define pb push_back

#define F(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define f(i, n) F(i, 0, n)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run();

  return 0;
}

ll a[100500];

ll cnt[100500];

int run() {
  ll ans = 0;

  int n;
  cin >> n;

  f(i, n) {
    cin >> a[i];
  }

  ll mx = 0;
  f(i, n) {
    mx = max(mx, a[i] + 1);
    cnt[i] = max(mx, cnt[i]);
  }

  for (int i = n - 2; i >= 0; i--) {
    cnt[i] = max(cnt[i], cnt[i + 1] - 1);
  }

  f(i, n) {
    ans += cnt[i] - a[i] - 1;
  }

  cout << ans;

  return 0;
}