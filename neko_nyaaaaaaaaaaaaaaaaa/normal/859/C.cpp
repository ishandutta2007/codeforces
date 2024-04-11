#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n);
      for (auto &i: a) cin >> i;
      reverse(a.begin(), a.end());

      int al = 0, bo = 0;
      for (int i: a) {
            if (al >= bo) {
                  bo += i;
            } else {
                  al += i;
            }
      }
      cout << min(al, bo) << " " << max(al, bo);

	return 0;
}