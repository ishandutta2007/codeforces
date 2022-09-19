#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <bitset>
#include <functional>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

long A[1048576];
long long B[30];
long long C[30];

long P[30];


void f(long n, long o){
  if(n > 1){
    f(n-1, o);
    f(n-1, o + P[n-1]);
  }
  sort(A + o, A + o + P[n-1]);
  sort(A + o + P[n-1], A + o + P[n]);
  long i = o;
  long j = o + P[n-1];
  while(i != o + P[n-1] && j != o + P[n]){
    if(A[i] < A[j]){
      B[n] += o + P[n] - j;
      i += 1;
    }else{
      j += 1;
    }
  }
  i = o;
  j = o + P[n-1];
  while(i != o + P[n-1] && j != o + P[n]){
    if(A[i] <= A[j]){
      i += 1;
    }else{
      C[n] += o + P[n-1] - i;
      j += 1;
    }
  }
}

int main(int, char**){
  ios_base::sync_with_stdio(false);
  P[0] = 1;
  FORU(i, 1, 29) P[i] = 2 * P[i-1];
  long n; cin >> n;
  FOR(i, P[n]) cin >> A[i];
  FOR(i, 29) B[i] = 0;
  FOR(i, 29) C[i] = 0;

  f(n, 0);
  
  bitset<30> BS;
  long m; cin >> m;
  FOR(i, m){
    long q; cin >> q;
    while(q != 0){
      BS[q] = not BS[q];
      q -= 1;
    }
    long long r = 0;
    FOR(j, n+1){
      r += BS[j] ? B[j] : C[j];
    }
    cout << r << "\n";
  }



  return 0;
}