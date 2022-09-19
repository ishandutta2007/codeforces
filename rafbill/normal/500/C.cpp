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

int W[1000];
int B[2000];
bool L[1000][1000];

int main(int, char**){
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  FOR(i, n) cin >> W[i];
  FOR(i, n) FOR(j, n) L[i][j] = false;
  int w = 0;
  FOR(i__, m){
    int b; cin >> b; b -= 1;
    FOR(i, n) if(i != b && L[b][i]){
      w += W[i];
      L[b][i] = false;
    }
    FOR(i, n) if(i != b) L[i][b] = true;
  }
  cout << w << endl;
  return 0;
}