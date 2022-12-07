#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
long long a[N], b[N], ans;


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  map < int, int > w;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i], ++w[b[i]];

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  if(a[n] > b[1]) {
    cout << -1;
    return 0;
  }

  if(m == 1) {
    if(a[n] != b[1]) {
      cout << -1;
      return 0;
    }

    for(int i = 1; i <= n; ++i) ans += a[i];
    cout << ans;
    return 0;
  }

  for(int i = 1; i <= n; ++i) {
    ans += a[i] * m;
  }

  int cnt = 0;
  for(int i = 1; i <= m; ++i) {
    if(b[i] != a[n]) {
      ++cnt;
      ans += b[i] - a[n];
    }
  }

  if(cnt == m) {
    ans += a[n] - a[n - 1];
  } 

  cout << ans;

  return 0;
}