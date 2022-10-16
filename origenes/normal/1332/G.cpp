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

int n, q;
int a[maxn], cnt[maxn], p3[maxn], p4[maxn];
vector<int> ans3[maxn], ans4[maxn];

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  set<int> s = {n + 1};
  vector<int> mn, mx;
  int mx_len = 0, mn_len = 0;
  for (int r = n, l; r >= 1; r = l - 1) {
    for (l = r; l > 1 && a[l - 1] == a[r]; l--);
    while (!mn.empty() && a[r] < a[mn.back()]) {
      if (!--cnt[mn.back()]) s.emplace(mn.back());
      mn.pop_back();
      mn_len = 0;
    }
    while (!mx.empty() && a[r] > a[mx.back()]) {
      if (!--cnt[mx.back()]) s.emplace(mx.back());
      mx.pop_back();
      mx_len = 0;
    }
    p3[r] = r + max(mn_len, mx_len) + 1;
    ans3[r] = {r, p3[r] - 1, p3[r]};
    int x = lower_bound(all(mn), r, [](int i, int j) { return a[i] < a[j]; }) - mn.begin() - 1;
    int y = lower_bound(all(mx), r, [](int i, int j) { return a[i] > a[j]; }) - mx.begin() - 1;
    if (~x && ~y) {
      p4[r] = *s.upper_bound(max(mn[x], mx[y]));
      int u = *upper_bound(all(mn), p4[r], greater<>()), v = *upper_bound(all(mx), p4[r], greater<>());
      if (p4[r] <= n) ans4[r] = {r, min(u, v), max(u, v), p4[r]};
    } else p4[r] = n + 1;
    mn.eb(r); mn_len++;
    mx.eb(r); mx_len++;
    cnt[r] += 2;
    if (r < n && p3[r] > p3[r + 1]) {
      p3[r] = p3[r + 1];
      ans3[r] = ans3[r + 1];
    }
    if (r < n && p4[r] > p4[r + 1]) {
      p4[r] = p4[r + 1];
      ans4[r] = ans4[r + 1];
    }
    ROF(i, r - 1, l) {
      p3[i] = p3[r], ans3[i] = ans3[r];
      p4[i] = p4[r], ans4[i] = ans4[r];
      mn.eb(i); mn_len++;
      mx.eb(i); mx_len++;
      cnt[i] += 2;
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (r >= p4[l]) {
      puts("4");
      for (auto x : ans4[l]) printf("%d ", x);
      putchar('\n');
    } else if (r >= p3[l]) {
      puts("3");
      for (auto x : ans3[l]) printf("%d ", x);
      putchar('\n');
    } else puts("0\n");
  }
}