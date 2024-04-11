#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18 + 100;

void Main() {
  int N;
  cin >> N;
  vector<string> S(3);
  for (int i = 0; i < 3; i++) {
    cin >> S[i];
  }
  vector<int> A(3), B(3);
  for (int i = 0; i < 3; i++) {
    A[i] = count(begin(S[i]), end(S[i]), '0');
    B[i] = count(begin(S[i]), end(S[i]), '1');
  }

  bool good = false;
  string ans;
  for (int i = 0; i < 3; i++) if (!good) {
    for (int j = i + 1; j < 3; j++) if (!good) {
      if (max(min(A[i], A[j]), min(B[i], B[j])) >= N) {
        good = true;
        if (min(A[i], A[j]) >= N) {
          int cnt = min(A[i], A[j]);
          while (cnt > 0) {
            while (S[i].back() == '1') S[i].pop_back(), ans.push_back('1');
            while (S[j].back() == '1') S[j].pop_back(), ans.push_back('1');
            ans.push_back('0');
            S[i].pop_back();
            S[j].pop_back();
            cnt--;
          }
          while (!S[i].empty()) ans.push_back(S[i].back()), S[i].pop_back();
          while (!S[j].empty()) ans.push_back(S[j].back()), S[j].pop_back();
        } else {
          int cnt = min(B[i], B[j]);
          while (cnt > 0) {
            while (S[i].back() == '0') S[i].pop_back(), ans.push_back('0');
            while (S[j].back() == '0') S[j].pop_back(), ans.push_back('0');
            ans.push_back('1');
            S[i].pop_back();
            S[j].pop_back();
            cnt--;
          }
          while (!S[i].empty()) ans.push_back(S[i].back()), S[i].pop_back();
          while (!S[j].empty()) ans.push_back(S[j].back()), S[j].pop_back();
        }
        reverse(begin(ans), end(ans));
        break;
      }
    }
  }

  assert(good);
  assert(ans.size() <= 3 * N);
  cout << ans << '\n';

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}