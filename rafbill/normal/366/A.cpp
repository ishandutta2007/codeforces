#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <bitset>
#include <set>
#include <functional>
#include <tuple>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, a, b) for(long i = a; i <= (b); ++i)
#define FORR(i, a, b) for(long i = a; i >= (b); --i)

using namespace std;

int main(int, char**){
  long n;
  cin >> n;
  bool dd = false;
  FOR(i, 4){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(dd) continue;
    if(min(a,b) + min(c, d) <= n){
      cout << i+1 << " " << min(a,b) << " " << n-min(a, b) << endl;
      dd = true;
    }
  }
  if(dd == false) cout << "-1" << endl;

  return 0;
}