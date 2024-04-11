#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define inf (1LL << 60)
using namespace std;

int A[100001];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> A[i * m + j];
		}
	}
	vector<vector<pair<int, int>>> vvi(100001);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vvi[A[i * m + j]].push_back({i, j});
		}
	}
	int ans = 0;
	for(auto i : vvi){
		sort(i.begin(), i.end(), [](pair<int, int> a, pair<int, int> b){
			return a.first < b.first;
		});
		int _prev = 0, cnt = 0, d = 0;
		for(auto j : i){
			d += (j.fi - _prev) * cnt;
			ans += d;
			cnt++;
			_prev = j.fi;
		}
		// cout << "*" << ans << endl;
		sort(i.begin(), i.end(), [](pair<int, int> a, pair<int, int> b){
			return a.se < b.se;
		});
		_prev = 0, cnt = 0, d = 0;
		for(auto j : i){
			d += (j.se - _prev) * cnt;
			ans += d;
			cnt++;
			_prev = j.se;
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
}