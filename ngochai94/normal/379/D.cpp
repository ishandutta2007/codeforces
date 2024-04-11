#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long k, x, n, m;
long long cnta[55], cntb[55], swa[55], swb[55], ewa[55], ewb[55], cntaa[55], cntbb[55], cntab[55], cntba[55];

// a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

// Inverse module a^-1 % m with a and m coprime
long long inverseMod(long long a, long long m) {
  long long x, y;
  extgcd(a, m, x, y);
  return (x + m) % m;
}

pair<long long, long long> solve(long long a, long long b, long long c, long long maxx, long long maxy) {
  // cout << a << ' ' << b << ' ' << c << ' ' << maxx << ' ' << maxy << endl;
  // solve a * x + b * y = c
  if (a * maxx + b * maxy < c) return {-1, -1};
  if (c < 0) return {-1, -1};
  if (!c) return {0, 0};
  if (!a) {
    if (c % b) return {-1, -1};
    return {0, c / b};
  }
  if (!b) {
    if (c % a) return {-1, -1};
    return {c / a, 0};
  }
  long long tmp = __gcd(a, b);
  // BUG(tmp);
  a /= tmp;
  b /= tmp;
  if (c % tmp) return {-1, -1};
  c /= tmp;
  long long x0 = (c * inverseMod(a, b)) % b;
  // BUG(x0);
  maxx = min(maxx, c / a);
  maxy = min(maxy, c / b);
  long long x = (maxx - x0) / b * b + x0;
  long long y = (c - a * x) / b;
  // cout << x << ' ' << y << endl;
  if (x >= 0 && y >= 0 && a * x + b * y == c && y <= maxy && x <= maxx) return {x, y};
  else return {-1, -1};
}

void out (int sc, int ea, int len, int ac) {
  if (sc) cout << "C";
  REP (i, ac) cout << "AC";
  REP (i, len - sc - ea - 2 * ac) cout << "Z";
  if (ea) cout << "A";
  cout << endl;
}

int main(){
  // auto p = solve(3, 5, 54, 11, 15);
  // cout << p._1 << ' ' << p._2 << endl;
  // return 0;
  cnta[1] = cntb[2] = swa[1] = ewa[1] = swb[2] = ewb[2] = 1;
  cin >> k >> x >> n >> m;
  FOR (i, 3, k) {
    cnta[i] = cnta[i - 1] + cnta[i - 2];
    cntb[i] = cntb[i - 1] + cntb[i - 2];
    cntaa[i] = cntaa[i - 1] + cntaa[i - 2];
    cntab[i] = cntab[i - 1] + cntab[i - 2];
    cntbb[i] = cntbb[i - 1] + cntbb[i - 2];
    cntba[i] = cntba[i - 1] + cntba[i - 2];
    swa[i] = swa[i - 2];
    swb[i] = swb[i - 2];
    ewa[i] = ewa[i - 1];
    ewb[i] = ewb[i - 1];
    cntaa[i] += ewa[i - 2] * swa[i - 1];
    cntab[i] += ewa[i - 2] * swb[i - 1];
    cntbb[i] += ewb[i - 2] * swb[i - 1];
    cntba[i] += ewb[i - 2] * swa[i - 1];
  }
  long long a = cnta[k], b = cntb[k], ab = cntab[k], ba = cntba[k], aa = cntaa[k], bb = cntbb[k];
  // BUG(a);
  // BUG(b);
  REP (asc, 2) REP (aea, 2) REP (bsc, 2) REP (bea, 2) {
    if (asc + aea > n || bsc + bea > m) continue;
    long long maxx = (n - asc - aea) / 2;
    long long maxy = (m - bsc - bea) / 2;
    long long c = x;
    if (aea && bsc) c -= ab;
    if (bsc && bea) c -= bb;
    if (bea && asc) c -= ba;
    if (aea && asc) c -= aa;
    auto p = solve(a, b, c, maxx, maxy);
    // cout << p._1 << ' ' << p._2 << endl;
    if (p._1 >= 0 && p._2 >= 0) {
      out(asc, aea, n, p._1);
      out(bsc, bea, m, p._2);
      return 0;
    }
  }
  cout << "Happy new year!";
}