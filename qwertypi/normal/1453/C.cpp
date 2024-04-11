#include <bits/stdc++.h>
#define inf (1 << 30)
#define int long long
using namespace std;

char c[2001][2001];

int r1[10], r2[10], c1[10], c2[10]; // actually the axis are wrong. Anyways.
int ans[10];

int d(int i, int j){
	return abs(j - i);
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < 10; i++){
		r1[i] = inf, r2[i] = -inf;
		c1[i] = inf, c2[i] = -inf;
	}
	fill(ans, ans + 10, 0);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> c[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			r1[c[i][j] - '0'] = min(r1[c[i][j] - '0'], i);
			r2[c[i][j] - '0'] = max(r2[c[i][j] - '0'], i);
			c1[c[i][j] - '0'] = min(c1[c[i][j] - '0'], j);
			c2[c[i][j] - '0'] = max(c2[c[i][j] - '0'], j);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int k = c[i][j] - '0';
			ans[k] = max(ans[k], d(r1[k], i) * d(0, j));
			ans[k] = max(ans[k], d(r1[k], i) * d(n - 1, j));
			ans[k] = max(ans[k], d(r2[k], i) * d(0, j));
			ans[k] = max(ans[k], d(r2[k], i) * d(n - 1, j));
			ans[k] = max(ans[k], d(c1[k], j) * d(0, i));
			ans[k] = max(ans[k], d(c1[k], j) * d(n - 1, i));
			ans[k] = max(ans[k], d(c2[k], j) * d(0, i));
			ans[k] = max(ans[k], d(c2[k], j) * d(n - 1, i));
		}
	}
	for(int i = 0; i < 10; i++) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}