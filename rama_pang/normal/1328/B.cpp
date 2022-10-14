#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
      if (k > i) {
        k -= i;
      } else {
        for (int j = 1; j < n - i; j++) {
          cout << 'a';
        }
        cout << 'b';
        int rest = i;
        for (int j = 1; j <= i - k; j++) {
          cout << 'a';
        }
        cout << 'b';
        for (int  j = i - k + 1; j < i; j++) {
          cout << 'a';
        }
        break;
      }
    }
    cout << '\n';
  }

}