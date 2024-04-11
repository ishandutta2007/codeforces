#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cur = 1;
ll last = 0;
ll sp[30][500001];
ll sp_sum[30][500001];
ll w[500001];

void solve1() {
	ll r, x;
	cin >> r >> x;
	r ^= last;
	x ^= last;
	
	w[++cur] = x;
	if(w[r] >= w[cur]){
		sp[0][cur] = r;
	} else {
		int from = r;
		for (int i = 19; i >= 0; i--) {
			if (w[sp[i][from]] < w[cur]) {
				from = sp[i][from];
			}
		}
		sp[0][cur] = sp[0][from];
	}
	
	sp_sum[0][cur] = (sp[0][cur] == 0 ? 1e16 : w[sp[0][cur]]);
	
	for (int i = 1; i < 20; i++) {
		sp[i][cur] = sp[i-1][sp[i-1][cur]];
		
		sp_sum[i][cur] = (sp[i][cur] == 0 ? 1e16 : sp_sum[i-1][cur] + sp_sum[i-1][sp[i-1][cur]]);
	}
}

void solve2() {
	ll r, x;
	cin >> r >> x;
	r ^= last;
	x ^= last;
	
	if (w[r] > x) {
		cout << "0\n";
		last = 0;
	} else {
		x -= w[r];
		
		int ans = 1;
		for (int i = 19; i >= 0; i--) {
			if (sp_sum[i][r] <= x) {
				ans += (1 << i);
				x -= sp_sum[i][r];
				r = sp[i][r];
			}
		}
		
		cout << ans << '\n';
		last = ans;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int q, c;
	cin >> q;
	w[0] = 1e16;
	for(int i = 0; i < 20; i++) sp_sum[i][1] = 1e16;
	
	while(q--) {
		cin >> c;
		if (c == 1) {
			solve1();
		} else {
			solve2();
		}
	}
	
	return 0;
}