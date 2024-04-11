#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t;
	int n;
	long long a[N];
	long long ans;
	vector<long long> b;
	int c[N];
	int x, y;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n + 1) {
			a[i] = 0;
			c[i] = -1;
		}
		ans = 0;
		rep(i, n) {
			cin >> a[i];
			ans += a[i];
		}
		rep(i, n - 1) {
			cin >> x >> y;
			c[x - 1]++;
			c[y - 1]++;
		}
		b.clear();
		rep(i, n) {
			rep(j, c[i])b.pb(a[i]);
		}
		sort(all(b), greater<long long>());
		cout << ans;
		rep(i, n - 2) {
			ans += b[i];
			cout << " " << ans;
		}
		cout << endl;
	}
	return 0;
}