#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
int dp[N];
int t[N];
vector <int> a;

int get(int i) {
  int res = 0;
  for (int j = 5; j >= 0; j--) {
    res = res * 10 + ((i >> j) & 1);
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = (1 << 30);
  }
  for (int i = 1; i < 64; i++) {
    a.push_back(get(i));
  }
  dp[0] = 0;
  a.push_back(1000000);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a.size(); j++) {
      int next = i + a[j];
      if (next > n) {
        continue;
      }
      if (dp[next] > dp[i] + 1) {
        dp[next] = dp[i] + 1;
        t[next] = a[j];
      }
    }
  }
  cout << dp[n] << endl;
  int pos = n;
  while (pos) {
    cout << t[pos] << " ";
    pos -= t[pos];
  }
  return 0;
}