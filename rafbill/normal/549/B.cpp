#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <tuple>
#include <queue>

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(int i = (j); i >= (k); --i)

#define X first
#define Y second
#define union union_

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

struct union_find{
  union_find(int n) : A(n), R(n){
    FOR(i, n) A[i] = i;
    FOR(i, n) R[i] = 0;
  }

  int find(int i){
    if(A[i] != i){ A[i] = find(A[i]); }
    return A[i];
  }

  int union(int i, int j){
    i = find(i); j = find(j);
    if(i != j){
      if(R[i] < R[j]){
        A[i] = j;
      }else if(R[j] < R[i]){
        A[j] = i;
        R[i] += R[i] == R[j];
      }
    }
    return A[i];
  }

  vector<int> A;
  vector<int> R;
};

bool A[100][100];
int B[100];
int C[100];

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  FOR(i, n){
    string s; cin >> s;
    FOR(j, n) A[i][j] = s[j] == '1';
  }
  FOR(i, n) cin >> B[i];
  vector<int> w;
  queue<int> q;
  FOR(i, n) { C[i] = 0; if(B[i] == 0) q.push(i); }
  while(!q.empty()){
    int i = q.front(); q.pop(); w.push_back(i);
    FOR(j, n) if(A[i][j]){
      C[j] += 1; if(B[j] == C[j]) q.push(j);
    }
  }

  cout << w.size() << endl;
  for(auto const& i : w) cout << i+1 << " "; cout << endl;
  
  return 0;
}