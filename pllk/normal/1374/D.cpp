#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int a[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		multiset<int> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i]%k == 0) continue;
			s.insert(k-a[i]%k);
		}
		int c = 0;
		ll r = 0;
		while (s.size()) {
			auto it = s.lower_bound(c);
			if (it == s.end()) {
				r += k-c;
				c = 0;
			} else {
				int h = *it;
				r += h-c;
				r++;
				s.erase(it);
				c = h+1;
			}
		}
		cout << r << "\n";
	}
}