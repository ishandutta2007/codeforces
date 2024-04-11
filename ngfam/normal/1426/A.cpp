#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, x; cin >> n >> x;

    if(n <= 2) cout << 1 << endl;
    else cout << 1 + (n - 2 + x - 1) / x << endl;
  }

  return 0;
}