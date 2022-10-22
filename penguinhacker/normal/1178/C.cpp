#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int m, n;
int main() {
   cin >> m >> n;
   int ans = 1;
   
   for (int i=0; i<m+n; ++i) {
      ans = (2*ans)%MOD;
   }

   cout << ans;
//lol
   return 0;
}