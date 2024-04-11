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
const int sz = sqrt(9592);

int n;
bool vis[maxn];
int cnt[maxn];
vector<int> primes;

int ask(char t, int a) {
  cout << t << ' ' << a << endl;
  int ret;
  cin >> ret;
  return ret;
}

int main() {
  cin >> n;
  FOR(i, 2, n) if (!vis[i]) {
    primes.eb(i);
    cnt[i] = 1;
    for (int j = i + i; j <= n; j += i) {
      if (!vis[j]) cnt[i]++;
      vis[j] = true;
    }
  }
  vector<int> fac, buff;
  int acc = 0, ex = n;
  bool f = false;
  for (auto x : primes) {
    int have = ask('B', x);
    if (have > cnt[x]) fac.eb(x);
    ex -= cnt[x];
    if (++acc == sz && fac.empty() && !f) {
      int rem = ask('A', 1);
      if (rem > ex) f = true;
      else buff.clear();
      acc = 0;
    }
    if (fac.empty() && !f) buff.eb(x);
  }
  int rem = ask('A', 1);
  if (rem == 1) {
    cout << "C 1" << endl;
    return 0;
  }
  for (auto x : buff) if (ask('A', x)) {
    fac.eb(x);
    break;
  }
  int ans = 1;
  for (auto x : fac) {
    ans *= x;
    while (ll(ans) * x <= n) {
      int now = ask('A', ans * x);
      if (now) ans *= x;
      else break;
    }
  }
  cout << "C " << ans << endl;
}