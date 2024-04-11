#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, vector<int>> M;
int cnt[200001];
priority_queue<pair<int, int>> pq; // {time, vertex}
int n;

int nt(int v, int t){
	int r = t / n * n + v;
	while(r <= t) r += n;
	return r; 
}

void erase(int v, int t){
	for(auto i : M[v]){
		cnt[i]--;
		if(cnt[i] == 0){
			pq.push({-nt(i, t), i});
		}
	}
}

void solve(){
	cin >> n;
	M.clear();
	fill(cnt, cnt + n + 1, 0);
	for(int i = 0; i < n; i++){
		int k; cin >> k;
		for(int j = 0; j < k; j++){
			int v; cin >> v; v--;
			M[v].push_back(i);
			cnt[i]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(cnt[i] == 0){
			pq.push({-i, i});
		}
	}
	int T = 0, N = 0;
	while(pq.size()){
		N++;
		pair<int, int> pi = pq.top(); pq.pop();
		erase(pi.second, -pi.first);
		T = max(T, -pi.first);
	}
	if(N != n){
		cout << -1 << endl;
	}else{
		cout << T / n + 1 << endl;
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}