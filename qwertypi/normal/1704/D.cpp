#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[1000001];
int s[1000001];
int n, m;
int id(int i, int j){
	return i * m + j;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
		cin >> c[i];
	}
	fill(s, s + n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			s[i] += j * c[i * m + j];
		}
	}
	map<int, vector<int>> M;
	for(int i = 0; i < n; i++){
		M[s[i]].push_back(i);
	}
	int k = -1;
	for(auto i : M){
		if(i.second.size() == 1){
			k = i.second.front();
		}
	}
	cout << k + 1 << ' ' << s[k] - s[(k == 0 ? 1 : 0)] << '\n';
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}