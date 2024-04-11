#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int a[100001];
int dp[100001];
int fa[100001];
const int MOD = 998244353;

int bp(int a, int b){
	if(b == 0) return 1;
	return bp(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

int mi(int a){
	return bp(a, MOD - 2);
}

int C(int n, int r){
	if(n < r) return 0;
	return fa[n] * mi(fa[r]) % MOD * mi(fa[n - r]) % MOD;
}

int f(int x, int y){
	int ans = 0;
	for(int i = 1; i <= min(x, y); i++){
		ans = (ans + C(x, i) * C(y, i)) % MOD;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int s = accumulate(a, a + n, 0LL);
	if(s == 0){
		cout << bp(2, n - 1) << endl;
		return;
	}
	set<int> SP;
	int leq = 0;
	for(int sp = 0, i = 0; i < n; i++){
		sp += a[i];
		SP.insert(sp);
		if(sp * 2 == s)
			leq++;
	}
	
	set<int> SS;
	for(int ss = 0, i = n - 1; i >= 0; i--){
		ss += a[i];
		SS.insert(ss);
	}
	
	int sp = 0, ss = 0;
	vector<int> vf, vb;
	for(int i = 0; i < n; i++){
		sp += a[i];
		if(sp <= s / 2 && SS.count(sp)){
			vf.push_back(i);
		}
	}
	for(int i = n - 1; i >= 0; i--){
		ss += a[i];
		if(ss <= s / 2 && SP.count(ss)){
			vb.push_back(i);
		}
	}
	
	vector<int> cf, cb;
	cf.push_back(0); cb.push_back(0);
	for(auto i : vf){
		if(a[i] == 0){
			cf.back()++;
		}else{
			cf.push_back(1);
		}
	}
	
	for(auto i : vb){
		if(a[i] == 0){
			cb.back()++;
		}else{
			cb.push_back(1);
		}
	}
	
	int ans = 1;
	assert(cf.size() == cb.size());
	for(int i = 0; i < cf.size(); i++){
		ans = ans * (f(cf[i], cb[i]) + 1) % MOD;
	}
	ans = ans * mi(f(leq, leq) + 1) % MOD * bp(2, leq) % MOD;
	cout << ans << endl;
}

int32_t main(){
	fa[0] = 1;
	for(int i = 1; i <= 100000; i++){
		fa[i] = fa[i - 1] * i % MOD;
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}