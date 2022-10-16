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

int cnt[256];

void solve() {
  string s;
  cin >> s;
  reset(cnt, 0);
  for (auto x : s) cnt[x]++;
  int n = s.size();
  FOR(i, 'a', 'z') if (cnt[i] == 1) {
    cout << char(i);
    cnt[i]--;
    FOR(j, 'a', 'z') while (cnt[j]--) cout << char(j);
    cout << '\n';
    return;
  }
  int fi = 'z' + 1;
  FOR(i, 'a', 'z') if (cnt[i] > 0) {
    fi = i;
    break;
  }
  string ans(n, 0);
  if ((cnt[fi] - 2) * 2 <= n - 2) {
    ans[0] = ans[1] = fi;
    cnt[fi] -= 2;
    for (int i = 3; i < n && cnt[fi]; i += 2) {
      ans[i] = fi;
      cnt[fi]--;
    }
    FOR(i, 'a', 'z') if (cnt[i] > 0) {
      REP(j, n) if (!ans[j] && cnt[i]) {
        cnt[i]--;
        ans[j] = i;
      }
    }
    cout << ans << '\n';
    return;
  }
  int se = 'z' + 1, th = 'z' + 1;
  FOR(i, fi + 1, 'z') if (cnt[i]) {
    se = i;
    break;
  }
  if (se == 'z' + 1) {
    cout << s << '\n';
    return;
  }
  FOR(i, se + 1, 'z') if (cnt[i]) {
    th = i;
    break;
  }
  if (th == 'z' + 1) {
    ans[0] = fi;
    FOR(i, 1, cnt[se]) ans[i] = se;
    FOR(i, cnt[se] + 1, n - 1) ans[i] = fi;
  } else {
    ans[0] = fi, ans[1] = se;
    cnt[fi]--, cnt[se]--;
    int i = 2;
    while (cnt[fi]) {
      ans[i++] = fi;
      cnt[fi]--;
    }
    ans[i++] = th;
    cnt[th]--;
    FOR(j, 'a', 'z') while (cnt[j]) {
      ans[i++] = j;
      cnt[j]--;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}