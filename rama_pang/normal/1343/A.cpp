#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k = 1;
    while (true) {
      int all = (1 << (k + 1)) - 1;
      if (n % all == 0) {
        cout << (n / all) << "\n";
        goto DONE;
      }
      k++;
    }
    DONE: continue;
  }  

}