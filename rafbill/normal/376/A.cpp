#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

#define FOR(i, n) for(unsigned i = 0; i < (n); ++i)
#define FORU(i, j, k) for(unsigned i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(unsigned i = (j); i >= (k); --i)

int main(int, char**){
  string s; cin >> s;
  long long ip;
  FOR(i, s.size()){
    if(s[i] == '^') ip = i;
  }
  long long bal = 0;
  FOR(i, s.size()){
    if(s[i] >= '1' && s[i] <= '9') bal += (ip - i) * (s[i] - '0');
  }
  if(bal < 0) cout << "right\n";
  else if(bal > 0) cout << "left\n";
  else cout << "balance\n";
  return 0;
}