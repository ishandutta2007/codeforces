#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = j; i <= (k); ++i)
#define FORD(i, j, k) for(long i = j; i >= (k); --i)

long P[100001];

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n; cin >> n;
  FOR(i, 100001) P[i] = -1;
  bool c = true;
  FOR(i, n){
    long x, k; cin >> x >> k;
    if(x > P[k] + 1 && c){
      c = false;
    }else{
      P[k] = max(x, P[k]);
    }
  }
  if(c) cout << "YES" << endl;
  else 
      cout << "NO" << endl;
  return 0;
}