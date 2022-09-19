#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <bitset>
#include <set>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, a, b) for(long i = a; i <= (b); ++i)
#define FORR(i, a, b) for(long i = a; i >= (b); --i)

using namespace std;

int main(int, char**){
  std::string s; cin >> s;
  char l = 0;
  bool l2 = false;
  bool n2 = false;
  int cont = 0;
  for(char c : s){
    if(c == l){
      cont++;
      if(cont < 3 && !l2){
        cout << c;
        n2 = true;
      }
    }else{
      l = c;
      l2 = n2;
      n2 = false;
      cont = 1;
      cout << c;
    }
  }
  cout << endl;
  return 0;
}