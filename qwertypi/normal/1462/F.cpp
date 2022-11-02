#include <bits/stdc++.h>

using namespace std;

int d[400001];
vector<int> bit[400001];
int n;
void add(int x, int y){
	// cout << "add " << x << ' ' << y << endl;
	for(int i = x; i <= n * 2; i += i & -i){
		bit[i].push_back(y);
	}
}

int query(int x, int y){
	// cout << "qry " << x << ' ' << y << endl;
	int res = 0;
	for(int i = x; i; i -= i & -i){
		int idx = upper_bound(bit[i].begin(), bit[i].end(), y) - bit[i].begin();
		res += idx;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> x;
		cin >> n;
		vector<pair<int, int>> seg;
		fill(d, d + n * 2 + 1, 0);
		for(int i = 0; i < n; i++){
			int l, r; cin >> l >> r;
			seg.push_back({l - 1, r});
			x.push_back(l - 1); x.push_back(r);
		}
		for(int i = 0; i <= n * 2; i++) bit[i].clear();
		sort(x.begin(), x.end());
		x.resize(unique(x.begin(), x.end()) - x.begin());
		map<int, int> M;
		for(int i = 0; i < x.size(); i++) M[x[i]] = i + 1;
		for(auto& i : seg){
			i.first = M[i.first], i.second = M[i.second];
		}
		for(auto i : seg){
			add(i.first, -i.second);
		}
		for(int i = 0; i <= n * 2; i++) sort(bit[i].begin(), bit[i].end());
		int ans = 0;
		for(auto i : seg){
			int v = query(i.second - 1, -i.first - 1);
			ans = max(ans, v);
		}
		cout << n - ans << endl;
	}
}