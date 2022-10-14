#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

   int T;
   cin >> T;
   while (T--) {
     int n;
     string a, b, c;
     cin >> a >> b >> c;
     n = a.size();
     int can = 1;
     for (int i = 0; i < n; i++) {
       if (c[i] == a[i] || c[i] == b[i]) {
         continue;
       }
       can = 0;
       break;
     }
     if (can) {
       cout << "YES\n";
     } else {
       cout << "NO\n";
     }
   }



}