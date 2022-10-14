#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    int k = 1;
    vector<int> col(n);
    col[0] = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) {
        col[i] = col[i - 1];
      } else {
        if (col[i - 1] == 1) {
          col[i] = 2;
          k = 2;
        } else {
          col[i] = 1;
        }
      }
    }
    if (a[n - 1] != a[0]) {
      if (col[n - 1] == col[0]) {
        int turn = 0;
        for (int i = 1; i < n; i++) {
          if (turn == 0 && col[i] == col[i - 1]) {
            turn = 1;
            if (col[i - 1] == 1) {
              col[i] = 2;
            } else {
              col[i] = 1;
            }
          } else if (turn == 1) {
            if (a[i] == a[i - 1]) {
              col[i] = col[i - 1];
            } else {
              if (col[i - 1] == 1) {
                col[i] = 2;
                k = 2;
              } else {
                col[i] = 1;
              }
            }
          }
        }
        if (turn == 0) {
          k = 3;
          col[n - 1] = 3;
        }
      }
    }
    cout << k << '\n';
    for (int i = 0; i < n; i++) {
      cout << col[i] << " \n"[i == n - 1];
    }
  }

}