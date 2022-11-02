#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<pair<int, int>> A;
void sub(){
	A.clear();
	int n, W, oW;
	cin >> n >> W;
	oW = W;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		A.push_back({v, i + 1});
	}
	
	sort(A.begin(), A.end());
	vector<int> ans;
	for(int i = n - 1; i >= 0; i--){
		if(W >= A[i].first){
			W -= A[i].first;
			ans.push_back(A[i].second);
		}
	}
	
	if(W <= oW / 2){
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i << ' ';
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}