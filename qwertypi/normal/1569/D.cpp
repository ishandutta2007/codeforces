#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001], B[200001];
vector<int> ca[200002], cb[200002];
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++){
		ca[i].clear();
	};
	for(int i = 0; i <= m; i++){
		cb[i].clear();
	}
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	A[n] = (1 << 30);
	for(int i = 0; i < m; i++){
		cin >> B[i];
	}
	B[m] = (1 << 30);
	sort(A, A + n);
	sort(B, B + m);
	for(int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		int x = lower_bound(A, A + n, r) - A;
		int y = lower_bound(B, B + m, c) - B;
		if(A[x] == r && B[y] == c) continue;
		if(A[x] == r){
			cb[y].push_back(x);
		}else{
			ca[x].push_back(y);
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		map<int, int> M;
		int cnt = 0;
		if(ca[i].size()){
			for(auto j : ca[i]){
				M[j]++; cnt++;
			}
		}
		ans += cnt * (cnt - 1) / 2;
		for(auto j : M){
			ans -= j.second * (j.second - 1) / 2;
		}
	}
	for(int i = 0; i <= m; i++){
		map<int, int> M;
		int cnt = 0;
		if(cb[i].size()){
			for(auto j : cb[i]){
				M[j]++; cnt++;
			}
		}
		ans += cnt * (cnt - 1) / 2;
		for(auto j : M){
			ans -= j.second * (j.second - 1) / 2;
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}