#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<int, int> q;
int t[5];

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  int sum = 0;
  
  for (int i = 0; i < 5; i++) {
    cin >> t[i];
    q[t[i]]++;
    sum += t[i];
  }
  
  int best = 0;
  
  for (auto &it : q) {
    if (it.second >= 2) {
      best = max(best, min(it.second, 3) * it.first);
    }
  }
  
  cout << sum - best << endl;
  
  return 0;
}