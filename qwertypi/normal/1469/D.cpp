#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;

int n;
void clear(int l, int r){
	r = min(r, n);
	for(int i = l; i < r; i++){
		ans.push_back({i, r});
	}
}

int k[6] = {2, 4, 16, 256, 65536, 200000};
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		ans.clear();
		cin >> n;
		int K = 0; while(k[K] < n) K++;
		for(int i = 0; i < K; i++){
			clear(k[i] + 1, k[i + 1]);
		}
		ans.emplace_back(n, k[K - 1]);
		ans.emplace_back(n, k[K - 1]);
		for(int i = K - 2; i >= 0; i--){
			ans.emplace_back(k[i + 1], k[i]);
			ans.emplace_back(k[i + 1], k[i]);
		}
		cout << ans.size() << endl;
		for(auto v : ans){
			cout << v.first << ' ' << v.second << endl; 
		}
		cout << endl;
	}
}