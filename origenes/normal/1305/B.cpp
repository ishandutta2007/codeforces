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

const int maxn = 1123;

char s[maxn];
int cnt[maxn];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int fi = n + 1;
  FOR(i, 1, n) {
    cnt[i] = cnt[i - 1];
    if (s[i] == '(') {
      cnt[i]++;
      chkmin(fi, i);
    }
  }
  if (cnt[n] - cnt[fi - 1] == n - fi + 1) {
    puts("0");
    return 0;
  }
  puts("1");
  vector<int> l, r;
  for (int i = 1, j = n; i <= j; i++, j--) {
    while (i <= n && s[i] != '(') i++;
    while (j > 0 && s[j] != ')') j--;
    if (i < j) l.eb(i), r.eb(j);
    else break;
  }
  reverse(all(r));
  printf("%d\n", int(l.size()) * 2);
  for (auto i : l) printf("%d ", i);
  for (auto i : r) printf("%d ", i);
}