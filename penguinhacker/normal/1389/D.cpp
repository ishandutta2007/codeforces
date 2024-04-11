#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, m;
pair<ll, ll> seg[2];

void test_case(int Test_Case_Number) {
	cin >> n >> m;
	for (int i=0; i<2; ++i) cin >> seg[i].first >> seg[i].second;
	sort(seg, seg+2);
	//case 1 [   [   ]   ]  seg contained completely inside
	if (seg[1].second<=seg[0].second) {
		m-=n*(seg[1].second-seg[1].first);
		if (m<=0) cout << "0\n";
		else {
			ll canTake=seg[0].second-seg[0].first-(seg[1].second-seg[1].first);
			if (n*canTake>=m) cout << m << '\n';
			else cout << n*canTake+(m-n*canTake)*2 << '\n';
		}
		return;
	}
	//case 2 [        []      ] //intersection, not contained
	if (seg[1].first<=seg[0].second) {
		m-=n*(seg[0].second-seg[1].first);
		if (m<=0) cout << "0\n";
		else {
			ll canTake=seg[1].second-seg[0].first-(seg[0].second-seg[1].first);
			if (n*canTake>=m) cout << m << '\n';
			else cout << n*canTake+(m-n*canTake)*2 << '\n';
		}
		return;
	}
	//case 3 [] [] //no intersection
	assert(seg[0].second<seg[1].first);
	ll ans=0;
	ll gap=seg[1].first-seg[0].second;
	ll width=seg[1].second-seg[0].first;
	for (int i=0; i<n; ++i) {
		if (m>=gap) {
			ans+=gap+min(width, m);
			m-=min(width, m);
			if (m==0) break;
		}
		else break;
	}
	if (ans==0) ans=gap+m;
	else if (m>0) ans+=2*m;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int _=0; _<t; ++_)
		test_case(_);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/