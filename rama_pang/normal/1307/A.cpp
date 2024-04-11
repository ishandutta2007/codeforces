#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
      while (d >= i && a[i] > 0) {
        d -= i;
        a[i]--;
        a[0]++;
      }
    }
    cout << a[0] << "\n";
  }  

}