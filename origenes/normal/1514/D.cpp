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

const int maxn = 312345;
const int B = 550;

int n, q;
int a[maxn], cnt[maxn], ans[maxn], ccnt[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  REP(i, n) cin >> a[i];
  vector<tuple<int, int, int, int>> queries(q);
  REP(i, q) {
    int l, r; cin >> l >> r;
    l--, r--;
    queries[i] = {l / B, r, l, i};
  }
  sort(all(queries));
  int L = 0, R = 0, occ = 1;
  ccnt[0] = n - 1, ccnt[1] = 1;
  cnt[a[0]] = 1;
  for (auto [_, r, l, id] : queries) {
    auto del = [&](int p) {
      ccnt[cnt[a[p]]]--;
      cnt[a[p]]--;
      ccnt[cnt[a[p]]]++;
      if (ccnt[occ] == 0) occ--;
    };
    auto ins = [&](int p) {
      ccnt[cnt[a[p]]]--;
      cnt[a[p]]++;
      ccnt[cnt[a[p]]]++;
      chkmax(occ, cnt[a[p]]);
    };
    while (L > l) L--, ins(L);
    while (R < r) R++, ins(R);
    while (L < l) del(L), L++;
    while (R > r) del(R), R--;
    int x = r - l + 1;
    ans[id] = max(2 * occ - x, 1);
  }
  REP(i, q) cout << ans[i] << '\n';
}