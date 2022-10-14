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
    string x;
    cin >> x;
    string a, b;
    a.push_back('1');
    b.push_back('1');
    bool big = false;
    for (int i = 1; i < x.size(); i++) {
      if (!big) {
        if (x[i] == '2') {
          a.push_back('1');
          b.push_back('1');
        }
        if (x[i] == '1') {
          a.push_back('1');
          b.push_back('0');
          big = true;
        }
        if (x[i] == '0') {
          a.push_back('0');
          b.push_back('0');
        }
      } else {
        a.push_back('0');
        b.push_back(x[i]);
      }
    }
    cout << a << '\n' << b << '\n';
  }

}