#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  int n1, n2;
  cin >> n1 >> n2;
  cout << ((n1 <= n2)? "Second" : "First");
  return 0;
}