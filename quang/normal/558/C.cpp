#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long MAX = 10000000000ll;

int n;
int a[N], maxval;
long long minval[N], sign[N], cnt;
int top;
pair<long long, int> q[N];

void build(int u) {
  top = 1;
  q[0] = make_pair(a[u], 0);
  minval[a[u]] -= MAX;
  cnt++;
  sign[a[u]] = cnt;
  for (int i = 0; i < top; i++) {
    int u = q[i].first;
    int cost = q[i].second;
    int val;
    val = u * 2;
    if (val <= maxval && sign[val] < cnt) {
      sign[val] = cnt;
      minval[val] -= MAX;
      minval[val] += cost + 1;
      q[top++] = make_pair(val, cost + 1);
    }
    val = u / 2;
    if (val && sign[val] < cnt) {
      sign[val] = cnt;
      minval[val] -= MAX;
      minval[val] += cost + 1;
      q[top++] = make_pair(val, cost + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxval = max(maxval, a[i]);
  }
  for (int i = 1; i <= 100000; i++) {
    minval[i] = MAX * n;
  }
  for (int i = 1; i <= n; i++) {
    build(i);
  }
  long long res = 1e16;
  for (int i = 1; i <= 100000; i++) {
    res = min(res, minval[i]);
  }
  cout << res << endl;
  return 0;
}