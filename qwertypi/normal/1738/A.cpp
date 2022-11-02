#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int a[300001], b[300001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<int> k[2];
	for(int i = 0; i < n; i++){
		k[a[i]].push_back(b[i]);
	}
	sort(k[0].begin(), k[0].end(), [](int a, int b){
		return a > b;
	});
	sort(k[1].begin(), k[1].end(), [](int a, int b){
		return a > b;
	});
	if(k[0].size() < k[1].size()) swap(k[0], k[1]);
	
	int rans = 0;
	{
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += b[i];
		}
		for(int i = 0; i < min((int) k[0].size() - 1, (int) k[1].size()); i++){
			ans += k[0][i];
		}
		for(int i = 0; i < k[1].size(); i++){
			ans += k[1][i];
		}
		rans = max(rans, ans);
	}
	if(k[0].size() == k[1].size()){
		swap(k[0], k[1]);
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += b[i];
		}
		for(int i = 0; i < min((int) k[0].size() - 1, (int) k[1].size()); i++){
			ans += k[0][i];
		}
		for(int i = 0; i < k[1].size(); i++){
			ans += k[1][i];
		}
		rans = max(rans, ans); 
	}
	cout << rans << endl;
}
 
int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}