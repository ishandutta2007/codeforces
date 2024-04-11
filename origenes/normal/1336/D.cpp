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

int n, a[maxn], b[maxn], ans[maxn], rc[maxn * maxn], tail;

void ask(int x) {
  cout << "+ " << x << endl;
  tail--;
  cin >> a[tail] >> b[tail];
}

void answer() {
  cout << '!';
  FOR(i, 1, n) cout << ' ' << ans[i];
  cout << endl;
}

int main() {
  cin >> n;
  cin >> a[n + 1] >> b[n + 1];
  REP(i, n + 1) rc[i * (i + 1) / 2] = i + 1;
  tail = n + 1;
  FOR(i, 2, n - 2) ask(i);
  ask(n); ask(n - 1); ask(n);
  ans[n] = rc[a[1] - a[2]] - 1;
  ans[n - 2] = b[1] - b[2] - b[3] + b[4] - 1;
  ans[n - 1] = (b[1] - b[2]) / (ans[n - 2] + 1) - 1;
  ans[n - 3] = (b[2] - b[3]) / (ans[n - 2] + 1) - ans[n] - 1;
  if (n > 4) ans[n - 3]--;
  ROF(i, n - 4, 1) {
    ans[i] = (b[n - i] - b[n - i + 1]- ans[i + 3] * ans[i + 4]) / (ans[i + 1] + 1) - ans[i + 3];
    if (i != 1) ans[i]--;
  }
  answer();
}