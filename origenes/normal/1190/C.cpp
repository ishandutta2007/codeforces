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

int k, n, zero[2], one[2];
char s[maxn];

bool check(const int *tar) {
  return tar[0] <= k && tar[1] > n - k && tar[1] - tar[0] == k;
}

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  FOR(i, 1, n) s[i] -= '0';
  zero[0] = one[0] = n + 1;
  FOR(i, 1, n) {
    if (s[i]) {
      chkmin(one[0], i);
      chkmax(one[1], i);
    } else {
      chkmin(zero[0], i); // l, r
      chkmax(zero[1], i);
    }
  }
  if (zero[1] - zero[0] + 1 <= k || one[1] - one[0] + 1 <= k) {
    puts("tokitsukaze");
    return 0;
  }
  puts(check(zero) && check(one) ? "quailty" : "once again");
}