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
  int n, k;
  cin >> n >> k;
  FOR(a, n){
    FOR(b, n){
      cout << (a == b ? k : 0) << ' ';
    }
    cout << endl;
  }
  return 0;
}