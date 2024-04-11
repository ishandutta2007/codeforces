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
deque<int> c[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int s;
    scanf("%d", &s);
    c[i].resize(s);
    for (auto &x : c[i]) scanf("%d", &x);
  }
  int a1 = 0, a2 = 0;
  vector<int> rem;
  FOR(i, 1, n) {
    while (c[i].size() >= 2) {
      a1 += c[i].front(); a2 += c[i].back();
      c[i].pop_front(); c[i].pop_back();
    }
    if (!c[i].empty()) rem.eb(c[i].front());
  }
  sort(all(rem), greater<>());
  REP(i, int(rem.size())) {
    if (i & 1) a2 += rem[i];
    else a1 += rem[i];
  }
  printf("%d %d", a1, a2);
}