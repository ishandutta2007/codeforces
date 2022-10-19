#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T, n, u, v, a[110], b[110];
int s[] = {1, -1, 0, 0}, t[] = {0, 0, 1, -1};

bool check() {
	int flag = 0;
	for (int i = 1; i < n; i++) if(abs(a[i] - a[i + 1]) > 1) flag = 1;
	return flag;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> u >> v;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int flag = 0;
		for (int i = 1; i < n; i++) if(abs(a[i] - a[i + 1]) > 1) flag = 1;
		if(flag == 1) {
			cout << 0 << endl;
			continue;
		}
		int ans = 2e9 + 100;
		for (int i = 1; i < n; i++) if(a[i] != a[i + 1]) ans = min(ans, u); 
		for (int i = 1; i < n; i++) if(a[i] == a[i + 1]) ans = min(ans, u + v);
		for (int i = 1; i <= n; i++) {
			if(a[i] - 2 >= 0) {
				if(!(a[i] - 2 == 0 && i == 1)) {
					a[i] -= 2;
					if(check())
						ans = min(ans , 2 * v);
					a[i] += 2;
				}
			}
			if(a[i] - 1 >= 0) {
				if(!(a[i] - 1 == 0 && i == 1)) {
					a[i] -= 1;
					if(check())
						ans = min(ans, v);
					a[i] += 1;
				}
			}
			if(a[i] + 1 <= 1e6 + 1) {
				if(!(a[i] + 1 == 1e6 + 1 && i == n)) {
					a[i] +=1;
					if(check())
						ans = min(ans, v); 
					a[i] -= 1;
				}
			}
			if(a[i] + 2 <= 1e6 + 1) {
				if(!(a[i] + 2 == 1e6 + 1 && i == n)) {
					a[i] += 2;
					if(check())
						ans = min(ans, 2 * v);
					a[i] -= 2;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}