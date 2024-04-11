#include <bits/stdc++.h>
// Uncertainty principle.
// If you are persistent enough, you can build a segtree.
using namespace std;
#define int long long
// why always ka long long ...
// WTF is TLE????
// lmao Wrong every TC 2... 
int b[300001];
int del[300001];
int dp[1 << 15];

struct BIT{
	int n;
	int bit[400003] = {0};
	void init(int n){
		this->n = n + 2;
		fill(bit, bit + n + 3, 0);
	}
	void add(int p, int v){
		while(p <= n){
			bit[p] += v;
			p += p & -p;
		}
	}
	int qry(int p){
		int res = 0;
		while(p){
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
} bit0, bit1, bit2;
int n, k;
int qry(int idx){
	int ans = (idx + 1) * bit0.qry(idx) + bit1.qry(idx) + bit2.qry(idx);
	return ans;
}

void upd(int idx, int val){
	bit0.add(idx, val);
	bit1.add(idx, -idx * val);
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		cin >> n >> k;
		bit0.init(n), bit1.init(n), bit2.init(n);
		for(int i = 1; i <= n; i++){
			cin >> b[i];
			bit2.add(i, b[i] - b[i - 1]);
		}
		int ans = 0;
		for(int i = n; i >= 1; i--){
			int v = max(0LL, qry(i));
			v = (v + min(i, k) - 1) / min(i, k);
			ans += v;
			upd(max(i, k) - (k - 1), -v);
			upd(max(i, k) - (k - 1) + k, (k + 1) * v);
			upd(max(i, k) - (k - 1) + k + 1, -k * v);
		}
		cout << ans << endl;
	}
}