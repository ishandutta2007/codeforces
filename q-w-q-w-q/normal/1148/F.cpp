#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll s, ans;
vector<pair<ll, int>> a[62];
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    ll y;
    scanf("%d%lld", &x, &y);
    s += x, a[__lg(y)].push_back(make_pair(y, x));
  }
  for (int i = 0; i < 62; i++) {
    ll tp = 0;
    for (auto x : a[i])
      if (__builtin_parityll(x.first & ans))
        tp += x.second;
      else
        tp -= x.second;
    if ((s < 0 && tp > 0) || (s > 0 && tp < 0)) ans |= 1ll << i;
  }
  cout << ans;
}