#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  vector<int> odd, even;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] & 1) odd.push_back(a[i]);
    else even.push_back(a[i]);
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      if (odd.size() == 0) {
        even.pop_back();
      } else if (even.size() == 0) {
        sum -= odd.back();
        odd.pop_back();
      } else {
        if (odd.back() > even.back()) {
          sum -= odd.back();
          odd.pop_back();
        } else {
          even.pop_back();
        }
      }
    } else {
      if (odd.size() == 0) {
        sum += even.back();
        even.pop_back();
      } else if (even.size() == 0) {
        odd.pop_back();
      } else {
        if (even.back() >= odd.back()) {
          sum += even.back();
          even.pop_back();
        } else {
          odd.pop_back();
        }
      }
    }
  }

  if (sum > 0) printf("Alice\n");
  else if (sum < 0) printf("Bob\n");
  else printf("Tie\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}