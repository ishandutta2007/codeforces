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



int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n; cin >> n;
  long c = 0, r = 0;
  FOR(i, n){
    long a; cin >> a;
    if (a == -1){
      if(c == 0){
        r++;
      }else{
        c--;
      }
    }else{
      c+=a;
    }
  }
  cout << r << endl;
  return 0;
}