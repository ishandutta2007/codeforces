#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, ans;
pair<ll, ll> best;
vector<ll> v1, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v1.resize(n);
	for (int i=0; i<n; ++i)
		cin >> v1[i];
	cin >> m;
	v2.resize(m);
	for (int i=0; i<m; ++i)
		cin >> v2[i];
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	
	ans = 3*(n-m);
	best = {3*n, 3*m};
	while (!v1.empty()) {
		ll x = v1.back();
		while (!v2.empty()&&v2.back()<x)
			v2.pop_back();
		ll a = v1.size(), b = v2.size();
		if (2*(n-m)+a-b>ans) {
			ans = 2*(n-m)+a-b;
			best = {2*n+a, 2*m+b};
		}

		while (!v1.empty()&&v1.back()<=x)
			v1.pop_back();
		while (!v2.empty()&&v2.back()<=x)
			v2.pop_back();
		a = v1.size(), b = v2.size();
		if (2*(n-m)+a-b>ans) {
			ans = 2*(n-m)+a-b;
			best = {2*n+a, 2*m+b};
		}
	}
	if (2*(n-m)>ans)
		cout << n*2 << ':' << m*2;
	else
		cout << best.first << ':' << best.second;
	return 0;
}