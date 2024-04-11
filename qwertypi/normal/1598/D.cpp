#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> v;

int C(int n, int r){
	if(n < r) return 0;
	int ret = 1;
	for(int i = n; i >= n - r + 1; i--){
		ret *= i;
	}
	for(int i = 1; i <= r; i++){
		ret /= i;
	}
	return ret;
}
int cnt[200001];
void solve(){
	int n;
	cin >> n;
	fill(cnt, cnt + n + 1, 0);
	v.clear();
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
		cnt[b]++;
	}
	sort(v.begin(), v.end());
	map<int, vector<int>> M;
	for(auto i : v){
		M[i.first].push_back(i.second);
	}
	vector<int> a;
	for(auto i : M){
		a.push_back(i.second.size());
	}
	int s1 = 0, s2 = 0, s3 = 0;
	int ans = C(n, 3);
	for(auto i : M){
		int v = i.second.size();
		for(auto j : i.second){
			ans -= (v - 1) * (cnt[j] - 1);
		}
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