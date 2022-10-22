#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, s;
		cin >> n >> s;
		vector<int> a(n);
		vector<ll> p(n+1);
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			p[i+1]=p[i]+a[i];
		}
		auto F=[&](int x)->int {
			return upper_bound(p.begin(), p.end(), x)-p.begin()+1;
		};
		ar<int, 2> best={F(s), -1};
		for (int i=0; i<n; ++i)
			if (p[i]<s)
				best=max(best, {F(s+a[i])-1, i});
		cout << best[1]+1 << "\n";
	}
	return 0;
}