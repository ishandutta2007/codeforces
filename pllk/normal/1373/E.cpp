#include <iostream>

using namespace std;

typedef long long ll;

ll dd[155][10];
int vv[155][10];

int f(ll u) {
	int s = 0;
	while (u) {
		s += u%10;
		u /= 10;
	}
	return s;
}

void check(ll x) {
	if (x < 0) return;
	int a = f(x);
	if (a <= 150 && (!vv[a][0] || dd[a][0] > x)) {
		vv[a][0] = 1;
		dd[a][0] = x;
	}
	int b = f(x)+f(x+1);
	if (b <= 150 && (!vv[b][1] || dd[b][1] > x)) {
		vv[b][1] = 1;
		dd[b][1] = x;
	}
}

void dfs(ll x) {
	if (x > 1e18) return;
	check(x*10+7);
	check(x*10+8);
	check(x*10+9);
	check(x*100+89);
	dfs(x*10+9);
}

int main() {
	for (int u = 0; u <= 1000000; u++) {
		ll s = 0;
		for (int k = 0; k <= 9; k++) {
			s += f(u+k);
			if (s > 150) break;
			if (!vv[s][k]) {
				vv[s][k] = 1;
				dd[s][k] = u;
			}
		}
	}
	for (int i = 1; i <= 9; i++) dfs(i);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, k;
		cin >> n >> k;
		if (vv[n][k]) cout << dd[n][k];
		else cout << -1;
		cout << "\n";
	}
}