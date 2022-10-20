#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  int n;
  cin >> n;
  if(n % 2) cout << "black";
  else cout << "white" << endl << "1 2";
  return 0;
}