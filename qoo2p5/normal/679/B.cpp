#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll f(ll x) {
  ll left = 0;
  ll right = 1e5 + 1;
  
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (mid * mid * mid <= x) left = mid;
    else right = mid;
  }
  
  return left;
}

pair<int, ll> solve(ll rest) {
  if (rest == 0) return {0, 0LL};
  
  ll a = f(rest);
  
  pair<int, ll> u = solve(rest - a * a * a);
  u.first += 1;
  u.second += a * a * a;
  
  if (a == 1) return u;
  
  pair<int, ll> v = solve(a * a * a - 1 - (a - 1) * (a - 1) * (a - 1));
  v.first += 1;
  v.second += (a - 1) * (a - 1) * (a - 1);
  
  return max(u, v);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  ll m;
  cin >> m;
  auto ans = solve(m);
  
  cout << ans.first << " " << ans.second << "\n";

	return 0;
}