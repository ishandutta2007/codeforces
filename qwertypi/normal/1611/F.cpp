#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
int ps[200001][20];
int s[200001][20];
void solve(){
	int n, S;
	cin >> n >> S;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		s[i][0] = A[i]; ps[i][0] = min(0LL, A[i]);
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n - (1 << j); i++){
			s[i][j] = s[i][j - 1] + s[i + (1 << j - 1)][j - 1];
			ps[i][j] = min(ps[i][j - 1], s[i][j - 1] + ps[i + (1 << j - 1)][j - 1]);
		}
	}
	int max_d = -1, L = -1, R = -1;
	for(int i = 0; i < n; i++){
		int bound = i, sum = S;
		for(int j = 19; j >= 0; j--){
			if(bound + (1 << j) > n) continue;
			if(sum + ps[bound][j] >= 0) sum += s[bound][j], bound += (1 << j); // order is wrong again...
		}
		if(bound - i > max_d){
			max_d = bound - i;
			L = i + 1;
			R = bound;
		}
	}
	if(L > R){
		cout << -1 << endl;
	}else{
		cout << L << ' ' << R << endl;
	}
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}