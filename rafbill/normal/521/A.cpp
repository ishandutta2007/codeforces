#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <tuple>
#include <cstring>
#include <unordered_map>

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

int A[256];

const long long MOD = 1e9+7;

long long fexp(long long a, long long b){
  if(b == 1){
    return a;
  }else if(b % 2 == 0){
    long long c = fexp(a, b/2);
    return (c*c)%MOD;
  }else{
    long long c = fexp(a, b/2);
    return (c*c*a)%MOD;
  }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  FOR(i, 256) A[i] = 0;
  for(char c : s) A[(int)c] += 1;
  int count = 0, mx = 0;
  FOR(i, 256){
    if(A[i] > mx){
      mx = A[i];
      count = 1;
    }else if(A[i] == mx){
      count += 1;
    }
  }
  
  cout << fexp(count, n) << endl;
  
  return 0;
}