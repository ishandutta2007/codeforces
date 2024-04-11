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

const int maxn = 512345;

int n, k;
ll c[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> c[i];
  sort(c + 1, c + n + 1, greater<>());
  ll s = 0, ans = 0;
  int st = n + 1;
  vector<ll> neg;
  FOR(i, 1, n) {
    ans += s;
    s += c[i];
    if (s < 0) {
      neg.eb(s);
      st = i + 1;
      break;
    }
  }
  FOR(i, st, n) neg.eb(c[i]);
  sort(all(neg));
  k++;
  REP(i, int(neg.size())) ans += neg[i] * (i / k);
  cout << ans;
}