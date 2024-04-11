#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int prime[15000001], countdiv[15000001];

void init() {
      for (int i = 2; i * i < 15000001; ++i)
        if (!prime[i])
            for (int j = i * i; j < 15000001; j += i)
                prime[j] = i;


    for (int i = 1; i < 15000001; ++i)
        if (!prime[i]) prime[i] = i;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      init();

      int n; cin >> n;
      int a[n];
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      int g = a[0];
      int flag = 1;
      for (int i = 1; i < n; i++) {
            g = __gcd(g, a[i]);
            if (a[i] != a[i-1]) flag = 0;
      }
      if (flag) {cout << -1; return 0;}
      for (int i = 0; i < n; i++) {
            a[i] /= g;
      }

      int ans = 0;
      for (int i = 0; i < n; i++) {
            int k = a[i];
            while (k > 1) {
                  int d = prime[k];
                  countdiv[d]++;

                  ans = max(ans, countdiv[d]);

                  while (k % d == 0) k /= d;
            }
      }

      cout << n-ans;

      return 0;
}