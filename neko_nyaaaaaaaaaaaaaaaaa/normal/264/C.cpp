#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<ll> v(100001);
vector<ll> c(100001);

void input() {
      cin >> n >> q;
      for (int i = 0; i < n; i++) cin >> v[i];
      for (int i = 0; i < n; i++) cin >> c[i];
}

void solve(ll a, ll b) {
      ll inf = 1e15;
      vector<ll> dp(n+1, -inf);
      ll m1 = 0, m2 = 0;
      for (int i = 0; i < n; i++) {
            ll m = v[i]*b;
            if (m1 != c[i]) {
                  m = max(m, dp[m1] + v[i]*b);
            }
            if (m2 != c[i]) {
                  m = max(m, dp[m2] + v[i]*b);
            }
            m = max(m, dp[c[i]] + v[i] * a);

            dp[c[i]] = max(dp[c[i]], m);

            if (i == 0) {
                  m1 = c[i];
            } else if (m1 == m2 && c[i] != m1) {
                  if (m > dp[m1]) {
                        m1 = c[i];
                  } else {
                        m2 = c[i];
                  }
            } else {
                  if (m > dp[m1]) {
                        if (m1 != c[i]) m2 = m1;
                        m1 = c[i];
                  } else if (m > dp[m2] && m1 != c[i]) {
                        m2 = c[i];
                  }
            }
      }
      cout << max(0LL, *max_element(dp.begin(), dp.end())) << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	input();
	while (q--) {
            ll a, b; cin >> a >> b;
            solve(a, b);
	}

	return 0;
}