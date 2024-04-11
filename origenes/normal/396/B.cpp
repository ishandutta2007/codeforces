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

bool prime(int x) {
  int upp = sqrt(x) + 1;
  FOR(i, 2, upp) if (x % i == 0) return false;
  return true;
}

void solve() {
  int n; scanf("%d", &n);
  int p = n, q = n + 1;
  while (!prime(p)) p--;
  while (!prime(q)) q++;
  ll nom = n - p + 1, den = ll(p) * q;
  if (__gcd(2LL, den) == 1) {
    nom = nom * 2 + ll(p) * q;
    den = den * 2;
  } else nom = nom + ll(p) * q / 2;
  nom -= den / p;
  ll d = __gcd(nom, den);
  nom /= d, den /= d;
  printf("%lld/%lld\n", nom, den);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}