#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
using namespace std;

int A[300001], s[300001];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
	}
	vector<pair<int, int>> vp;
	for(int i = 0; i <= n; i++){
		if(!vp.empty() && s[i] <= vp.back().first) continue;
		vp.push_back({s[i], i});
	}
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		if(s[n] <= 0){
			int idx = lower_bound(vp.begin(), vp.end(), make_pair(x, -inf)) - vp.begin();
			cout << (idx == vp.size() ? -1 : vp[idx].second - 1) << ' ';
		}else{
			int r = (x - vp.back().first + s[n] - 1) / s[n];
			r = max(r, 0LL);
			int idx = lower_bound(vp.begin(), vp.end(), make_pair(x - r * s[n], -inf)) - vp.begin();
			cout << r * n + vp[idx].second - 1 << ' ';
		}
	}
	cout << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}