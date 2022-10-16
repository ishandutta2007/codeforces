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

bool solve(int a, int b, int c, int d, bool zero) {
  vector<int> ans; ans.reserve(a + b + c + d);
  if (zero) ans.eb(0), a--;
  else ans.eb(1), b--;
  while (a) {
    if (ans.back() == 1) {
      ans.eb(0);
      a--;
    } else {
      if (b) ans.eb(1), b--;
      else return false;
    }
  }
  if (ans.back() == 0 && b) ans.eb(1), b--;
  if (b == 0 && c == 0 && d == 0) {
    puts("YES");
    for (auto it : ans) printf("%d ", it);
    return true;
  }
  if (ans.back() == 0) return false;
  while (b) {
    if (ans.back() == 1) {
      if (c) ans.eb(2), c--;
      else return false;
    } else {
      ans.eb(1);
      b--;
    }
  }
  if (ans.back() == 1 && c) ans.eb(2), c--;
  if (c == 0 && d == 0) {
    puts("YES");
    for (auto it : ans) printf("%d ", it);
    return true;
  }
  if (ans.back() == 1) return false;
  while (c) {
    if (ans.back() == 2) {
      if (d) ans.eb(3), d--;
      else return false;
    } else {
      ans.eb(2);
      c--;
    }
  }
  if (ans.back() == 2 && d) ans.eb(3), d--;
  if (d) return false;
  puts("YES");
  for (auto it : ans) printf("%d ", it);
  return true;
}

bool solve(int c, int d) {
  if (c == 0) {
    if (d == 1) {
      puts("YES\n3");
      return true;
    }
    return false;
  }
  if (d == 0) {
    if (c == 1) {
      puts("YES\n2");
      return true;
    }
    return false;
  }
  if (c == d) {
    puts("YES");
    while (c--) printf("2 3 ");
    return true;
  }
  if (c == d + 1) {
    puts("YES");
    while (d--) printf("2 3 ");
    printf("2");
    return true;
  }
  if (d == c + 1) {
    puts("YES");
    while (c--) printf("3 2 ");
    printf("3");
    return true;
  }
  return false;
}

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a > 0 && solve(a, b, c, d, true)) return 0;
  if (b > 0 && solve(a, b, c, d, false)) return 0;
  if (a == 0 && b == 0 && solve(c, d)) return 0;
  if (a == 0 && c == b + d + 1) {
    puts("YES");
    printf("2");
    while (b--) printf(" 1 2");
    while (d--) printf(" 3 2");
    return 0;
  }
  puts("NO");
}