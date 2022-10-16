#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      int n;
      cin >> n;
      vector<int> a(n);
      int ans = 0;
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                  int tmp = 0;
                  for (int k = 0; k < n; k++) {
                        if (k >= i && k <= j) {tmp += 1 - a[k];}
                        else {tmp += a[k];}
                  }
                  ans = max(tmp, ans);
            }
      }
      cout << ans;
}