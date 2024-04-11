#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, y;

void out() {
      for (int i = 0; i < x.size(); i++) {
            cout << x[i] << ' ' << y[i] << '\n';
      }
      exit(0);
}

void add(int a, int b) {
      if (x.size() == n) out();
      x.push_back(a);
      y.push_back(b);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      if (n <= 10) {
            for (int i = 1; i <= 10; i++) add(i, i);
      } else if (n <= 30) {
            for (int i = 1; 1; i++) {
                  add(i, 1);
                  add(i, 5);
            }
      }
      int sd = n/4;

      for (int i = 1; 1; i++) {
            if (i == 1) {
                  for (int j = 1; j <= sd; j++) {
                        add(i, j);
                  }
            } else if (i == 4) {
                  for (int j = 1; j <= sd; j += 2) {
                        add(i, j);
                  }
            } else {
                  add(i, 1);
                  add(i, sd);
            }
      }

      return 0;
}