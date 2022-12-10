//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
LL lcnt[maxn],
   rcnt[maxn],
   cnt[maxn],
   lcom[maxn],
   rcom[maxn],
   a[maxn],
   n, k;
vector<int> all;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    all.PB(a[i]);
  }
  sort(all(all));
  all.resize(unique(all(all)) - all.begin());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(all(all), a[i]) - all.begin();
    cnt[a[i]]++;
  }
  for (int i = 0; i < sz(all); i++)
    lcnt[i + 1] = lcnt[i] + cnt[i];
  for (int i = sz(all) - 1; i >= 0; i--)
    rcnt[i] = rcnt[i + 1] + cnt[i];
  for (int i = 1; i < sz(all); i++)
    lcom[i] = lcom[i - 1] + lcnt[i] * (all[i] - all[i - 1]);
  for (int i = sz(all) - 1; i >= 0; i--)
    rcom[i] = rcom[i + 1] + rcnt[i + 1] * (all[i + 1] - all[i]);
  LL ans = 1e18;
  for (int i = 0; i < sz(all); i++) {
    if (cnt[i] >= k)
      return cout << 0 << endl, 0;
    smin(ans, lcom[i] + rcom[i] - (n - k));
    if (lcnt[i + 1] >= k)
      smin(ans, lcom[i] - (lcnt[i + 1] - k));
    if (rcnt[i] >= k)
      smin(ans, rcom[i] - (rcnt[i] - k));
  }
  cout << ans << endl;
	return 0;
}