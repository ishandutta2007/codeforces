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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}
		vector<int> val;
		vector<int> pos;
		for (int i = 0; i < n; ++i) {
			bool lock;
			cin >> lock;
			if (!lock) {
				val.push_back(a[i]);
				pos.push_back(i);
			}
		}
		sort(val.rbegin(), val.rend());
		for (int i = 0; i < val.size(); ++i) {
			a[pos[i]] = val[i];
		}
		for (int i : a) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}