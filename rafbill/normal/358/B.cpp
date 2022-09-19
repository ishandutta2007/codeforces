#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <iostream>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORD(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

int main(int, char**){
  long n; cin >> n;
  std::string msg = "<3";
  FOR(i, n){
    string s;
    cin >> s;
    msg += s + "<3";
  }
  std::string str; cin >> str;
  str += "\n";
  unsigned pos = 0;
  unsigned siz = str.size();
  for(char c : msg){
    while(pos != siz && str[pos] != c){
      pos++;
    }
    if(pos == siz){
      cout << "no" << endl;
      return 0;
    }
    pos++;
  }
  cout << "yes" << endl;
  return 0;
}