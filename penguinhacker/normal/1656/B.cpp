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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		bool ok=0;
		for (int i : a) {
			auto it=lower_bound(a.begin(), a.end(), i+k);
			if (it!=a.end()&&*it==i+k) {
				ok=1;
				break;
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}