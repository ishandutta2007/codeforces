#include <bits/stdc++.h>

using namespace std;

int A[300001];
int con[300001];
int f(int idx){
	return A[idx] < A[idx + 1] && A[idx + 1] > A[idx + 2] || A[idx] > A[idx + 1] && A[idx + 1] < A[idx + 2];
}

int n;

int best = 0;
int check(int idx, int val){
	int ori = A[idx];
	A[idx] = val;
	int res = 0;
	for(int i = idx - 2; i <= idx; i++){
		if(i < 0 || i >= n - 2) continue;
		res += f(i);
	}
	A[idx] = ori;
	best = min(best, res - con[idx]);
	return res;
}

void solve(){
	best = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i], con[i] = 0;
	int ans = 0;
	for(int i = 0; i < n - 2; i++){
		if(f(i)){
			con[i]++, con[i + 1]++, con[i + 2]++, ans++;
		}
	}
	for(int i = 0; i < n; i++){
		check(i, -1);
		check(i, 1e9 + 1);
		if(i > 0) check(i, A[i - 1]);
		if(i > 0) check(i, A[i - 1] - 1);
		if(i > 0) check(i, A[i - 1] + 1);
		if(i < n - 1) check(i, A[i + 1]);
		if(i < n - 1) check(i, A[i + 1] - 1);
		if(i < n - 1) check(i, A[i + 1] + 1);
	}
	cout << ans + best << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}