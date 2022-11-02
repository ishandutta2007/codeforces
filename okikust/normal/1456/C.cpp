#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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
	int n, k;
	vector<ll>a;
	vector<ll>b;
	ll s;
	ll ans;
	int x;
	cin >> n >> k;
	rep(i, n) {
		cin >> s;
		a.pb(s);
	}
	sort(all(a), greater<ll>());
	s = 0;
	ans = 0;
	rep(i, n) {
		ans += s;
		s += a[i];
		if (s < 0) {
			b.pb(s);
			rep2(j, i + 1, n) {
				b.pb(a[j]);
			}
			break;
		}
	}
	sort(all(b));
	n = b.size();
	rep(i, n) {
		x = i / (k+1);
		ans += (b[i] * x);
	}
	cout << ans << endl;
	return 0;
}