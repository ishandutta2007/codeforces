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

const int maxn = 112345;

int n;
int p[maxn], L[maxn], R[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> p[i];
  FOR(i, 2, n) if (p[i] > p[i - 1]) L[i] = L[i - 1] + 1;
  ROF(i, n - 1, 1) if (p[i] > p[i + 1]) R[i] = R[i + 1] + 1;
  map<int, int> cnt;
  FOR(i, 1, n) {
    if (L[i]) cnt[L[i]]++;
    if (R[i]) cnt[R[i]]++;
  }
  int ans = 0;
  FOR(i, 1, n) if (L[i] && R[i]) {
    int x = L[i], y = R[i];
    if (x > y) swap(x, y);
    int opp = y % 2 == 0 ? y - 1 : y;
    if (x <= opp) continue;
    if (!--cnt[L[i]]) cnt.erase(L[i]);
    if (!--cnt[R[i]]) cnt.erase(R[i]);
    if (cnt.empty() || cnt.rbegin()->_1 < y) ans++;
    cnt[L[i]]++, cnt[R[i]]++;
  }
  cout << ans;
}