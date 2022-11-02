#include <bits/stdc++.h>

using namespace std;

int da[100001], db[100001];
int A[100001], B[100001];
bool win[100001];
char ans[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	vector<pair<pair<int, int>, int>> va, vb;
	for(int i = 0; i < n; i++){
		va.push_back({{A[i], B[i]}, i});
	}
	for(int i = 0; i < n; i++){
		vb.push_back({{B[i], A[i]}, i});
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	int min_a = n - 1, min_b = n - 1;
	da[n] = db[n] = (1 << 30);
	for(int i = n - 1; i >= 0; i--){
		da[i] = min(da[i + 1], va[i].first.second); // min b
	}
	for(int i = n - 1; i >= 0; i--){
		db[i] = min(db[i + 1], vb[i].first.second); // ...
	}
	for(int t = 0; t < n; t++){
		int idx_a = lower_bound(vb.begin(), vb.end(), pair<pair<int, int>, int>{{da[min_a], -1}, -1}) - vb.begin();
		min_b = min(min_b, idx_a);
		int idx_b = lower_bound(va.begin(), va.end(), pair<pair<int, int>, int>{{db[min_b], -1}, -1}) - va.begin();
		min_a = min(min_a, idx_b);
		// cout << min_a << ' ' << min_b << endl;
	}
	// cout << min_a << ' ' << min_b << endl;
	for(int i = 0; i < n; i++){
		win[i] = false;
	}
	for(int i = min_a; i < n; i++){
		win[va[i].second] = true;
	}
	for(int i = min_b; i < n; i++){
		win[vb[i].second] = true;
	}
	for(int i = 0; i < n; i++){
		ans[i] = (win[i] ? '1' : '0');
		cout << ans[i];
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}