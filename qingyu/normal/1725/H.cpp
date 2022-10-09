#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, a[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> cnt(3);
	for(int i = 1; i <= n; i ++) cin >> a[i], a[i] %= 3, cnt[a[i]] ++;
	vector<int> id = {0, 1, 2};
	do {
		vector<int> use = cnt;
		int cur = 0, s = 0, t = 0;
		for(int _i = 0; _i < 3; _i ++) {
			int i = id[_i];
			int c = min(use[i], n / 2 - cur);
			cur += c, use[i] -= c;
			if(c) s |= 1 << i;
			if(use[i]) t |= 1 << i;
			// cout << i << ' ' << use[i] << ' ' << 
		}
		vector<int> ok(3, 1);
		for(int i = 0; i < 3; i ++) if(s >> i & 1) {
			for(int j = 0; j < 3; j ++) if(t >> j & 1) {
				ok[((i + j) * (i + j) + i * j) % 3] = 0;
			}
		}
		int p = find(ok.begin(), ok.end(), 1) - ok.begin();
		if(p == 3) continue;
		cout << p << '\n';
		// cout << ok[0] <<  ' ' << ok[1] << ' ' << ok[2] << ' ' << s << ' ' << t << '\n';
		for(int i = 1; i <= n; i ++) {
			if(use[a[i]]) use[a[i]] --, cout << 1;
			else cout << 0;
		}
		cout << '\n';
		exit(0);
	}while(next_permutation(id.begin(), id.end()));
	cout << -1 << '\n';
	return 0;
}