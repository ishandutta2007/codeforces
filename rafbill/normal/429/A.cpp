#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = j; i <= (k); ++i)
#define FORD(i, j, k) for(long i = j; i >= (k); --i)

set<int> A[100000];
int AC[100000];
int GL[100000];
list<int> O;
bool E[100000];

int main(int, char**){


std::function<int(int, bool, bool, bool)> dfs = [&](int i, bool c, bool s1, bool s2){
  E[i] = true;
  int r = 0;
  if(c){
    if((s2 xor AC[i]) == GL[i]){
      O.push_back(i);
      r = 1;
      s2 = !s2;
    }
  }else{
    if((s1 xor AC[i]) == GL[i]){
      O.push_back(i);
      r = 1;
      s1 = !s1;
    }
  }
  for(int j : A[i]) if(!E[j]){
    r += dfs(j, !c, s1, s2);
  }
  return r;
};

  long n; cin >> n;
  FOR(i, n-1){
    int u, v; cin >> u >> v;
    A[u-1].insert(v-1);
    A[v-1].insert(u-1);
  }
  FOR(i, n) cin >> AC[i];
  FOR(i, n) cin >> GL[i];
  FOR(i, n) E[i] = false;
  cout << dfs(0, 0, 1, 1) << "\n";
  for(int i : O) cout << i+1 << "\n";
  return 0;
}