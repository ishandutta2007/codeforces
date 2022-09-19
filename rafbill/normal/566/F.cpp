#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>

#define FOR(i, n) for (long long int i = 0; i < (n); ++i)
#define FORU(i, j, k) for (long long int i = (j); i <= (k); ++i)
#define FORD(i, j, k) for (long long int i = (j); i >= (k); --i)

using namespace std;

// SOLUTION

const int N = 1e6;

bool A[N+5]; // IS
int B[N+5];  // ALL
int V[N+5];  // MAX
int P[N+5];  // PREV

int main(int, char **) {
  ios::sync_with_stdio(false);
  int n; cin >> n; FOR(i, n){
    cin >> B[i];
    A[B[i]] = true;
  }
  int mx = -1;
  FOR(i, n){
    if(V[B[i]] > mx){
      mx = V[B[i]];
    }
    int k = 2;
    while(B[i]*k <= N){
      if(A[B[i]*k]){
        if(V[B[i]]+1 > V[B[i]*k]){
          V[B[i]*k] = V[B[i]]+1;
          P[B[i]*k] = B[i];
        }
      }
      k += 1;
    }
  }
  cout << mx+1 << endl;

  return 0;
}