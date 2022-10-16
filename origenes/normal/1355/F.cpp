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

const vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

ll ask(ll Q) {
  cout << "? " << Q << endl;
  ll A;
  cin >> A;
  return A;
}

void solve() {
  int i = 0;
  double prod = 1;
  int rem = 22, X = 1;
  vector<int> ans = {1};
  while (rem--) {
    ll Q = 1;
    int pi = i;
    while (i < 168 && prod * primes[i] < 1e18) {
      prod *= primes[i];
      Q *= primes[i];
      i++;
    }
    ll g = ask(Q);
    FOR(j, pi, i - 1) if (j < 168 && g % primes[j] == 0) {
        Q = 1;
        while (Q < 1e9) Q *= primes[j];
        if (rem == 0) {
          ans.eb(2);
          continue;
        }
        ll d = ask(Q);
        X *= d;
        int now = 0;
        while (d > 1) {
          d /= primes[j];
          now++;
        }
        ans.eb(now + 1);
        rem--;
      }
    if (i == 168) break;
    prod = 1;
  }
  ll ret = 1;
  for (auto x : ans) ret *= x;
  ret *= 2;
  chkmax(ret, 8LL);
  cout << "! " << ret << endl;
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}