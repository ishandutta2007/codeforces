#include <bits/stdc++.h>

using namespace std;

int M;
void solve(){
	int x, y;
	cin >> x >> y;
	long long ans = 0;
	for(int i = 1; i < M; i++){
		int mx = min(y, x / i - 1);
		ans += max(0, mx - (i + 1) + 1);
	}
	cout << ans << endl;
}

int main(){
	M = ceil(sqrt(1e9)) + 3;
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}