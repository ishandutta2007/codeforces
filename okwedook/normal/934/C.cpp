#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int main() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i;
	vector<ll> pref(n), suff(n);
	ll curr1 = 0;
	for (int i = 0; i < n; ++i) {
		pref[i] = curr1;
		curr1 += (arr[i] == 1);
	} 
	ll curr2 = 0;
	for (int i = n - 1; i >= 0; --i) {
		suff[i] = curr2;
		curr2 += (arr[i] == 2);
	}
	ll ans = 0;
	for (ll r = 0; r < n; ++r) {
		ans = max(ans, pref[r] + suff[r] + 1);
		curr1 = 0, curr2 = 0;
		for (ll l = r; l >= 0; --l) {
			if (arr[l] == 2) curr2 = max(curr2, curr1) + 1;
			else ++curr1;
			ans = max(ans, curr2 + pref[l] + suff[r]);
		}
	}
	cout << ans;
	//system("pause");
    return 0;
}