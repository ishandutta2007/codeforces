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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 512345;

int a[maxn], need[maxn], b[maxn];
int n, k, m, s, ext;
set<int> bad;

bool check(int st) {
  if (!bad.empty()) return false;
  vector<int> del;
  FOR(i, st, st + k + ext - 1) {
    if (del.size() == ext) break;
    if (need[a[i]] < 0) {
      del.eb(i);
      need[a[i]]++;
    }
  }
  printf("%d\n", int(del.size()));
  for (auto it : del) printf("%d ", it);
  return true;
}

int main() {
  scanf("%d%d%d%d", &m, &k, &n, &s);
  FOR(i, 1, m) scanf("%d", a + i);
  FOR(i, 1, s) {
    scanf("%d", b + i);
    need[b[i]]++;
    bad.insert(b[i]);
  }
  ext = m - n * k;
  FOR(i, 1, k + ext) {
    need[a[i]]--;
    if (!need[a[i]]) bad.erase(a[i]);
  }
  if (check(1)) return 0;
  FOR(i, 1, n - 1) {
    int pre = (i - 1) * k + 1, now = i * k;
    FOR(j, pre, now) {
      need[a[j]]++;
      if (need[a[j]] == 1) bad.insert(a[j]);
    }
    pre = i * k + ext;
    FOR(j, pre + 1, pre + k) {
      need[a[j]]--;
      if (!need[a[j]]) bad.erase(a[j]);
    }
    if (check(i * k + 1)) return 0;
  }
  puts("-1");
}