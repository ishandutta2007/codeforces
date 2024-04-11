#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, d, m;
deque<int> a, b;
vector<ll> p1={0}, p2={0};

void test_case() {
	cin >> n >> d >> m;
	a.clear();
	b.clear();
	for (int i=0; i<n; ++i) {
		int x; cin >> x;
		if (x<=m) a.push_back(x);
		else b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (b.empty()) {
		ll ans=0;
		for (int i: a) ans+=i;
		cout << ans << '\n';
		return;
	}
	for (int i: a) p1.push_back(p1.back()+i);
	for (int i: b) p2.push_back(p2.back()+i);
	ll ans=0;
	for (int i=1; i<=b.size(); ++i) {
		if (i+(i?(i-1)*d:0)>n) break;
		//if (i+(i?(i-1)*d:0)<b.size()) continue;
		ll cur=p2[b.size()]-p2[b.size()-i];
		int need=max(0, i+(i-1)*d-(int)b.size());
		cur+=p1[a.size()]-p1[need];
		ans=max(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/