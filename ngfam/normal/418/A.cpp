#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  if(k * n > n * (n - 1) / 2) {
    cout << -1;
    return 0;
  }

  cout << k * n << endl;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < k; ++j) {
      cout << (i + 1) << " " << (i + j + 1) % n + 1 << "\n";
    }
  }

  return 0;
}