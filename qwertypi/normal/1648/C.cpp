#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define inf (1LL << 60)
#define mod 998244353

using namespace std;

int A[200001], B[200001];
int fact[200001];
int cnt[200001];
bool you_first[200001];

int powmod(int a, int b){
	if(b == 0) return 1;
	if(b % 2 == 1){
		int res = powmod(a, b / 2); return res * res % mod * a % mod;
	}else{
		int res = powmod(a, b / 2); return res * res % mod;
	}
}

int modinv(int a){
	return powmod(a, mod - 2);
}

struct fenwick{
	int bit[200001] = {0};
	int val[200001] = {0};
	int N = 200000;
	void add(int idx, int v){
		int rv = v; // (val[idx] + v) * (val[idx] + v) - val[idx] * val[idx];
		val[idx] += v;
		while(idx <= N){
			// cout << "add " << idx << ' ' << v << endl;
			bit[idx] += rv;
			idx += idx & -idx;
		}
	}
	void set(int idx, int v){
		while(idx <= N){
			bit[idx] = 0;
			idx += idx & -idx;
		}
	}
	int qry(int idx){
		int res = 0;
		while(idx > 0){
			res += bit[idx];
			idx -= idx & -idx;
		}
		return res;
	}
} ssq;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		cnt[A[i]]++;
	}
	for(int i = 0; i < n; i++){
		ssq.add(A[i], 1);
	}
	for(int i = 0; i < m; i++){
		cin >> B[i];
	}
	sort(A, A + n);
	int ans = 0;
	int prod = fact[n];
	for(int i = 0; i < n; i++){
		if(!you_first[A[i]]){
			prod = (prod * modinv(fact[cnt[A[i]]])) % mod; 
		}
		you_first[A[i]] = true;
	}
	// cout << prod << endl;
	for(int i = 0; i < m; i++){
		// cout << "answer " << i << ' ' << prod << ' ' << (prod * modinv(n - i)) % mod << ' ' << ssq.qry(B[i] - 1) << endl;
		ans += (prod * modinv(n - i)) % mod * ssq.qry(B[i] - 1) % mod;
		if(cnt[B[i]] > 0){
			prod = (prod * cnt[B[i]] % mod * modinv(n - i)) % mod;
			cnt[B[i]]--;
			ssq.add(B[i], -1);
		}else{
			if(i == n) ans++;
			break;
		}
	}
	ans %= mod;
	cout << ans << endl;
}

int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
}