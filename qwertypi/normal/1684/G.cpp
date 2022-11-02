#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		a.push_back(v);
	}
	sort(a.begin(), a.end());
	for(auto i : a){
		if(i >= (m + 1) / 2){
			cout << -1 << endl;
			return 0;
		}
	}
	vector<int> A, B;
	vector<pii> ans;
	for(int i = 0; i < n; i++){
		if(a[i] >= (m + 2) / 3) 
			A.push_back(a[i]);
		else
			B.push_back(a[i]);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for(auto i : A){
		int best = -1;
		for(auto j : B){
			if(i % j == 0 && i * 2 + j <= m) best = j;
		}
		if(best == -1){
			cout << -1 << endl; 
			return 0;
		}
		ans.push_back({i * 2 + best, i + best});
		B.erase(find(B.begin(), B.end(), best));
	}
	for(auto i : B){
		ans.push_back({i * 3, i * 2});
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.fi << ' ' << i.se << endl;
	}
}