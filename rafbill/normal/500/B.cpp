#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <tuple>

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(int i = (j); i >= (k); --i)

#define X first
#define Y second

using namespace std;

template <typename T>
void hash_combine (size_t& seed, const T& val){
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}
template <typename T, typename... Ts>
void hash_combine (size_t& seed, const T& val, const Ts&... args){
  hash_combine(seed, val);
  hash_combine(seed, args...);
}
void hash_combine (size_t&){}
template <typename... Ts>
size_t hash_val (const Ts&... args){
  size_t seed = 0;
  hash_combine (seed, args...);
  return seed;
}

using pt   = pair<int, int>;
using vec2 = pair<pt, pt>;

enum D8 { D1, D2, D3, D4, D6, D7, D8, D9 };
pt D8O[8] = { {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };

int P[500];
int Q[500];
bool A[500][500];

void do_swap(int i, int j){
  swap(Q[P[i]], Q[P[j]]);
  swap(P[i], P[j]);
}

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  FOR(i, n) { cin >> P[i]; P[i] -=1; Q[P[i]] = i; }
  FOR(i, n) FOR(j, n) { char c; cin >> c; A[i][j] = c == '1'; }
  FOR(i, n) FOR(j, n) FOR(k, n){
    A[j][k] = A[j][k] || (A[j][i] && A[i][k]);
  }
  FOR(i, n) {
    FOR(j, n) {
      if(Q[j] >= i && A[i][Q[j]]){
        do_swap(i, Q[j]);
        break;
      }
    }
  }
  FOR(i, n) cout << P[i]+1 << " "; cout << endl;
  return 0;
}