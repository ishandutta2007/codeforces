#include <bits/stdc++.h>

#define int long long
using namespace std;

int A[200001];
int s[200001];
map<int, int> M;
vector<pair<int, int>> vip;

int mod = 1e9 + 7;
int fact[200001];

int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int modinv(int a){
	return powmod(a, mod - 2);
}

int C(int n, int r){
	if(r > n) return 0;
	return fact[n] * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod;
}

void sub(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	M.clear();
	vip.clear();
	for(int i = 0; i < n; i++){
		M[A[i]]++;
	}
	for(auto i : M){
		vip.push_back(i);
	}
	
	vip.push_back({1LL << 60, 0});
	int ans = 0;
	s[0] = 0;
	for(int i = 0; i < (int) vip.size() - 1; i++){
		s[i + 1] = s[i] + vip[i].second;
	}
	for(int i = 0; i < (int) vip.size() - 1; i++){
		int idx = upper_bound(vip.begin(), vip.end(), pair<int, int>{vip[i].first + k + 1, 0LL}) - vip.begin();
		int cnt = s[idx] - s[i + 1];
		int cnt_0 = vip[i].second;
		ans = ((ans + C(cnt_0 + cnt, m) - C(cnt, m)) % mod + mod) % mod;
	}
	cout << ans << endl;
}

int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}