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

  const int K = 60;
  int n;
  long long T;
  cin >> n >> T;
  string s;
  cin >> s;
  T -= 1ll << (s[n - 1] - 'a');
  T += 1ll << (s[n - 2] - 'a');
  int cnt[K];
  fill(cnt, cnt + K, 0);
  for (int i = 0; i < n - 2; ++i)
    ++cnt[s[i] - 'a'];
  long long S = 0;
  for (int i = 0; i < K; ++i)
    S += cnt[i] * (1ll << i);
  if ((T + S) < 0 || (T + S) % 2 == 1){
    cout << "No\n";
    return 0;
  }
  T = (T + S) / 2;
  for (int i = 0; i + 1 < K; ++i){
    if (T & (1ll << i)){
      if (cnt[i] == 0){
        cout << "No\n";
        return 0;
      }
      --cnt[i];
    }
    cnt[i + 1] += cnt[i] / 2;
  }
  cout << "Yes\n";
  return 0;
}