#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	string chars;
	for (char c = 'a'; c <= 'z'; c++) {
		chars += c;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		chars += c;
	}

	vector<char> inv(256);
	for (int i = 0; i < (int) chars.size(); i++) {
		inv[chars[i]] = i;
	}

	constexpr int sigma = 52;

	while (t--) {
		int n;
		cin >> n;

		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (auto &c : s[i]) {
				c = inv[c];
			}
		}

		vector<vector<array<int, 2>>> pos(sigma, vector<array<int, 2>>(n, {-1, -1}));

		vector<vector<bool>> pos_masks(sigma, vector<bool>(1 << n, false));
		for (int c = 0; c < sigma; c++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < (int) s[i].length(); j++) {
					if (s[i][j] == c) {
						if (pos[c][i][0] == -1) {
							pos[c][i][0] = j;
						} else {
							pos[c][i][1] = j;
						}
					}
				}
			}

			int current_mask = 0;
			auto recurse = [&](int i, auto &&self) -> void {
				if (i == n) {
					pos_masks[c][current_mask] = true;
				} else {
					for (int f = 0; f < 2; f++) {
						if (pos[c][i][f] != -1) {
							current_mask += f * (1 << i);
							self(i + 1, self);
							current_mask -= f * (1 << i);
						}
					}
				}
			};
			recurse(0, recurse);
		}

		auto next_mask = [&](int u, int mask, int v) -> int {
			if (v == -1) {
				return -1;
			}
			int required_mask = 0;
			for (int i = 0; i < n; i++) {
				if (pos[v][i][0] > pos[u][i][mask >> i & 1]) {
					required_mask += 0 * (1 << i);
				} else if (pos[v][i][1] > pos[u][i][mask >> i & 1]) {
					required_mask += 1 * (1 << i);
				} else {
					return -1;
				}
			}
			return required_mask;
		};

		vector<vector<int>> dp(sigma, vector<int>(1 << n, -1));
		vector<vector<int>> parent(sigma, vector<int>(1 << n, -1));

		auto recurse = [&](int u, int mask, auto &&self) -> int {
			if (dp[u][mask] != -1) {
				return dp[u][mask];
			}
			dp[u][mask] = 1;
			for (int v = 0; v < 52; v++) {
				auto transition_mask = next_mask(u, mask, v);
				if (transition_mask == -1) {
					continue;
				}
				auto current_answer = 1 + self(v, transition_mask, self);
				if (current_answer > dp[u][mask]) {
					dp[u][mask] = current_answer;
					parent[u][mask] = v;
				}
			}
			return dp[u][mask];
		};

		int best_char = -1, best_answer = 0;
		for (int c = 0; c < 52; c++) {
			if (pos_masks[c][0]) {
				auto answer = recurse(c, 0, recurse);
				if (answer > best_answer) {
					best_answer = answer;
					best_char = c;
				}
			}
		}

		cout << best_answer << '\n';
		string lcs;
		for (int u = best_char, mask = 0; u != -1;) {
			lcs += chars[u];
			int v = parent[u][mask];
			int transition_mask = next_mask(u, mask, v);
			std::tie(u, mask) = std::make_pair(v, transition_mask);
		}
		cout << lcs << '\n';
	}
	return 0;
}