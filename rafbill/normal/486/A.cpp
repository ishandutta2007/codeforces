#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
#include <array>
#include <iostream>
#include <utility>
#include <tuple>

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, j, k) for (int i = (j); i <= (k); ++i)
#define FORD(i, j, k) for (int i = (j); i >= (k); --i)

using namespace std;

int main(int, char**)
{
  long long int n; cin >> n;
  if(n % 2 == 0) cout << n / 2;
  else cout << - (n+1)/2;
  cout << endl;
  return 0;
}