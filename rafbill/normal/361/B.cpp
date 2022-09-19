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
  if(n == k){
    cout << -1 << endl;
  }else{
    FORU(i, 1, n-k-1){
      cout << i+1 << " ";
    }
    cout << 1 << " ";
    FORU(i, n-k+1, n){
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}