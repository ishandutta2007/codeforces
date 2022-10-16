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

const int maxn = 2123;

int n, x;
int t[maxn], h[maxn], m[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> x;
  FOR(i, 1, n) cin >> t[i] >> h[i] >> m[i];
  vector<pii> candies[2];
  FOR(i, 1, n) candies[t[i]].eb(h[i], m[i]);
  REP(i, 2) sort(all(candies[i]), greater<>());
  int ans = 0;
  REP(i, 2) {
    vector<pii> c[2];
    c[0] = candies[0], c[1] = candies[1];
    int now = 0, reach = x;
    priority_queue<int> heap[2];
    REP(j, 2) while (!c[j].empty() && c[j].back()._1 <= x) {
      heap[j].emplace(c[j].back()._2);
      c[j].pop_back();
    }
    int op = i;
    while (!heap[op].empty()) {
      auto inc = heap[op].top();
      heap[op].pop();
      now++;
      reach += inc;
      REP(j, 2) while (!c[j].empty() && c[j].back()._1 <= reach) {
        heap[j].emplace(c[j].back()._2);
        c[j].pop_back();
      }
      op = 1 - op;
    }
    chkmax(ans, now);
  }
  cout << ans;
}