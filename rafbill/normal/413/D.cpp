#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <functional>
#include <iomanip>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

long AAA1[10000];
long AAA2[10000];

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n, k; cin >>n>>k;
  long* P = AAA1;
  long* Q = AAA2;
  FOR(i, 10000) P[i] = 0;
  long x; cin >> x;
  if(x == 2 || x == 0) P[1] = 1;
  if(x == 4 || x == 0) P[2] = 1;
  FOR(i, n-1){
    FOR(j, 10000) Q[j] = 0;
    cin >> x;
    if(x == 2 || x == 0){
      FORU(j, 1, 1<<(k-1)){
        Q[j] += P[j-1];
        Q[j] %= 1000000007;
      }
      Q[1<<(k-1)] += P[1<<(k-1)];
      Q[1<<(k-1)] %= 1000000007;
    }
    if(x == 4 || x == 0){
      Q[1<<(k-1)] += P[1<<(k-1)];
      Q[1<<(k-1)] %= 1000000007;
      FOR(j, 1<<(k-1)) if(j % 2 == 1){
        Q[2] += P[j];
        Q[2] %= 1000000007;
      } else{
        Q[j+2] += P[j];
        Q[j+2] %= 1000000007;
      }
    }
    swap(P, Q);
  }
  cout << P[1<<(k-1)] << endl;
  return 0;
}