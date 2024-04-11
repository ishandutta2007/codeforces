#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
int ans = 0;
using namespace std;

int bp(int a, int b, int p){
	if(b == 0) return 1;
	return bp(a * a % p, b / 2, p) * (b % 2 ? a : 1) % p;
}

int mi(int a, int p){
	return bp(a, p - 2, p);
}

bool MR(int x){
	if(x == 1) return false;
	int v = x - 1, d = 0;
	while(v % 2 == 0) v /= 2, d++;
	for(auto i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59}){
		if(x == i) return true;
		bool suc = false;
		int pw = bp(i, v, x);
		if(pw == 1) suc = true;
		for(int j = 0; j < d; j++){
			if(pw == x - 1) suc = true;
			pw = bp(pw, 2, x);
		}
		if(!suc) return false;
	}
	return true;
}

int A[200002]; 

int n, d;
int min_L[200002];
int min_R[200002]; 
void solve(){
	cin >> n >> d;
	A[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	A[n + 1] = d + 1;
	int mx = 0;
	for(int i = 0; i < n; i++){
		mx = max(mx, (A[i + 1] - A[i] - 2) / 2);
	}
	mx = max(mx, A[n + 1] - A[n] - 2);
	min_L[0] = inf;
	for(int i = 1; i <= n; i++){
		min_L[i] = min(min_L[i - 1], A[i] - A[i - 1] - 1);
	}
	min_R[n + 1] = min_R[n] = inf;
	for(int i = n - 1; i >= 1; i--){
		min_R[i] = min(min_R[i + 1], A[i + 1] - A[i] - 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int dis = A[i + 1] - A[i - 1] - 1;
		int res = min(min(min_L[i - 1], min_R[i + 1]), max(mx, (i == n ? dis - 1 : (dis - 1) / 2)));
		// cout << dis << ' ' << mx << ' ' << res << endl; 
		if(i != n) res = min(res, dis);
		ans = max(ans, res);
		// cout << i << ' ' << res << endl;
	}
	cout << ans << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}