#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n+2);
  REP(i,n) cin>>a[i+1];
  a[n+1] = 1000000001;
  vector<bool> iso(n+1);
  REP(i,n+1) iso[i] = a[i] < a[i+1];
  int st = -1, ed = n-1;
  bool ok = true;
  REP(i,n) {
    if (iso[i] && !iso[i+1]) {
      if (st >= 0) {
        ok = false;
        break;
      } else {
        st = i;
      }
    } else if (!iso[i] && iso[i+1]) {
      ed = i;
    }
  }
  if (ok) {
    if (st < 0) {
      cout << "yes" << endl;
      cout << "1 1" << endl;
    } else {
      if (a[st] < a[ed+1] && a[st+1] < a[ed+2]) {
        cout << "yes" << endl;
        cout << (st+1) <<' '<<(ed+1)<<endl;
      } else
        cout<<"no"<<endl;
    }
  } else
    cout << "no"<<endl;
  return 0;
}