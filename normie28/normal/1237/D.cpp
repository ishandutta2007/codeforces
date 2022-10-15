#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(3 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i + 2 * n] = a[i];
  }
  vector<int> ans(3 * n);
  vector<int> st_max;
  vector<int> st_min;
  for (int i = 3 * n - 1; i >= 0; i--) {
    while (!st_max.empty() && a[st_max.back()] < a[i]) {
      st_max.pop_back();
    }
    while (!st_min.empty() && a[st_min.back()] > a[i]) {
      st_min.pop_back();
    }
    int low = 0, high = (int) st_min.size();
    while (low < high) {
      int mid = (low + high) >> 1;
      if (a[st_min[mid]] * 2 < a[i]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    int nxt = 3 * n;
    if (low > 0) {
      nxt = min(nxt, st_min[low - 1]);
    }
    if (!st_max.empty()) {
      nxt = min(nxt, st_max.back());
    }
    if (nxt < 3 * n && a[nxt] >= a[i]) {
      ans[i] = ans[nxt];
    } else {
      ans[i] = nxt;
    }
    st_min.push_back(i);
    st_max.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << (ans[i] == 3 * n ? -1 : ans[i] - i);
  }
  cout << '\n';
  return 0;
}