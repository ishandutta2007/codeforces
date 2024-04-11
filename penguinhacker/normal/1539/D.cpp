#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	deque<ar<ll, 2>> a(n);
	for (ar<ll, 2>& b : a)
		cin >> b[1] >> b[0];
	sort(a.begin(), a.end());
	ll ans=0, cur=0;
	while(a.size()) {
		if (cur>=a[0][0]) {
			ans+=a[0][1], cur+=a[0][1];
			a.pop_front();
		} else if (a.back()[1]<=a[0][0]-cur) {
			ans+=a.back()[1]*2, cur+=a.back()[1];
			a.pop_back();
		} else {
			ll need=a[0][0]-cur;
			ans+=2*need, cur+=need, a.back()[1]-=need;
		}
	}
	cout << ans;
	return 0;
}