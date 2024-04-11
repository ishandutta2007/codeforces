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

int ask(int a, int b, int c) {
  cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
  int res; cin >> res;
  return res;
}

void solve() {
  int n; cin >> n;
  vector<int> ans(n, -1);
  vector<int> zeros, ones;
  REP(i, n / 3) {
    int v = ask(i * 3, i * 3 + 1, i * 3 + 2);
    if (v == 0) zeros.eb(i);
    else ones.eb(i);
  }
  assert(!zeros.empty() && !ones.empty());
  int z[3] = {}, o[3] = {};
  REP(i, 3) {
    z[i] = zeros[0] * 3 + i;
    o[i] = ones[0] * 3 + i;
  }
  vector<int> res(3);
  REP(i, 3) res[i] = ask(o[0], o[1], z[i]);
  if (res[0] == res[1] && res[1] == res[2]) {
    if (res[0] == 0) {
      REP(i, 3) ans[z[i]] = 0;
      ans[o[2]] = 1;
    } else {
      ans[o[0]] = ans[o[1]] = 1;
      int v = ask(o[0], z[0], z[1]);
      if (v == 0) ans[z[0]] = ans[z[1]] = 0;
      else ans[z[2]] = 0;
    }
  } else {
    ans[o[2]] = 1;
    REP(i, 3) ans[z[i]] = res[i];
  }
  int zero = -1, one = -1;
  REP(i, 3) {
    if (ans[z[i]] == 0) zero = z[i];
    else if (ans[z[i]] == 1) one = z[i];
    if (ans[o[i]] == 0) zero = o[i];
    else if (ans[o[i]] == 1) one = o[i];
  }
  REP(i, 3) {
    if (ans[z[i]] == -1) ans[z[i]] = ask(zero, one, z[i]);
    if (ans[o[i]] == -1) ans[o[i]] = ask(zero, one, o[i]);
  }
  FOR(i, 1, int(zeros.size()) - 1) {
    REP(j, 3) z[j] = zeros[i] * 3 + j;
    int v = ask(z[0], z[1], one);
    if (v == 0) {
      ans[z[0]] = ans[z[1]] = 0;
      ans[z[2]] = ask(zero, one, z[2]);
    } else {
      ans[z[2]] = 0;
      ans[z[0]] = ask(zero, one, z[0]);
      ans[z[1]] = 1 - ans[z[0]];
    }
  }
  FOR(i, 1, int(ones.size()) - 1) {
    REP(j, 3) o[j] = ones[i] * 3 + j;
    int v = ask(o[0], o[1], zero);
    if (v == 1) {
      ans[o[0]] = ans[o[1]] = 1;
      ans[o[2]] = ask(zero, one, o[2]);
    } else {
      ans[o[2]] = 1;
      ans[o[0]] = ask(zero, one, o[0]);
      ans[o[1]] = 1 - ans[o[0]];
    }
  }
  cout << '!';
  int cnt = 0;
  REP(i, n) if (!ans[i]) cnt++;
  cout << ' ' << cnt;
  REP(i, n) if (!ans[i]) cout << ' ' << i + 1;
  cout << endl;
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}