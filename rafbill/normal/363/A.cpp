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

void pdigit(char d){
  switch(d){
    case '0':
      cout << "O-|-OOOO" << endl;
      break;
    case '1':
      cout << "O-|O-OOO" << endl;
      break;
    case '2':
      cout << "O-|OO-OO" << endl;
      break;
    case '3':
      cout << "O-|OOO-O" << endl;
      break;
    case '4':
      cout << "O-|OOOO-" << endl;
      break;
    case '5':
      cout << "-O|-OOOO" << endl;
      break;
    case '6':
      cout << "-O|O-OOO" << endl;
      break;
    case '7':
      cout << "-O|OO-OO" << endl;
      break;
    case '8':
      cout << "-O|OOO-O" << endl;
      break;
    case '9':
      cout << "-O|OOOO-" << endl;
      break;
  }
}

int main(int, char**){
  std::string s; cin >> s;
  for_each(s.rbegin(), s.rend(), pdigit);
  return 0;
}