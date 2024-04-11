#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = 998244353;
int ft[5008];
int nCr[5008][5008];

void init() {
      for (int i = 0; i <= 5000; i++) {
            nCr[i][0] = nCr[i][i] = 1;
            for (int j = 1; j <= i; j++) {
                  nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % M;
            }
      }
      ft[0] = 1;
      for (int i = 1; i <= 5000; i++) {
            ft[i] = (ft[i-1]*i) % M;
      }
}

int solve(int a, int b) {
      int ans = 0;
      for (int i = 0; i <= min(a, b); i++) {
            int tmp = (nCr[a][i] * nCr[b][i]) % M;
            tmp = (tmp*ft[i]) % M;
            ans = (ans + tmp) % M;
      }
      return ans;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      init();

      int a, b, c; cin >> a >> b >> c;
      int ans1 = 0, ans2 = 0, ans3 = 0;
      ans1 = solve(a, b);
      ans2 = solve(b, c);
      ans3 = solve(c, a);

      int ans = (ans1*ans2) % M;
      ans = (ans*ans3) % M;

      cout << ans;

      return 0;
}