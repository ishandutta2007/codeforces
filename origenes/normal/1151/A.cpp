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

const int maxn = 55;

int n, ans = 1e9;
char s[maxn];

int dis(char a, char b) {
  if (b > a) swap(a, b);
  return min(a - b, b + 26 - a);
}

int check(const char *s) {
  int ret = 0;
  ret += dis(s[0], 'A');
  ret += dis(s[1], 'C');
  ret += dis(s[2], 'T');
  ret += dis(s[3], 'G');
  return ret;
}

int main() {
  scanf("%d%s", &n, s + 1);
  FOR(i, 1, n - 3) chkmin(ans, check(s + i));
  printf("%d", ans);
}