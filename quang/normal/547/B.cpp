#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n;
int a[N];
pair <int , int> b[N];
int l[N], r[N];
int st[N], top;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = make_pair(a[i], i);
  }
  a[0] = a[n + 1] = 0;
  sort(b + 1, b + n + 1);
  st[0] = 0;
  top = 1;
  for (int i = 1; i <= n + 1; i++) {
    while (top && a[st[top - 1]] > a[i]) {
      r[st[top - 1]] = i - 1;
      top--;
    }
    st[top++] = i;
  }
  top = 1;
  st[0] = n + 1;
  for (int i = n; i >= 0; i--) {
    while (top && a[st[top - 1]] > a[i]) {
      l[st[top - 1]] = i + 1;
      top--;
    }
    st[top++] = i;
  }
  int cur = 1;
  for (int i = n; i > 0; i--) {
    if (cur > n) {
      break;
    }
    int pos = b[i].second;
    while (r[pos] - l[pos] + 1 >= cur && cur <= n) {
      cur++;
      cout << b[i].first << " ";
    }
  }
  return 0;
}