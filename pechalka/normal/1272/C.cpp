#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> A(n);
  bool good[26];
  for (int i = 0; i < 26; ++i)
    good[i] = false;
  for (int i = 0; i < k; ++i){
    char c;
    cin >> c;
    good[c - 'a'] = true;
  }
  for (int i = 0; i < n; ++i)
    A[i] = good[s[i] - 'a'];
  vector<int> firstZero(n);
  for (int i = n - 1; i >= 0; --i){
    if (A[i] == 0)
      firstZero[i] = i;
    else
      firstZero[i] = (i + 1) < n ? firstZero[i + 1] : n;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans += firstZero[i] - i;
  cout << ans << '\n';
  return 0;
}