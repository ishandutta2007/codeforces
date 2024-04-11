#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MOD = 998244353;

inline int lgput(int a, int b) {
	int ans = 1;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> n >> m;

	vector<int> d(n + 1);
	int tot = 0;
	for(i = 1; i <= n; i++) {
		cin >> d[i];
		tot = (tot + d[i]) % MOD;
	}
	sort(d.begin(), d.end());
	
	vector<int> a(m + 1), b(m + 1);
	for(i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
	}

	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 1);
	sort(ord.begin(), ord.end(), [&](const int& x, const int& y) {
		if(b[x] == b[y]) return x < y;
		return b[x] > b[y];
	});

	vector<int> fact(n + 1, 1), invfact(n + 1, 1);
	for(i = 1; i <= n; i++) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		invfact[i] = lgput(fact[i], MOD - 2);
	}
	
	vector<int> sol(m + 1);
	int pos = n, sum = 0;
	for(auto p : ord) {
		while(pos > 0 && d[pos] >= b[p]) {
			sum = (sum + d[pos]) % MOD;
			pos--;
		}
		int x = n - pos;
		if(x >= a[p]) {
			sol[p] =  (1LL * (1LL * (x - a[p]) * sum % MOD) * lgput(x, MOD - 2)) % MOD;

			//cerr << p << " " << sol[p] << "\n";

			int coef = (1LL * a[p] * lgput(x + 1, MOD - 2)) % MOD;
			coef = (1 + MOD - coef) % MOD;

			//cerr << tot - sum << " " << coef << " " << p << "\n";
			sol[p] = (sol[p] + 1LL * (tot + MOD - sum) * coef) % MOD;
		}
	}

	for(i = 1; i <= m; i++) {
		cout << sol[i] << "\n";
	}
	
	
    return 0;
}