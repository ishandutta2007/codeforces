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

const int maxn = 512;

int n, k;
int f[maxn], pre[maxn];
bool used[maxn];

int main() {
  cin >> n >> k;
  reset(f, 0x3f);
  f[0] = 0;
  f[k] = 1, pre[k] = 0;
  queue<int> q;
  q.emplace(k);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (int inc = -k; inc <= k; inc += 2) {
      int zeros = k - (k - inc) / 2, ones = k - zeros;
      if (u < ones || u + zeros > n) continue;
      if (f[u + inc] > f[u] + 1) {
        f[u + inc] = f[u] + 1;
        pre[u + inc] = u;
        q.emplace(u + inc);
      }
    }
  }
  if (f[n] > 500) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> seq = {n};
  for (int u = n; u != 0; u = pre[u]) seq.eb(pre[u]);
  reverse(all(seq));
  ll ans = 0;
  FOR(i, 1, f[n]) {
    int inc = seq[i] - seq[i - 1], zeros = k - (k - inc) / 2, ones = k - zeros;
    cout << "?";
    FOR(j, 1, n) {
      if (used[j] && ones) {
        used[j] = false;
        ones--;
        cout << ' ' << j;
      } else if (!used[j] && zeros) {
        used[j] = true;
        zeros--;
        cout << ' ' << j;
      }
    }
    cout << endl;
    ll v; cin >> v;
    ans ^= v;
  }
  cout << "! " << ans << endl;
}