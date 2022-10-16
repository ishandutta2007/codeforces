#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      cout << fixed << setprecision(8);

      int n; cin >> n;
      vector<int> a(200008);
      vector<int> s(1);
      ll sum = 0, sz = 1;
      while (n--) {
            int q; cin >> q;
            if (q == 2) {
                  int k; cin >> k;
                  sz++; sum += k;
                  s.push_back(k);
            } else if (q == 1) {
                  int x, p; cin >> x >> p;
                  a[x-1] += p; sum += x*p;
            } else {
                  sum -= s.back();
                  s.pop_back();
                  sz--;
                  sum -= a[sz];
                  a[sz-1] += a[sz];
                  a[sz] = 0;
            }
            cout << sum*1.0/sz << '\n';
      }
}