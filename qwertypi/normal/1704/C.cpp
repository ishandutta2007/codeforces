#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100001];

int f(int x){
	if(x >= 1) return x;
	else if(x == 0) return 1;
	return 0;
}
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	sort(a, a + m);
	vector<pair<int, int>> vip;
	for(int i = 0; i < m - 1; i++){
		vip.push_back({a[i + 1] - a[i] - 1, 2});
	}
	vip.push_back({a[0] + n - 1 - a[m - 1], 2});
	
	vector<int> v;
	for(auto i : vip){
		v.push_back(i.first);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int t = 0;
	for(int i = m - 1; i >= 0; i--){
		ans += f(v[i] - t * 2 - 1);
		t += 2;
	}
	cout << n - ans << '\n';
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}