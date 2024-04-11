#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (k); ++i)
#define FORD(i, j, k) for(int i = (j); i >= (k); --i)

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

int main(int, char**){
  ios::sync_with_stdio(false);
  ll a, b; cin >> a >> b;
  FORU(i, b+1, b+a+1) cout << i << " ";
  FORD(i, b, 1) cout << i << " ";
  return 0;
}