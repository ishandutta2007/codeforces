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
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int fib[maxn];
int n;
char s[maxn];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n) if (s[i] == 'm' || s[i] == 'w') {
    puts("0");
    return 0;
  }
  fib[0] = fib[1] = 1;
  FOR(i, 2, n) fib[i] = add(fib[i - 1], fib[i - 2]);
  int ans = 1;
  for (int i = 1; i <= n; ) {
    if (s[i] != 'n' && s[i] != 'u') {
      i++;
      continue;
    }
    int j = i + 1;
    while (j <= n && s[j] == s[i]) j++;
    ans = mul(ans, fib[j - i]);
    i = j;
  }
  printf("%d", ans);
}