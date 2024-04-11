#include <bits/stdc++.h>

using namespace std;
int A[1001][1001];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
		}
	}
	vector<int> ans;
	for(int i = 0; i < n - 1; i++){
		vector<pair<int, int>> diff;
		vector<int> get;
		for(int j = 0; j < m; j++){
			diff.push_back({A[j][n-1] - A[j][i], j});
		}
		int _sum = 0;
		for(auto j : diff){
			_sum += j.first;
		}
		sort(diff.begin(), diff.end());
		int pos = m - 1;
		while(_sum > 0){
			pair<int, int> data = diff[pos--];
			_sum -= data.first;
			get.push_back(data.second);
		}
		if(i == 0 || get.size() < ans.size()){
			ans = get;
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i + 1 << ' ';
	}
}