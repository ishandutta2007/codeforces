#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define re return
#define pb push_back

#define all(v) (v).begin(), (v).end()

#define F(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define f(i, n) F(i, 0, n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif // home
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  run();
}

ll a[100500];
ll c[100500];

ll pref[100500];

ll bal[100500];

ll ans[100500];

int run() {
  int n;
  cin >> n;
  f(i, n) {
    cin >> a[i];
  }
  f(i, n) {
    cin >> c[i];
    pref[i + 1] = pref[i] + c[i];
  }
  F(i, n, n + 10) {
    pref[i + 1] = pref[i];
  }
  f(i, n) {
    bal[i]++;
    int l = i - 1, r = n;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      if (pref[mid + 1] - pref[i] <= a[i]) {
        l = mid;
      } else {
        r = mid;
      }
    }
//    cerr << i << ' ' << l << '\n';
    bal[l + 1]--;
    ans[l + 1] += a[i] - (pref[l + 1] - pref[i]);
  }
  ll cur = 0;

  f(i, n) {
    cur += bal[i];
    ans[i] += cur * c[i];
  }
  f(i, n) {
    cout << ans[i] << ' ';
  }
}