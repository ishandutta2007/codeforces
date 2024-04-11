#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first+a.second < b.first+b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	set<int> st;
	for (int i = 2; i <= sqrt(a[0].first); i++) {
		if (a[0].first % i == 0) {
			st.insert(i);
			while (a[0].first % i == 0) {
				a[0].first /= i;
			}
		}
	}
	st.insert(a[0].first);
	for (int i = 2; i <= sqrt(a[0].second); i++) {
		if (a[0].second % i == 0) {
			st.insert(i);
			while (a[0].second % i == 0) {
				a[0].second /= i;
			}
		}
	}
	st.insert(a[0].second);
	
	for (int u: st) {
		if (u == 1) continue;
		
		bool yes = 1;
		for (int i = 1; i < n; i++) {
			if (a[i].first % u == 0 || a[i].second % u == 0) continue;
			yes = 0; break;
		}
		if (yes) {cout << u; return 0;}
	}
	cout << -1;
	
	return 0;
}