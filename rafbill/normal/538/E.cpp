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

using pt   = pair<int, int>;
using vec2 = pair<pt, pt>;

vector<int> A[200005];
int S[200005];

void dfs(int cur, int par = -1){
  if(A[cur].size() == 1 && par != -1){
    S[cur] = 1;
    return;
  }
  S[cur] = 0;
  for(auto const& c : A[cur]) if(c != par){
      dfs(c, cur);
      S[cur] += S[c];
    }
}

int dfs1(int cur, int par = -1);
int dfs2(int cur, int par = -1);

int dfs1(int cur, int par){
  if(A[cur].size() == 1 && par != -1){
    return 0;
  }
  int a = 0;
  for(auto const& c : A[cur]) if(c != par){
      a = max(a, S[cur]-S[c]+dfs2(c, cur));
    }
  return a;
}

int dfs2(int cur, int par){
  if(A[cur].size() == 1 && par != -1){
    return 0;
  }
  int a = 0;
  for(auto const& c : A[cur]) if(c != par){
      a += dfs1(c, cur);
    }
  return a;
}

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  FOR(i, n-1){
    int x, y; cin >> x >> y;
    x -=1; y -= 1;
    A[x].push_back(y);
    A[y].push_back(x);
  }
  if(n == 1){
    cout << "1 1" << endl;
    return 0;
  }
  dfs(0);
  auto p = dfs1(0);
  auto q = dfs2(0);
  cout << p+1 << " " << S[0]-q << endl;
  return 0;
}