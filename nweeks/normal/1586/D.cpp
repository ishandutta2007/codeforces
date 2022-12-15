#include <bits/stdc++.h>
#define int long long
using namespace std;

int makeQuery(vector<int> arr) {
  cout << "? ";
  for (int x : arr)
    cout << x << ' ';
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> p(n);

  int i = 2;
  while (1) {
    vector<int> query(n, 1);
    query[n - 1] = i;
    if (makeQuery(query) == 0) {
      p[n - 1] = n + 2 - i;
      break;
    }
    i++;
    if (i > n) {
      p[n - 1] = 1;
      break;
    }
  }

  // We have p[n-1]

  for (int delta = 1; delta + p[n - 1] <= n; ++delta) {
    vector<int> query(n, 1);
    query[n - 1] = delta + 1;
    int x = makeQuery(query);
    assert(x);
    p[x - 1] = p[n - 1] + delta;
  }

  for (int delta = -1; delta + p[n - 1] >= 1; --delta) {
    vector<int> query(n, n);
    query[n - 1] = n + delta;

    int x = makeQuery(query);
    assert(x);
    p[x - 1] = p[n - 1] + delta;
  }

  cout << "!";
  for (int x : p)
    cout << ' ' << x;
  cout << endl;
}