#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	ll ans=(ll)n*(n+1)/2;
	auto calc=[&](int i) {
		if (i<0||i>=n-1||a[i]==a[i+1])
			return 0ll;
		return (ll)(i+1)*(n-i-1);
	};
	for (int i=0; i<n-1; ++i)
		ans+=calc(i);
	while(m--) {
		int i, x;
		cin >> i >> x, --i;
		ans-=calc(i)+calc(i-1);
		a[i]=x;
		ans+=calc(i)+calc(i-1);
		cout << ans << "\n";
	}
	return 0;
}