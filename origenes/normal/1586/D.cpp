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

const int maxn = 112;

int n;
int p[maxn], a[maxn];

int ask() {
  cout << '?';
  FOR(i, 1, n) cout << ' ' << a[i];
  cout << endl;
  int ret; cin >> ret;
  return ret;
}

int main() {
  cin >> n;
  p[n] = n;
  vector<int> q;
  FOR(inc, 2, n) {
    a[n] = 1;
    FOR(i, 1, n - 1) a[i] = inc;
    int k = ask();
    if (k == 0) {
      p[n] = inc - 1;
      break;
    }
    q.eb(k);
  }
  REP(i, int(q.size())) p[q[i]] = p[n] - i - 1;
  FOR(now, p[n] + 1, n) {
    FOR(i, 1, n) a[i] = 1;
    a[n] = now - p[n] + 1;
    p[ask()] = now;
  }
  cout << '!';
  FOR(i, 1, n) cout << ' ' << p[i];
  cout << endl;
}