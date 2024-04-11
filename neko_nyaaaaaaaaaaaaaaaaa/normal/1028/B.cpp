#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      for (int i = 0; i <= 2000; i++) {
            if (i % 2) cout << 5;
            else cout << 4;
      }
      cout << 5 << endl;
      for (int i = 0; i <= 2000; i++) {
            if (i % 2) cout << 4;
            else cout << 5;
      }
      cout << 5 << endl;

      return 0;
}