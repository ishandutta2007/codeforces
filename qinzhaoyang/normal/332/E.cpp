#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string p, s;
int k;
string ans, tmp;

int main() {
	ios::sync_with_stdio(false);
	getline(cin, p), getline(cin, s), cin >> k;
	if (p.size() < s.size()) return cout << 0 << endl, 0;
	int a = p.size() / k, b = p.size() % k;
	for (int i = 1; i <= k; i++)
		ans += '?', tmp += ' ';
	for (int i = 1; i <= s.size(); i++) {
		int l = (int)s.size() - i * a, r = i - l;
		if (!(0 <= l && l <= b && 0 <= r && r <= k - b)) continue;
		for (int j = 0; j < k; j++) tmp[j] = '0';
		int now = i;
		for (int j = k - 1; j >= b; j--) {
			if (now == l) break;
			int flag = 1;
			for (int o = j, z = now - 1; o < p.size() && z < s.size(); o += k, z += i)
				if (p[o] != s[z]) {
					flag = 0;
					break;
				}
			if (flag == 1) {
				tmp[j] = '1';
				now--;
			}
		}
		if (now != l) continue;
		for (int j = b - 1; j >= 0; j--) {
			if (now == 0) break;
			int flag = 1;
			for (int o = j, z = now - 1; o < p.size() && z < s.size(); o += k, z += i)
				if (p[o] != s[z]) {
					flag = 0;
					break;
				}
			if (flag == 1) {
				tmp[j] = '1';
				now--;
			}
		}
		if (now != 0) continue;
		if (ans[0] == '?') ans = tmp;
		else if (tmp < ans) ans = tmp;
	}
	if (ans[0] == '?') cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}