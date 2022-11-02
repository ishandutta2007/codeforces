#include <bits/stdc++.h>

using namespace std;

int A[2001][2], B[2001][2];

int _max[2001 * 2001];
vector<pair<int, int>> vip;
void sub(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i][0] >> A[i][1];
	}
	for(int i = 0; i < m; i++){
		cin >> B[i][0] >> B[i][1];
	}
	
	for(int j = 0; j < m; j++){
		int min_x = (1 << 30), min_y = (1 << 30);
		for(int i = 0; i < n; i++){
			vip.push_back({max(-1, B[j][0] - A[i][0]) + 1, max(-1, B[j][1] - A[i][1]) + 1});
		}
	}
	
	sort(vip.begin(), vip.end());
	for(int i = n * m - 1; i >= 0; i--){
		_max[i] = max(_max[i + 1], vip[i].second);
	}
	int ans = _max[0];
	for(int i = 0; i < n * m; i++){
		int res = vip[i].first + _max[i + 1];
		ans = min(ans, res);
	}
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}