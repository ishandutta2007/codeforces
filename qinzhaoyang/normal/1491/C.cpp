#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n;
ll a[5010];
ll s[5010], tmp[5010];

int main() {
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i], s[i] = tmp[i] = 0;
		ll t = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			t += s[i] + tmp[i];
			if(a[i] - 1 - t > 0) ans += a[i] - 1 - t;
			if (a[i] != 1) { 
				s[i + 2] += 1;
				if(i + a[i] <= n) s[i + a[i] + 1] -= 1;
			}
			if(a[i] - 1 - t < 0)
				tmp[i + 1] += t - a[i] + 1;
			t -= tmp[i];
		}
		cout << ans << endl;
	}
	return 0;
}