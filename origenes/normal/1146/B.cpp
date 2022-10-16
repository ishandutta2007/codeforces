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

const int maxn = 112345;

char t[maxn], s[maxn];
int n, a, na, last = -1;

int main() {
  scanf("%s", t + 1);
  n = strlen(t + 1);
  FOR(i, 1, n) if (t[i] == 'a') {
    a++;
    last = i;
  }
  if (last == -1) {
    if (n & 1) {
      puts(":(");
    } else {
      if (strncmp(t + 1, t + n / 2 + 1, n / 2)) puts(":(");
      else puts(t + n / 2 + 1);
    }
    return 0;
  }
  na = n - a;
  if (na & 1) {
    puts(":(");
    return 0;
  }
  int en = n - na / 2 + 1;
  if (en <= last) {
    puts(":(");
    return 0;
  }
  int j = 1;
  FOR(i, 1, en - 1) if (t[i] != 'a') s[j++] = t[i];
  if (strncmp(s + 1, t + en, na / 2)) puts(":(");
  else {
    FOR(i, 1, en - 1) putchar(t[i]);
  }
}