#include <bits/stdc++.h>
#define int long long
using namespace std;

int s[200001];

int r;	
bool test(int x){
	int T = 0;
	for(int i = 0; i < x; i++){
		T = max(T, x - i + s[i]);
	}
	return T <= r;
}

void solve(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for(int i = 0; i < m; i++) cin >> s[i];
	sort(s, s + m);
	if(a < b){
		m = min(m, b - a - 1);
		r = b - 1;
	}else{
		m = min(m, a - b - 1);
		r = n - b;
	}
	// cout << r << endl;
	
	int L = 0, R = m;
	while(L != R){
		int mid = (L + R + 1) / 2;
		if(test(mid)){
			L = mid;
		}else{
			R = mid - 1;
		}
	}
	cout << L << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}