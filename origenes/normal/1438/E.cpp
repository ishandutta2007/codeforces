#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

int n;
ll a[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  set<pii> S;
  auto hi = [&](ll x) {
    ROF(i, 31, 0) if (x & (1LL << i)) {
      return 1LL << i + 1;
    }
    return 2LL;
  };
  FOR(i, 1, n) {
    int j = i + 1;
    ll s = 0, up = hi(a[i]);
    while (s <= up && j + 1 <= n) {
      s += a[j];
      j++;
      if ((a[i] ^ a[j]) == s) S.emplace(i, j);
    }
  }
  ROF(i, n, 1) {
    int j = i - 1;
    ll s = 0, up = hi(a[i]);
    while (s <= up && j - 1 >= 1) {
      s += a[j];
      j--;
      if ((a[i] ^ a[j]) == s) S.emplace(j, i);
    }
  }
  cout << S.size();
}