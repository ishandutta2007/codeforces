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

bool win(ll s, ll e) {
  if (e & 1) return 1 - (s & 1);
  if (s * 2 > e) return s & 1;
  if (s * 4 > e) return true;
  return win(s, e / 4);
}

bool lose(ll s, ll e) {
  if (s * 2 > e) return true;
  return win(s, e / 2);
}

ll s[maxn], e[maxn];
bool w[maxn], l[maxn];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld%lld", s + i, e + i);
  l[0] = true;
  FOR(i, 1, n) {
    if (w[i - 1] && l[i - 1]) {
      puts("1 1");
      return 0;
    }
    if (!w[i - 1] && !l[i - 1]) {
      puts("0 0");
      return 0;
    }
    if (l[i - 1]) {
      w[i] = win(s[i], e[i]);
      l[i] = lose(s[i], e[i]);
    } else {
      w[i] = 1 - win(s[i], e[i]);
      l[i] = 1 - lose(s[i], e[i]);
    }
  }
  printf("%d %d", w[n], l[n]);
}