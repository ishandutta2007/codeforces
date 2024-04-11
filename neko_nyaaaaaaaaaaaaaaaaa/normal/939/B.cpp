
 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	// cout << fixed << setprecision(12);
	
	ll n, k;
	cin >> n >> k;
	if (n == 0) {cout << "1 0"; return 0;}
	vector<ll> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	ll ans = -1, ans1, ans2;
	for (int i = 0; i < k; i++) {
		ll box = (n/a[i])*a[i];
		if (box > ans) {
			ans = box;
			ans1 = i+1;
			ans2 = n/a[i];
		}
	}
	cout << ans1 << " " << ans2;
	
	return 0;
}