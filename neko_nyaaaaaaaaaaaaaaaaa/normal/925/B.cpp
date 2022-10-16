#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool flag = 0;

void solve(ll n, ll x1, ll x2, vector<pair<ll, int>> a, bool revorder) {
	int pt = 0;
	vector<int> ans1, ans2;
	
	// x1 first
	
	while (pt < n) {
		ans1.push_back(a[pt].second);
		
		if (a[pt].first*ans1.size() >= x1) {
			break;
		} else {pt++;}
	}
	
	pt++;
	if (pt >= n) {return;}
	
	bool flagg = 0;
	
	while (pt < n) {
		ans2.push_back(a[pt].second);
		
		if (a[pt].first*ans2.size() >= x2) {
			flagg = 1;
			break;
		} else {pt++;}
	}
	
	if (flagg == 0) return;
	
	cout << "Yes\n"; flag = 1;
	
	if (revorder) {
		cout << ans2.size() << " " << ans1.size() << "\n";
		for (int i = 0; i < ans2.size(); i++) {
			cout << ans2[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < ans1.size(); i++) {
			cout << ans1[i] << " ";
		}
	} else {
		cout << ans1.size() << " " << ans2.size() << "\n";
		for (int i = 0; i < ans1.size(); i++) {
			cout << ans1[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < ans2.size(); i++) {
			cout << ans2[i] << " ";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	ll n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<pair<ll, int>> a(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		sum += a[i].first;
		a[i].second = i+1;
	}
	
	sort(a.begin(), a.end(), greater<pair<ll, int>>());
	
	// solve begins
	
	solve(n, x1, x2, a, 0);
	if (flag) return 0;
	
	solve(n, x2, x1, a, 1);

	if (!flag) cout << "No";
	
	return 0;
}