#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

vector<vector<int>> G(200001);
int a[200001];

int n;

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int m = 0, c = 0;
	for(int i = 1; i < n; i++){
		m += a[i] + a[0];
		c += a[i] * a[0];
	}
	if(m > 0){
		cout << "INF" << endl;
		return;
	}
	m = 0, c = 0;
	for(int i = 0; i < n - 1; i++){
		m += a[i] + a[n - 1];
		c += a[i] * a[n - 1];
	}
	if(m < 0){
		cout << "INF" << endl;
		return;
	}
	int ans = -inf;
	m = 0, c = 0;
	for(int i = 1; i < n; i++){
		m += a[i] + a[0];
		c += a[i] * a[0];
	}
	ans = max(ans, m * -a[0] + c);
	for(int i = 1; i < n - 1; i++){
		m -= a[i] + a[0];
		c -= a[i] * a[0];
		m += a[i] + a[n - 1];
		c += a[i] * a[n - 1];
		ans = max(ans, m * -a[i] + c);
		ans = max(ans, m * -a[i] + c);
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}