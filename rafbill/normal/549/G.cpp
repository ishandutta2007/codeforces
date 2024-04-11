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

int A[200000];
int B[200000];

bool solve(int* IN, int* OUT, int i, int j){
  if(i == j){
    OUT[i] = IN[i];
    return true;
  }else{
    int k = (i+j)/2;
    if(solve(IN, OUT, i, k) && solve(IN, OUT, k+1, j)){
      FORU(a, i, j) IN[a] = OUT[a];
      int l = k+1;
      int i_ = i;
      while(i <= k && l <= j){
        int vi = IN[i] + i - i_;
        int vl = IN[l] + l - i_;
        if(vi == vl){
          return false;
        }else if(vi < vl){
          OUT[i_] = vi;
          i += 1;
        }else{
          OUT[i_] = vl;
          l += 1;
        }
        i_ += 1;
      }
      while(i <= k){
        int vi = IN[i] + i - i_;
        OUT[i_] = vi;
        i += 1;
        i_ += 1;
      }
      while(l <= j){
        int vl = IN[l] + l - i_;
        OUT[i_] = vl;
        l += 1;
        i_ += 1;
      }
      return true;
    }else{
      return false;
    }
  }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  int n; cin >> n; FOR(i, n) cin >> A[i];
  if(solve(A, B, 0, n-1)){
    FOR(i, n) cout << B[i] << " "; cout << endl;
  }else{
    cout << ":(" << endl;
  }
  return 0;
}