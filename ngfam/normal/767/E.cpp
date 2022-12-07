#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n, m;
int a[maxn], w[maxn];
int ansx[maxn], ansy[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    ansx[i] = a[i] / 100;
    ansy[i] = (a[i] %= 100);
  }

  for(int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  set<pair<long long, int>> heap;

  long long ans = 0;
  for(int i = 0; i < n; ++i) {
    if(a[i] == 0) continue;
    heap.emplace((100 - a[i]) * w[i], i);
    m -= a[i];
    if(m < 0) {
      m += 100;
      ans += heap.begin() -> first;
      ansy[heap.begin() -> second] = 0;
      ansx[heap.begin() -> second]++;
      heap.erase(heap.begin());
    }
  }

  cout << ans << endl;
  for(int i = 0; i < n; ++i) {
    cout << ansx[i] << " " << ansy[i] << endl;
  }

  return 0;
}