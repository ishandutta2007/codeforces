#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <functional>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

int main(int, char**){
  ios_base::sync_with_stdio(false);
  long n; cin >> n;
  long lo = -2e9, hi = 2e9;
  FOR(i, n){
    string s; cin >> s;
    long a; char c;
    cin >> a >> c;
    if((s == "<" && c=='Y') || (s == ">=" && c=='N')){
      hi = min(hi, a-1);
    }else if((s == "<" && c=='N') || (s == ">=" && c=='Y')){
      lo = max(lo, a);
    }else if((s == ">" && c=='Y') || (s == "<=" && c=='N')){
      lo = max(lo, a+1);
    }else if((s == ">" && c=='N') || (s == "<=" && c=='Y')){
      hi = min(hi, a);
    }else{
      throw 0;
    }
  }
  if(lo <= hi){
    cout << lo << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}