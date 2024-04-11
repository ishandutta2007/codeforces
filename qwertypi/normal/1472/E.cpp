#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> bit[400002];

int n;

void addPoint(int x, int y, int id){
	for(int i = x; i <= n * 2; i += i & -i){
		bit[i].push_back({y, id});
	}
}

int search(int x, int y){
	for(int i = x; i; i -= i & -i){
		if(bit[i].empty() || bit[i][0].first > y) continue;
		return bit[i][0].second;
	}
	return -1;
}

void solve(){
	cin >> n;
	vector<int> v;
	vector<pair<int, int>> points;
	for(int i = 0; i <= n * 2; i++) bit[i].clear();
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
		v.push_back(x);
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	map<int, int> M;
	for(int i = 0; i < v.size(); i++) M[v[i]] = i + 1;
	
	for(auto& pi : points){
		pi.first = M[pi.first];
		pi.second = M[pi.second];
	}
	
	for(int i = 0; i < n; i++){
		addPoint(points[i].first, points[i].second, i + 1);
		addPoint(points[i].second, points[i].first, i + 1);
	}
	
	for(int i = 1; i <= n * 2; i++){
		sort(bit[i].begin(), bit[i].end());
		bit[i].resize(unique(bit[i].begin(), bit[i].end()) - bit[i].begin());
	}
	for(int i = 0; i < n; i++){
		cout << search(points[i].first - 1, points[i].second - 1) << ' ';
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