#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, petr;
int l[1000];
int r[1000];
int ans[1000];

void output() {
      for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {cout << "NO"; exit(0);}
      }
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
      }
      exit(0);
}

void solve() {
      petr--; int cnt = 0;
      for (int i = 0; i < n; i++) {
            if (l[i] == 0 && r[i] == 0 && ans[i] == 0) {
                  ans[i] = petr; cnt++;
            }
      }
      if (cnt == 0) output();

      int k = 0;
      for (int i = 0; i < n; i++) {
            if (ans[i] == petr) {
                  cnt--; k++;
            } else if (!ans[i]) {
                  r[i] -= cnt;
                  l[i] -= k;
            }
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n; petr = n+1;
      for (int i = 0; i < n; i++) cin >> l[i];
      for (int i = 0; i < n; i++) cin >> r[i];

      while (1) {
            solve();
      }

      return 0;
}