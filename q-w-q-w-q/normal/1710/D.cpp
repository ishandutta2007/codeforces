#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

const int N = 2005;
int n;
char a[N][N];
int pt[N];
int ans[N][2], k;

void solve(int l, int r) {
  if (l == r)
    return;
  if (pt[l] >= r)
    pt[l] = r - 1;
  for (int i = l; i <= r; i++) {
    if (pt[i] > r)
      pt[i] = r;
    while (a[i][pt[i]] == '0')
      pt[i]--;
  }
  vector<pair<int, int>> tp;
  for (int lt = l, i = l, mx = 0; i <= r; i++) {
    mx = max(mx, pt[i]);
    if (mx <= i && (i != r || lt != l)) {
      solve(lt, i);
      tp.push_back({lt, i});
      lt = i + 1;
    }
  }
  if (!tp.empty()) {
    int len = tp.size();
    vector<pair<int, int>> a;
    for (int i = 2; i < len - 1; i += 2)
      a.push_back(tp[i]);
    a.push_back(tp[0]), a.push_back(tp[len - 1]);
    for (int i = 1; i < len - 1; i += 2)
      a.push_back(tp[i]);
    for (int i = 1; i != len; i++) {
      k++;
      if (a[i - 1].first < a[i].first)
        ans[k][0] = a[i - 1].first, ans[k][1] = a[i].second;
      else
        ans[k][0] = a[i].first, ans[k][1] = a[i - 1].second;
    }
    return;
  }
  int mid = pt[l];
  solve(l, mid);
  int lt = k;
  for (int i = mid;; i--)
    if (a[i][r] == '1') {
      memcpy(a[mid], a[i], sizeof a[i]);
      pt[mid] = r;
      solve(mid, r);
      for (int j = k; j != lt; j--)
        if (ans[j][0] == mid)
          ans[j][0] = i;
      return;
    }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> (a[i] + i), pt[i] = n;
  solve(1, n);
  for (int i = 1; i <= k; i++)
    cout << ans[i][0] << ' ' << ans[i][1] << '\n';
  k = 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
}