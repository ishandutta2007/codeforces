#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;

const long long INF = 1e18;

long long tree[2 * MAXN + 228];
long long mod[2 * MAXN + 228];

void push(int v, int left, int right){
  tree[v] += mod[v];
  if (left + 1 == right){
    mod[v] = 0;
    return;
  }
  mod[2 * v + 1] += mod[v];
  mod[2 * v + 2] += mod[v];
  mod[v] = 0;
}

void add(int v, int left, int right, int x, int y, long long d){
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y){
    mod[v] += d;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * v + 1, left, mid, x, y, d);
  add(2 * v + 2, mid, right, x, y, d);
  push(2 * v + 1, left, mid);
  push(2 * v + 2, mid, right);
  tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

long long get(int v, int left, int right, int x, int y){
  push(v, left, right);
  if (y <= left || right <= x)
    return INF;
  if (x <= left && right <= y)
    return tree[v];
  int mid = (left + right) / 2;
  return min(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
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

  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i){
    add(0, 0, MAXN, p[i], n + 1, a[i]);
  }
  long long ans = INF;
  for (int i = 0; i + 1 < n; ++i){
    add(0, 0, MAXN, p[i], n + 1, -a[i]);
    add(0, 0, MAXN, 0, p[i], a[i]);
    ans = min(ans, get(0, 0, MAXN, 0, n + 1));
  }
  cout << ans << '\n';
  return 0;
}