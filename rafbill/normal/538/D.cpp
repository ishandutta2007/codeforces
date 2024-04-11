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

string A[50];
int S[200][200];

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n;
  FOR(i, n){
    cin >> A[i];
  }
  FOR(i, 2*n-1) FOR(j, 2*n-1){
    S[i][j] = 1;
  }
  FOR(x, n) FOR(y, n) if(A[x][y] == 'o'){
    FOR(i, n) FOR(j, n) if(A[i][j] == '.'){
      int dx = n-1+i-x;
      int dy = n-1+j-y;
      S[dx][dy] = 0;
    }
  }
  FOR(i, n) FOR(j, n) if(A[i][j] == 'x'){
    bool ok = false;
    FOR(x, n) FOR(y, n) if(A[x][y] == 'o'){
      int dx = n-1+i-x;
      int dy = n-1+j-y;
      if(S[dx][dy]) ok = true;
    }
    if(!ok){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  FOR(i, 2*n-1){
    FOR(j, 2*n-1){
      if(i == n-1 && j == n-1){
        cout << 'o';
      }else{
        cout << ((S[i][j] == 1)?'x':'.');
      }
    }
    cout << endl;
  }
  return 0;
}