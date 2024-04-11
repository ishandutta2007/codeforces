#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 19;

bool tree[2 * MAXN];

void upd(int v, int left, int right, int i){
  if (i < left || right <= i)
    return;
  if (left + 1 == right){
    tree[v] = true;
    return;
  }
  int mid = (left + right) / 2;
  upd(2 * v + 1, left, mid, i);
  upd(2 * v + 2, mid, right, i);
  tree[v] = tree[2 * v + 1] || tree[2 * v + 2];
}

bool get(int v, int left, int right, int x, int y){
  if (y <= left || right <= x)
    return false;
  if (x <= left && right <= y)
    return tree[v];
  int mid = (left + right) / 2;
  return get(2 * v + 1, left, mid, x, y) || get(2 * v + 2, mid, right, x, y);
}

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, k, d;
  cin >> n >> k >> d;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  sort(A.begin(), A.end());
  int j = -1;
  upd(0, 0, n + 1, 0);
  for (int i = 0; i < n; ++i){
    while (A[j + 1] + d < A[i])
      ++j;
    int left = j + 1, right = i - k + 1;
    if (left <= right && get(0, 0, n + 1, left, right + 1))
      upd(0, 0, n + 1, i + 1);
  }
  if (get(0, 0, n + 1, n, n + 1))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}