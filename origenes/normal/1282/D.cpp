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

int ask(const string &s) {
  cout << s << endl;
  int ret;
  cin >> ret;
  if (!ret) exit(0);
  return ret;
}

int main() {
  string s(300, 'a');
  int ca = 300 - ask(s);
  s = string(300, 'b');
  int cb = 300 - ask(s);
  int n = ca + cb;
  if (ca == 0) {
    s = string(n, 'b');
    ask(s);
  }
  if (cb == 0) {
    s = string(n, 'a');
    ask(s);
  }
  s = string(n, 'a');
  int pre = cb;
  REP(i, n - 1) {
    s[i] = 'b';
    int now = ask(s);
    if (now >= pre) s[i] = 'a';
    else pre = now;
  }
  assert(pre <= 1);
  if (pre) s.back() = 'b';
  ask(s);
}