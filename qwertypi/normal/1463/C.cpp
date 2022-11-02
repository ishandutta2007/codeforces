#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
using namespace std;

bool correct[100001];

vector<pair<int, int>> v;

int intersect(int x, int t1, int t2, int x1, int x2){
	if(x1 > x2) swap(x1, x2), swap(t1, t2);
	if(x < x1 && x1 <= x2 || x1 <= x2 && x2 < x) return -inf;
	return t1 + (t1 < t2 ? x - x1 : x1 - x);
}

void check(int t, int from, int to){
	// cout << "CHECK " << t << ' ' << from << ' ' << to << endl;
	int idx = lower_bound(v.begin(), v.end(), make_pair(t, -inf)) - v.begin();
	while(idx < (int) v.size() - 1 && v[idx].first <= t + abs(to - from)){
		int t_X = intersect(v[idx].second, t, t + abs(to - from), from, to);
		// cout << "t_X " << t_X << endl;
		correct[idx] |= v[idx].first <= t_X && t_X <= v[idx + 1].first;
		idx++;
	}
}

void solve(){
	int n;
	cin >> n;
	fill(correct, correct + n, false);
	v.clear();
	for(int i = 0; i < n; i++){
		int t, x; cin >> t >> x;
		v.push_back({t, x});
	}
	v.push_back({inf, -1});
	int T = 0, X = 0;
	for(auto i : v){
		if(i.first == inf) continue;
		int t = i.first, x = i.second;
		if(T <= t){
			check(t, X, x);
			T = t + abs(X - x);
			X = x;
		}
	}
	/*
	for(int i = 0; i < n; i++){
		cout << correct[i];
	}
	cout << endl;
	*/
	int ans = accumulate(correct, correct + n, 0LL);
	cout << ans << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}