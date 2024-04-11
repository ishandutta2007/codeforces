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

const int maxn = 312345;

char s[maxn];
int l, r, n;

int main() {
  scanf("%d%s", &n, s + 1);
  if (n & 1) {
    puts(":(");
    return 0;
  }
  FOR(i, 1, n) {
    if (s[i] == '(') l++;
    else if (s[i] == ')') r++;
  }
  if (l > n / 2 || r > n / 2) {
    puts(":(");
    return 0;
  }
  l = n / 2 - l;
  r = n / 2 - r;
  FOR(i, 1, n) if (s[i] == '?') {
    if (l) {
      l--;
      s[i] = '(';
    } else {
      r--;
      s[i] = ')';
    }
  }
  int cnt = 0;
  FOR(i, 1, n - 1) {
    if (s[i] == '(') cnt++;
    else cnt--;
    if (cnt <= 0) {
      puts(":(");
      return 0;
    }
  }
  if (s[n] == '(') {
    puts(":(");
    return 0;
  }
  puts(s + 1);
}