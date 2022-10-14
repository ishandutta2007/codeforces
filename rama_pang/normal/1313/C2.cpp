#include <bits/stdc++.h>
using namespace std;
using lint = long  long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // optimal is of a form like a mountain
  lint ans = 0;

  vector<lint> val(n, 0);

  vector<pair<lint, int>> st;
  lint sum = 0;

  for (int i = 0; i < n; i++) {
    int cur = i;
    while (!st.empty() && st.back().first >= a[i]) {
      sum -= st.back().first * (cur - st.back().second);
      cur = st.back().second;
      st.pop_back();
    }
    sum += (i - cur + 1) * a[i];
    st.emplace_back(a[i], cur);
    val[i] += sum;
  }
  st.clear();
  sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int cur = i;
    while (!st.empty() && st.back().first >= a[i]) {
      sum -= st.back().first * (st.back().second - cur);
      cur = st.back().second;
      st.pop_back();
    }
    sum += (cur - i + 1) * a[i];
    st.emplace_back(a[i], cur);
    val[i] += sum;
  }
  
  lint mx = 0;
  ans = 0;
  for (int i = 0; i < n; i++) {
    if (mx < val[i] - a[i]) {
      mx = val[i] - a[i];
      ans = i;
    }
  }

  // for (int i = 0; i < n; i++) {
  //   cout << val[i] - a[i] << " \n"[i == n - 1];
  // }

  vector<lint> place(n);
  place[ans] = a[ans];
  for (int i = ans - 1; i >= 0; i--) {
    place[i] = min(a[i], place[i + 1]);
  }
  for (int i = ans + 1; i < n; i++) {
    place[i] = min(a[i], place[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    cout << place[i] << " \n"[i == n - 1];
  }
}