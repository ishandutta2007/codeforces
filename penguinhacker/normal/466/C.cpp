#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[500000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll sum = 0;
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	if (sum%3 != 0) {
		cout << 0;
		return 0;
	}
	ll third = sum/3;
	
	int rCnt = 0;
	ll rSum = 0;
	for (int i=n-1; i>=2; --i) {
		rSum += a[i];
		if (rSum == third)
			rCnt++;
	}
	ll lSum = 0;
	ll ans = 0;
	
	for (int i=0; i<n-2; ++i) {
		lSum += a[i];
		if (lSum == third)
			ans += rCnt;
		if (rSum == third)
			rCnt--;
		rSum -= a[i+2];
	}

	cout << ans;
	return 0;
}