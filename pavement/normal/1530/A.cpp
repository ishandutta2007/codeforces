#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int curr = 0, ans = 0;
		string S = to_string(N);
		for (int i = 0; i < S.size(); i++) {
			if (curr >= S[i] - '0') continue;
			ans += S[i] - '0' - curr;
			curr += S[i] - '0' - curr;
		}
		cout << ans << '\n';
	}
}