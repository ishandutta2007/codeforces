#include <bits/stdc++.h>

// nothing to say
using namespace std;

int a[200001];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i * m + j];
		}
	}
	set<int> S; 
	for(int i = 0; i < n; i++){
		int mx = 0, mxi = -1; vector<int> s;
		for(int j = 0; j < m; j++){
			if(a[i * m + j] < mx) s.push_back(mxi), s.push_back(j);
			if(a[i * m + j] > mx) mxi = j, mx = max(mx, a[i * m + j]);
		}
		for(auto i : s) S.insert(i);
	}
	if(S.size() == 0){
		cout << 1 << ' ' << 1 << endl;
		return;
	}
	vector<int> b;
	for(auto i : S) b.push_back(i);
	for(int i = 0; i < n; i++){
		swap(a[i * m + b[0]], a[i * m + b[b.size() - 1]]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			if(a[i * m + j] > a[i * m + j + 1]){
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << b[0] + 1 << ' ' << b[b.size() - 1] + 1 << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}