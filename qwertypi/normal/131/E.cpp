#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> M[4];
vector<pair<int, int>> P;
int cnt[9];

int check(int id, int x, int y){
	if(M[id][x].size() == 1) return 0;
	if(M[id][x].front() == y || M[id][x].back() == y) return 1;
	return 2;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		P.push_back({x, y});
		M[0][x].push_back(y);
		M[1][y].push_back(x);
		M[2][x + y].push_back(x - y);
		M[3][x - y].push_back(x + y);
	}
	for(int i = 0; i < 4; i++) for(auto& j : M[i]) sort(j.second.begin(), j.second.end());
	for(int i = 0; i < m; i++){
		int x = P[i].first, y = P[i].second;
		int res = 0;
		res += check(0, x, y);
		res += check(1, y, x);
		res += check(2, x + y, x - y);
		res += check(3, x - y, x + y);
		cnt[res]++;
	}
	for(int i = 0; i <= 8; i++){
		cout << cnt[i] << ' ';
	}
	cout << endl;
}