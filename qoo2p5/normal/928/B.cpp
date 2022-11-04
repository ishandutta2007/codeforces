
#include <bits/stdc++.h>
using namespace std;

#define f(_i, _n) for (auto _i = 0; _i < _n; _i++)
#define F(_i, _k, _n) for (auto _i = _k; _i < _n; _i++)
#define re return
#define pb push_back
#define all(_v) _v.begin(), _v.end()
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }
#define fi first
#define se second

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

int dp[100500];
int a[100500];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int k;
  cin >> n >> k;
  f(i, n) {
    cin >> a[i];
    --a[i];
    // cerr << min(k, i) << '\n';
    if (a[i] == -1) {
      dp[i] = min(k, i) + 1;
    } else {
      dp[i] = dp[a[i]] + min(2 * k, i - a[i] - 1) + 1;
    }
    cout << dp[i] + min(k, n - i - 1) << ' ';
  }

}