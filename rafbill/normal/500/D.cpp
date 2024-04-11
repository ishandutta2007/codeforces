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

long long int n;
vector<pair<long long int, long long int>> A[100005];
long long int S[100005];
long long int B[100005];
long long int L[100005];

void dfs1(long long int i, long long int p = -1){
  S[i] = 1;
  for(auto const& a : A[i])
    if(a.first != p){
      dfs1(a.first, i);
      S[i] += S[a.first];
      B[a.second] = S[a.first] * (n - S[a.first]);
    }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  scanf("%I64d", &n);
  FOR(i, n-1){
    long long int a, b, l; scanf("%I64d %I64d %I64d", &a, &b, &l); a -= 1; b -= 1;
    L[i] = l;
    A[a].push_back(make_pair(b, i));
    A[b].push_back(make_pair(a, i));
  }
  dfs1(0);
  long long int ans = 0;
  FOR(i, n-1){
    ans += L[i] * B[i];
  }
  long long int q; scanf("%I64d", &q);
  FOR(i, q){
    long long int r, w; scanf("%I64d %I64d", &r, &w);
    r -= 1;
    ans -= B[r] * (L[r] - w);
    L[r] = w;
    printf("%.10lf\n", static_cast<double>(6*ans)/static_cast<double>(n*(n-1)));
  }
  return 0;
}