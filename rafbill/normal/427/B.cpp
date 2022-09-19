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
  long n, t, c; cin >> n >> t >> c;
  long cur = 0;
  long r = 0;
  auto f = [&](){
    r += max<long>(0, cur-c+1);
    cur = 0;
  };
  FOR(i, n){
    long b; cin >> b;
    if(b > t){
      f();
    }else{
      cur += 1;
    }
  }
  f();
  cout << r << endl;
  return 0;
}