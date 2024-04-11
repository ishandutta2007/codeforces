#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	ll cur = 0;
	ll acur = 0;
	vector<ll> ans(n+1);
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		acur = cur/m;
		
		ans[i] = acur;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i]-ans[i-1] << " ";
	}
	
	return 0;
}