#include <bits/stdc++.h>

using namespace std;

bool S[300][300];
int res = 0;

map<int, int> to_seat;
void assign(int a, int s){
	to_seat[a] = s;
}

int n, m;
int A[100001];
void assign(int s){
	int si = s / m; int sj = s % m;
	for(int i = 0; i < sj; i++){
		if(S[si][i]) res++;
	}
	S[si][sj] = true;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n * m; i++){
			cin >> A[i];
		}
		res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				S[i][j] = false;
			}
		}
		map<int, vector<int>> M;
		for(int i = 0; i < n * m; i++){
			M[A[i]].push_back(i);
		}
		int cur_idx = 0;
		for(auto i : M){
			vector<pair<int, int>> sights;
			for(int j = 0; j < i.second.size(); j++){
				sights.push_back({m - 1 - (cur_idx + j) % m, cur_idx + j});
			}
			sort(sights.begin(), sights.end());
			int cur_i = 0;
			for(auto j : i.second){
				assign(j, sights[cur_i++].second);
			}
			cur_idx += i.second.size();
		}
		for(int i = 0; i < n * m; i++){
			assign(to_seat[i]);
		}
		cout << res << endl;
		
	}
}