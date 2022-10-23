#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while (T--) 
		[&]() {
			int n, q, mx = -1;
			int64_t sum = 0;
			cin >> n >> q;
			vector<int> a(n), k(q);
			vector<pair<int, int64_t>> we = { {-1, static_cast<int64_t>(0)} };
			for (int &x : a) {
				cin >> x;
				we.emplace_back(mx = max(x, mx), sum += x);
			}
			for (int &x : k) {
				cin >> x;
				cout << prev(lower_bound(we.begin(), we.end(), make_pair(x + 1, static_cast<int64_t>(0))))->second << ' ';	
			}
			cout << '\n';
		}();
}