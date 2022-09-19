#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <functional>

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(long i = (j); i >= (k); --i)

using namespace std;

int main(int, char**){
  ios_base::sync_with_stdio(false);
  string S[100000];
  long n; cin >> n;
  FOR(i, n) cin >> S[i];
  string R(S[0].size(), '.');
  FOR(i, S[0].size()){
    FOR(j, n) if(S[j][i] != '?'){
      if(R[i] == '.') R[i] = S[j][i];
      else if(R[i] != S[j][i]) R[i] = '?';
    }
  }
  for(char c : R){
    switch(c){
      case '.': cout << 'a'; break;
      default: cout << c; break;
    }
  }
  cout << endl;

  return 0;
}