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

const int maxn = 112;

int n, s[maxn];
char ans[maxn];

int main() {
  scanf("%d", &n);
  map<int, int> cnt;
  FOR(i, 1, n) {
    scanf("%d", s + i);
    cnt[s[i]]++;
  }
  int one = 0, mul = 0;
  FOR(i, 1, n) {
    if (cnt[s[i]] == 1) one++;
    else if (cnt[s[i]] >= 3) mul++;
  }
  if ((one & 1) && !mul) {
    puts("NO");
    return 0;
  }
  bool flag = false;
  puts("YES");
  FOR(i, 1, n) {
    if (cnt[s[i]] == 1) {
      ans[i] = 'A' + flag;
      flag ^= 1;
    } else if (cnt[s[i]] == 2) {
      ans[i] = 'A';
    }
  }
  if (one & 1) flag = false;
  else flag = true;
  FOR(i, 1, n) if (cnt[s[i]] >= 3) {
    if (!flag) ans[i] = 'B', flag = true;
    else ans[i] = 'A';
  }
  FOR(i, 1, n) putchar(ans[i]);
}