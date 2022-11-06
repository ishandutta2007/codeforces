#include <bits/stdc++.h>
using namespace std;

int q, n, k, a, sr[200005], sg[200005], sb[200005];
string s;
char c[] = {'R', 'G', 'B'};

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> n >> k >> s;
		a = 1e9;
		for (int i = 1; i <= n; i++)
			sr[i] = (s[i - 1] != c[(i - 1) % 3]) + sr[i - 1];
		for (int i = 1; i <= n; i++)
			sg[i] = (s[i - 1] != c[((i - 1) % 3 + 1) % 3]) + sg[i - 1];
		for (int i = 1; i <= n; i++)
			sb[i] = (s[i - 1] != c[((i - 1) % 3 + 2) % 3]) + sb[i - 1];
		for (int i = 1; i <= n - k + 1; i++) {
			a = min(a, sr[i + k - 1] - sr[i - 1]);
			a = min(a, sg[i + k - 1] - sg[i - 1]);
			a = min(a, sb[i + k - 1] - sb[i - 1]);
		}
		cout << a << '\n';
	}
}