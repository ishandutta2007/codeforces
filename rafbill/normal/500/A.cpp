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

int A[50000];
bool OK[50000];

int main(int, char**){
  ios::sync_with_stdio(false);
  int n, t; cin >> n >> t; t -= 1;
  FOR(i, n-1) cin >> A[i];
  FOR(i, n) OK[i] = false;
  OK[0] = true;
  FOR(i, n-1) if(OK[i]){
    OK[i+A[i]] = true;
  }
  cout << (OK[t]?"YES":"NO") << endl;
  return 0;
}