#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n;
      cin >> n;
      vector<int> x1(n), y1(n), x2(n), y2(n);
      for (int i = 0; i < n; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
      }

      int xans, yans;
      multiset<int> a1, b1, a2, b2;
      for (int i = 0; i < n; i++) {
            a1.insert(x1[i]);
            b1.insert(y1[i]);
            a2.insert(x2[i]);
            b2.insert(y2[i]);
      }

      for (int i = 0; i < n; i++) {
            a1.erase(a1.find(x1[i]));
            b1.erase(b1.find(y1[i]));
            a2.erase(a2.find(x2[i]));
            b2.erase(b2.find(y2[i]));

            if (*a1.rbegin() <= *a2.begin() && *b1.rbegin() <= *b2.begin()) {
                  cout << *a1.rbegin() << " " << *b1.rbegin();
                  return 0;
            }

            a1.insert(x1[i]);
            b1.insert(y1[i]);
            a2.insert(x2[i]);
            b2.insert(y2[i]);
      }

      return 0;
}