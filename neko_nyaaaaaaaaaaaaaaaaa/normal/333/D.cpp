#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> f;

int check(int k) {
      vector<vector<int>> b(1001, vector<int>(1001));
      for (int i = 1; i <= n; i++) {
            vector<int> d;
            for (int j = 1; j <= m; j++) {
                  if (f[i][j] >= k) {
                        for (int c: d) {
                              if (b[c][j]) return 1;
                              b[c][j] = 1;
                        }
                        d.push_back(j);
                  }
            }
      }
      return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    f.resize(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  cin >> f[i][j];
            }
    }

    int ans = 0;
    int lo = 0, hi = 1e9;
    while (lo < hi) {
            int mid = (lo + hi + 1)/2;

            if (check(mid)) {
                  lo = mid;
            } else {
                  hi = mid-1;
            }
    }
    cout << lo;

    return 0;
}