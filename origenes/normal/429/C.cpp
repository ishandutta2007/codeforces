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

const int maxn = 30;

int n;
int c[maxn], cnt[maxn];

bool dfs(int i, int need, int deg, int last) {
  if (i == n) return true;
  if (need == 1) {
    if (deg != 1) {
      cnt[c[i]]++;
      return dfs(i + 1, c[i + 1], 0, n);
    }
  } else {
    ROF(j, min(need - 1, last), 1) if (cnt[j]) {
      cnt[j]--;
      if (dfs(i, need - j, deg + 1, j)) return true;
      cnt[j]++;
    }
  }
  return false;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) cin >> c[i];
  sort(c, c + n);
  if (c[n - 1] != n) {
    cout << "NO";
    return 0;
  }
  if (any_of(c, c + n, [](int x) { return x == 2; })) {
    cout << "NO";
    return 0;
  }
  REP(i, n) if (c[i] > i + 1) {
    cout << "NO";
    return 0;
  }
  if (dfs(0, c[0], 0, n)) cout << "YES";
  else cout << "NO";
}