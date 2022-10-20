#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int a[N];
int state[N];
int pos[N];
int hp[N];
int n, m;

bool go(int from, int to, int health, bool update) {
	int step = 1;
	if (from > to) step = -1;
	to += step;
	while (from != to) {
		health += state[from];
		if (health < 0) return false;
		if (update) state[from] = 0;
		from += step;
	}
	return true;
}

vector<int> solve(int target) {
	vector<int> rem;
	vector<int> ans;
	for (int i = 1; i <= m; ++i) rem.push_back(i);
	for (int i = 1; i <= n; ++i) state[i] = a[i];
	while (!rem.empty()) {
		bool progressed = false;
		for (int i = (int) rem.size() - 1; i >= 0; --i) {
			if (go(pos[rem[i]], target, hp[rem[i]], false)) {
				go(pos[rem[i]], target, hp[rem[i]], true);
				ans.push_back(rem[i]);
				rem[i] = rem.back();
				rem.pop_back();
				progressed = true;
			}
		}
		if (!progressed) break;
	}
	if (!rem.empty()) return vector<int>();
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> pos[i] >> hp[i];
	}
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		vector<int> ans = solve(i);
		if (!ans.empty()) {
			cout << i << endl;
			for (int v : ans) cout << v << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}