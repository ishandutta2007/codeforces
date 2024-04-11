#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int mod = 998244353;
int bp(int a, int b, int p){
	if(b == 0) return 1;
	return bp(a * a % p, b / 2, p) * (b % 2 ? a : 1) % p;
}
 
bool fill_r[200001], fill_c[200001];
int R = 0, C = 0;
int solve(){
	R = 0, C = 0;
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<pair<int, int>> pairs;
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		pairs.push_back({x, y});
	}
	fill(fill_r, fill_r + n + 1, false);
	fill(fill_c, fill_c + m + 1, false);
	int c = 0;
	for(int i = q - 1; i >= 0; i--){
		int x = pairs[i].first, y = pairs[i].second;
		if(R == n || C == m) break;
		bool change = false;
		if(!fill_r[x]) R++, fill_r[x] = true, change = true;
		if(!fill_c[y]) C++, fill_c[y] = true, change = true;
		if(change) c++;
	}
	cout << bp(k, c, mod) << endl;
	return 0;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}