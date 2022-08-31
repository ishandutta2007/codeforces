#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<long long> A00;
  vector<long long> A01;
  vector<long long> A10;
  vector<long long> A11;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s == "00") {
      A00.emplace_back(x);
    } else if (s == "01") {
      A01.emplace_back(x);
    } else if (s == "10") {
      A10.emplace_back(x);
    } else {
      A11.emplace_back(x);
    }
  }
  sort(A00.rbegin(), A00.rend());
  sort(A01.rbegin(), A01.rend());
  sort(A10.rbegin(), A10.rend());
  sort(A11.rbegin(), A11.rend());
  vector<long long> pref00(A00.size() + 1);
  for (int i = 0; i < A00.size(); ++i)
    pref00[i + 1] = pref00[i] + A00[i];
  vector<long long> pref01(A01.size() + 1);
  for (int i = 0; i < A01.size(); ++i)
    pref01[i + 1] = pref01[i] + A01[i];
  vector<long long> pref10(A10.size() + 1);
  for (int i = 0; i < A10.size(); ++i)
    pref10[i + 1] = pref10[i] + A10[i];
  vector<long long> pref11(A11.size() + 1);
  for (int i = 0; i < A11.size(); ++i)
    pref11[i + 1] = pref11[i] + A11[i];
  long long ans = 0;
  for (int i = 0; i <= A00.size() && i <= A11.size(); ++i) {
    int delta = A11.size() - i;
    long long cur = pref11.back() + pref00[i];
    if (A01.size() + delta >= A10.size())
      ans = max(ans, cur + pref10.back() + pref01[min((int)A01.size(), (int)A10.size() + delta)]);
    if (A10.size() + delta >= A01.size())
      ans = max(ans, cur + pref01.back() + pref10[min((int)A10.size(), (int)A01.size() + delta)]);
  }
  cout << ans << '\n';
  return 0;
}