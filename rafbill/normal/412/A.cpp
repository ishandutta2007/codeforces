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
  long n, k; cin >> n >> k;
  string s; cin >> s;
  if(n-k < k-1){
    FOR(i, n-k) cout << "RIGHT\n";
    FORR(i, n-1, 1) cout << "PRINT " << s[i] << "\nLEFT\n";
    cout << "PRINT " << s[0] << "\n";
  }else{
    FOR(i, k-1) cout << "LEFT\n";
    FORU(i, 0, n-2) cout << "PRINT " << s[i] << "\nRIGHT\n";
    cout << "PRINT " << s[n-1] << "\n";
  }
  return 0;
}