#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<vector<int>> adj;
void solve() {
	cin >> n;
	vector<int> fact;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i > 0) {
			continue;
		}
		fact.push_back(i);
		if (i * i != n) {
			fact.push_back(n / i);
		}
	}
	fact.push_back(n);
	sort(fact.begin(), fact.end());

	if (fact.size() == 3 && __gcd(fact[0], fact[1]) == 1) {
		for (int i = 0; i < 3; ++i) {
			cout << fact[i] << (i == 2 ? "\n" : " ");
		}
		cout << "1\n";
		return;
	}

	
	vector<int> ans;
	set<int> s(fact.begin(), fact.end());
	int last = n;
	for (int i = 0; i < fact.size(); ++i) {
		assert(!s.empty());
		for (auto it = s.begin(); it != s.end(); ++it) {
			if (__gcd(last, *it) > 1) {
				ans.push_back(*it);
				last = *it;
				s.erase(it);
				break;
			}
		}
	}
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n0\n";
	/*adj = vector<vector<int>>(fact.size());
	for (int i = 0; i < fact.size(); ++i) {
		for (int j = i + 1; j < fact.size(); ++j) {
			if (__gcd(fact[i], fact[j]) > 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < fact.size(); ++i) {
		cout << adj[i].size() << " ";
	}
	cout << "\n";*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}