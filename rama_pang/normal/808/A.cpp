#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  vector<lint> lucky;
  for (int i = 1; i < 10; i++) {
    for (lint j = i; j <= (lint) 1e12; j *= 10) {
      lucky.emplace_back(j);
    }
  }
  sort(begin(lucky), end(lucky));
  lint n;
  cin >> n;
  cout << *upper_bound(begin(lucky), end(lucky), n) - n << "\n";
  return 0;
}