#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100;

int n, q;
int a[N], b[N];
pair<int, int> c[N];
priority_queue <int> p;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= q; i++) cin >> c[i].first >> c[i].second;
  sort(a + 1, a + n + 1);
  sort(c + 1, c + q + 1);
  int cur = 1;
  for(int i = 1; i <= n; i++) {
    while(cur <= q && c[cur].first <= i) {
      p.push(-c[cur].second);
      cur++;
    }
    b[i] = p.size();
    while(!p.empty() && -p.top() <= i) p.pop();
  }
  sort(b + 1, b + n + 1);
  long long ans=  0;
  for(int i = n; i;i--)
    ans += 1ll * a[i] * b[i];
  cout << ans;
  return 0;
}