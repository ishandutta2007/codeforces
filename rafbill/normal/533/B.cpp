#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <deque>
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

using pt   = pair<long long int, long long int>;
using vec2 = pair<pt, pt>;

vector<int> A[200005];
long long int B[200005];

pt dfs(int cur, int par){
  long long int mdelta = 10e14;
  long long int mx = 0;
  bool even = true;
  for(auto const& c : A[cur])
    if(c != par){
      pt x = dfs(c, cur);
      mdelta = min(mdelta, abs(x.X - x.Y));
      mx += max(x.X, x.Y);
      if(x.X < x.Y){
        even = not even;
      }
    }
  if(even){
    return make_pair(mx, B[cur]+mx);
  }else{
    return make_pair(mx-mdelta, max(B[cur]+mx-mdelta, mx));
  }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  FOR(i, n){
    int p, a; cin >> p >> a;
    if(p != -1){
      A[i].push_back(p-1);
      A[p-1].push_back(i);
    }
    B[i] = a;
  }
  auto ppp = dfs(0, -1);
  cout << max(ppp.X, ppp.Y) << endl;
  return 0;
}