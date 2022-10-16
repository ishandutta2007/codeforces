#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      vector<int> fr, ba;
      int n; ll m; cin >> n >> m;
      m--;
      for (int i = 1, j = n-2; i < n; i++, j--) {
            if (m & (1LL << j)) {
                  ba.push_back(i);
            } else {
                  fr.push_back(i);
            }
      }
      fr.push_back(n);
      reverse(ba.begin(), ba.end());

      for (int i: fr) cout << i << " ";
      for (int i: ba) cout << i << " ";

	return 0;
}