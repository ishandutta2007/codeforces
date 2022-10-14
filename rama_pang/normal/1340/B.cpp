#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, K;
string A[2005];

string digit[10] = {
  "1110111",
  "0010010",
  "1011101",
  "1011011",
  "0111010",
  "1101011",
  "1101111",
  "1010010",
  "1111111",
  "1111011"
};

int differ(string a, string b) {
  int res = 0;
  for (int i = 0; i < 7; i++) {
    if (a[i] == '0' && b[i] == '1') res++;
    if (a[i] == '1' && b[i] == '0') return 1e8;
  }
  return res;
}

int memo[2005][2005];

int dp(int n, int k) {
  if (k < 0) return false;
  if (n == N) return k == 0;
  if (memo[n][k] != -1) return memo[n][k];

  int res = 0;
  for (int dig = 0; dig < 10; dig++) {
    res |= dp(n + 1, k - differ(A[n], digit[dig]));
  }
  return memo[n][k] = res;
}
string ans;
void trace(int n, int k) {
  if (dp(n, k) == 0) {
    ans = "-1";
    return;
  }
  for (int dig = 9; dig >= 0; dig--) {
    if (dp(n + 1, k - differ(A[n], digit[dig]))) {
      ans.push_back(dig + '0');
      return trace(n + 1, k - differ(A[n], digit[dig]));
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(memo, -1, sizeof(memo));
  
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  trace(0, K);
  cout << ans << "\n";

  return 0;
}