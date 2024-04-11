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

const int maxn = 11234567;
const int upp = 1e7 + 5;

vector<int> G[maxn];
int a[maxn], n;

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    G[a[i]].eb(i);
  }
  ll ans = 1e15;
  pii best = {-1, -1};
  FOR(i, 1, upp) {
    if (i >= ans) continue;
    if (G[i].size() >= 2) {
      ans = i;
      best = {G[i][0], G[i][1]};
      continue;
    }
    int fi = -1;
    if (G[i].size() == 1) fi = G[i][0];
    for (int j = 2 * i; j < upp && j < ans; j += i) {
      if (G[j].empty()) continue;
      if (G[j].size() >= 2) {
        ans = j;
        best = {G[j][0], G[j][1]};
        break;
      }
      if (G[j].size() == 1) {
        if (fi == -1) fi = G[j][0];
        else {
          ll now = lcm(a[fi], j);
          if (now < ans) {
            ans = now;
            best = {fi, G[j][0]};
          }
          break;
        }
      }
    }
  }
  if (best._1 > best._2) swap(best._1, best._2);
  printf("%d %d", best._1, best._2);
}