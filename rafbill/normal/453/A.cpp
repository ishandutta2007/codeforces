#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <tuple>

using namespace std;

#define ll long long
#define ull unsigned long long

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define FORU(i, j, k) for(ll i = j; i <= (k); ++i)
#define FORD(i, j, k) for(ll i = j; i >= (k); --i)

#define pf push_front
#define pb push_back

#define mp make_pair
#define f first
#define s second

// const double p = 1.0/6.0;
// using mat = array<array<double,6>,6>;
// mat A = {
//   {p, 0, 0, 0, 0, 0},
//   {p, 2*p, 0, 0, 0, 0},
//   {p, p, 3*p, 0, 0, 0},
//   {p, p, p, 4*p, 0, 0},
//   {p, p, p, p, 5*p, 0},
//   {p, p, p, p, p, 6*p},
// };

// mat mult(mat const& a, mat const& b){
//   mat c;
//   FOR(i, 6) FOR(j, 6){
//     c[i][j] = 0;
//     FOR(k, 6){
//       c[i][j] += a[i][k]*b[k][j];
//     }
//   }
//   return c;
// }

// mat exp(mat const& a, ll n){
//   if(n == 1){
//     return 
//   }
// }

double sq(double a){ return a * a; }

double exp(double const& a, ll n){
  if(n == 0) return 1.0;
  else if(n == 1) return a;
  else if(n % 2) return a * sq(exp(a, n/2));
  else return sq(exp(a, n/2));
}

int main(int, char**){
  ios::sync_with_stdio(false);
  ll m, n; cin >> m >> n;
  double dm = m;
  double p = 0;
  FORU(i, 1, m){
    p += (m - i + 1) * (exp((dm-i+1)/dm, n) - exp((dm-i)/dm, n));
  }
  printf("%.5f", p);
  return 0;
}