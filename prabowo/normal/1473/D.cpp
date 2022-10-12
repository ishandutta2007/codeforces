#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

tuple<int, int, int> pre[N];
pair<int, int> suf[N];

int solve() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);

  int l = 0, r = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') ++cur;
    else --cur;
    l = min(l, cur);
    r = max(r, cur);

    pre[i] = make_tuple(l, r, cur);
  }

  l = 0, r = 0, cur = 0;
  suf[n] = {l, r};
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '+') ++cur;
    else --cur;
    l = min(l, cur);
    r = max(r, cur);

    suf[i] = {cur - r, cur - l};
  }

  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    tuple<int, int, int> p = (l == 0 ? make_tuple(0, 0, 0) : pre[l - 1]);
    int ll, rr, cur;
    tie(ll, rr, cur) = p;

    // cerr << ll << " " << rr << " " << cur << "; " << suf[r + 1].first << " " << suf[r + 1].second;
    ll = min(ll, cur + suf[r + 1].first);
    rr = max(rr, cur + suf[r + 1].second);
    // cerr << ll << " " << rr << endl;
    printf("%d\n", rr - ll + 1);
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}