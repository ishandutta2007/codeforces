#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, l[N], r[N];
vector<int> add[2 * N], rem[2 * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

		vector<int> temp;
		for (int i = 0; i < n; i++) temp.push_back(l[i]), temp.push_back(r[i]);

		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

		for (int x = 0; x < temp.size(); x++) {
			add[x].clear();
			rem[x].clear();
		}

		for (int i = 0; i < n; i++) {
			l[i] = lower_bound(temp.begin(), temp.end(), l[i]) - temp.begin();
			r[i] = lower_bound(temp.begin(), temp.end(), r[i]) - temp.begin();
			add[l[i]].push_back(i);
			rem[r[i]].push_back(i);
		}

		vector<int> ans(n);

		int total_visited = 0, cur_visited = 0;

		for (int x = 0; x < temp.size(); x++) {
			for (int i : add[x]) {
				ans[i] = cur_visited - total_visited;
				total_visited += 1;
				cur_visited += 1;
			}

			for (int i : rem[x]) {
				ans[i] += total_visited;
				cur_visited -= 1;
			}
		}

		cout << n - (*max_element(ans.begin(), ans.end())) << '\n';
	}
	return 0;
}