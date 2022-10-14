#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;

  vector<int> facts;
  for (int i = 2; i <= a; i++) {
    if (a % i == 0) {
      while (a % i == 0) {
        a /= i;
        facts.emplace_back(i);
      }
    }
  }

  for (auto &i : facts) {
    cout << i;
  }
  cout << "\n";

}