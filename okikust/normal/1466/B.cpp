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
	int t, n, k;
	int x, y, z;
	int s, ans;
	vector<int>a;
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		rep(i, n) {
			cin >> x;
			a.pb(x);
		}
		a.pb(3 * N);
		ans = 0;
		x = 0;
		rep2(i, 1, n) {
			if (a[i] > (a[i - 1] + 1)) {
				ans += min(a[i - 1] - a[x] + 2, i - x);
				x = i;
			}
		}
		cout << ans << endl;
	}


	return 0;
}