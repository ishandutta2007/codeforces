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

const int maxn = 3123;
const int maxk = 3123456;

int n, k, pos[maxk];
char s[maxn];
vector<int> ans[maxk];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  int rd = 0, tot = 0;
  while (true) {
    FOR(i, 1, n - 1) if (s[i] == 'R' && s[i + 1] == 'L') {
      swap(s[i], s[i + 1]);
      ans[rd].eb(i);
      i++;
      tot++;
    }
    if (ans[rd].empty()) break;
    rd++;
  }
  if (tot < k || rd > k) {
    puts("-1");
    return 0;
  }
  int now = rd;
  REP(i, rd) {
    while (ans[i].size() - pos[i] > 1 && now < k) {
      now++;
      printf("1 %d\n", ans[i][pos[i]]);
      pos[i]++;
    }
    printf("%d", int(ans[i].size()) - pos[i]);
    FOR(j, pos[i], int(ans[i].size()) - 1) printf(" %d", ans[i][j]);
    putchar('\n');
  }
}