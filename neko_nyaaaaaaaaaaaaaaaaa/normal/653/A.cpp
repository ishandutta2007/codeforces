#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      set<int> s;
      for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
      }
      vector<int> a;
      for (int u: s) {
            a.push_back(u);
      }
      n = a.size();
      for (int i = 2; i < n; i++) {
            if (a[i-1] == a[i] - 1 && a[i-2] == a[i] - 2) {cout << "YES"; return 0;}
      }
      cout << "NO";

	return 0;
}