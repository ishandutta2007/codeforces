#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[100001], B[100001];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> A[i];
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) cin >> B[i];
	vector<pair<int, int>> va, vb, vpa, vpb;
	for(int i = 0; i < n; i++){
		int vm = 1, p = A[i];
		while(p % m == 0) vm *= m, p /= m;
		va.push_back({p, vm});
	}
	for(int i = 0; i < k; i++){
		int vm = 1, p = B[i];
		while(p % m == 0) vm *= m, p /= m;
		vb.push_back({p, vm});
	}
	for(auto i : va){
		if(vpa.size() == 0 || vpa.back().first != i.first) vpa.push_back(i);
		else vpa.back().second += i.second;
	}
	for(auto i : vb){
		if(vpb.size() == 0 || vpb.back().first != i.first) vpb.push_back(i);
		else vpb.back().second += i.second;
	}
	cout << (vpa == vpb ? "Yes" : "No") << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}