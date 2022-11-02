// 
// 

#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)

using namespace std;

const int mod = 1e9 + 7;

int A[300001];
int lg(int x){
	int cnt = 0;
	while(x){
		x /= 2, cnt++;
	}
	return cnt;
}
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	map<int, int> M;
	for(int i = 0; i < n; i++){
		M[A[i]]++;
	}
	int mx = 0;
	for(auto i : M){
		mx = max(mx, i.second);
	}
	int ans = n - mx + lg((n - 1) / mx);
	cout << ans << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}