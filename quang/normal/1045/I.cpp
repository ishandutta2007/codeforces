#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
map<int, int> cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int mask = 0;
		for (char u : s) {
			int x = u - 'a';
			mask ^= (1 << x);
		}
		res += cnt[mask];
		for (int j = 0; j < 26; j++) {
			mask ^= (1 << j);
			res += cnt[mask];
			mask ^= (1 << j);
		}
		cnt[mask]++;
	}
	cout << res << endl;
	return 0;
}