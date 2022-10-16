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

const int MOD = 1e9 + 7;
const int inv2 = 5e8 + 4;

ll pw[35], even[35], odd[35], se[35], so[35];

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int get(ll upp) {
  int turn = 0;
  int ret = 0;
  while (upp) {
    int pos = turn >> 1;
    if (turn & 1) {
      int fi = (se[pos] + 2) % MOD;
      if (upp <= even[pos]) {
        int now = mul(mul(add(fi, add(fi, mul((upp - 1) % MOD, 2))), upp % MOD), inv2);
        return add(ret, now);
      } else {
        int now = mul(mul(add(fi, add(fi, mul((even[pos] - 1) % MOD, 2))), even[pos] % MOD), inv2);
        ret = add(ret, now);
        upp -= even[pos];
      }
    } else {
      int fi = (so[pos] + 2) % MOD;
      if (upp <= odd[pos]) {
        int now = mul(mul(add(fi, add(fi, mul((upp - 1) % MOD, 2))), upp % MOD), inv2);
        return add(ret, now);
      } else {
        int now = mul(mul(add(fi, add(fi, mul((odd[pos] - 1) % MOD, 2))), odd[pos] % MOD), inv2);
        ret = add(ret, now);
        upp -= odd[pos];
      }
    }
    turn++;
  }
  return ret;
}

int main() {
  pw[0] = odd[0] = 1;
  even[0] = 2;
  se[0] = so[0] = 0;
  FOR(i, 1, 30) {
    pw[i] = pw[i - 1] << 2;
    odd[i] = pw[i];
    even[i] = odd[i] << 1;
    se[i] = se[i - 1] + even[i - 1] * 2;
    so[i] = so[i - 1] + odd[i - 1] * 2;
  }
  REP(i, 31) so[i]--;
  ll lo, hi;
  cin >> lo >> hi;
  cout << add(get(hi), MOD -  get(lo - 1));
}