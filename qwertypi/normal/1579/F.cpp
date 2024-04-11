#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[1000001];
int st[1000001][20];
int res[1000001];


int n, d;
	
int reg(int x){
	x %= n;
	if(x < 0) return x + n;
	return x;
}

void solve(){
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int c = accumulate(A, A + n, 0LL);
	if(c == 0){
		cout << 0 << endl;
		return;
	}
	for(int i = 0; i < n; i++){
		st[i][0] = A[i];
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i < n; i++){
			st[i][j] = st[i][j - 1] && st[reg(i - (d << j - 1))][j - 1];
		}
	}
	for(int i = 0; i < n; i++) res[i] = 1;
	int ans = 0;
	for(int j = 19; j >= 0; j--){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += res[i] && st[reg(i - d * ans)][j];
		}
		if(cnt > 0){
			for(int i = 0; i < n; i++){
				res[i] &= st[reg(i - d * ans)][j];
			}
			ans += (1 << j);
		}
	}
	cout << (ans == (1 << 20) - 1 ? -1 : ans) << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}