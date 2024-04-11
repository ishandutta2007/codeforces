#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <list>
#include <bitset>

using namespace std;

using LL = long long int;

#define FOR(i, n) for(LL i = 0; i < n; ++i)
#define FORU(i, a, b) for(LL i = a; i <= b; ++i)
#define FORD(i, b, a) for(LL i = b; i >= a; --i)

int main(int, char**){
  char c;
  long r = 0;
  long i = 0;
  while(!cin.eof()){
    cin >> c;
    if(c == '\0' || c == '\n' || cin.eof() || !cin.good()){
      break;
    }
    r += (c == '+' ? 1 : -1) * (i % 2 == 0 ? 1 : -1);
    i++;
  }
  cout << (r == 0 ? "Yes" : "No") << endl;
  return 0;
}