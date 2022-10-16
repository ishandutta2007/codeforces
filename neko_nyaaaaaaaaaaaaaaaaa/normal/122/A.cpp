#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> a = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
      for (int i = 0; i < a.size(); i++) {
            if (n % a[i] == 0) {cout << "YES"; return 0;}
      }
      cout << "NO";
}