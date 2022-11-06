#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int C[1000102][21] = {};

int ld[1000002];

int MOD = 1e9 + 7;

void pre() {
	C[0][0] = 1;
	for (int n = 1; n < 1000101; ++n) {
		C[n][0] = 1;
		for (int r = 1; r < 21; ++r) {
			C[n][r] = C[n - 1][r] + C[n - 1][r - 1];
			if (C[n][r] > MOD) C[n][r] -= MOD;
		}
	}
}

void pre2() {
	for (int i = 0; i < 1000001; ++i) ld[i] = i;
	for (int i = 2; i < 1000001; ++i)
		if (ld[i] == i)
			for (int j = i * 2; j < 1000001; j += i)
				ld[j] = min(ld[j], i); 
}

int powm(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1ll;
    }
    return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	pre();
	pre2();
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		int y; cin >> y;
		std::vector<int> v;
		while (x != 1) {
			int cn = 0, ll = ld[x];
			while (ld[x] == ll) {
				x /= ll;
				cn++;
			}
			v.pb(cn);
		}
		int res = powm(2, y - 1, MOD);
		for (int i : v) {
			res = (res * C[i + y - 1][i]) % MOD;
		}
		cout << res << "\n";
	}
}