#include <bits/stdc++.h>
#define int long long
using namespace std;

int id(char c){
	if(c == 'R') return 0;
	if(c == 'G') return 1;
	return 2;
}

int A[300001];
int d[300001][3];
int s[300001][3];
void solve(){
	int n, k;
	cin >> n >> k;
	string S;
	cin >> S;
	for(int i = 0; i < n; i++){
		A[i] = id(S[i]);
	}
	for(int b = 0; b < 3; b++){
		for(int i = 0; i < n; i++){
			d[i][b] = A[i] != (b + i) % 3;
			s[i + 1][b] = s[i][b] + d[i][b];
		}
	}
	int ans = (1 << 30);
	for(int b = 0; b < 3; b++){
		for(int i = 0; i <= n - k; i++){
			ans = min(ans, s[i + k][b] - s[i][b]);
		}
	}
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}