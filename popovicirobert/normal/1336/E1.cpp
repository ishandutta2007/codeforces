#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MOD = 998244353;

vector<ll> BuildLiniarBase(vector<ll> &a, int m) {
	vector<int> ids(m, -1);
	vector<ll> base;
	int n = (int)a.size();

	for(int i = 0; i < n; i++) {
		for(int j = m - 1; j >= 0; j--) {
			if(a[i] & (1LL << j)) {
				if(ids[j] != -1) {
					a[i] ^= a[ids[j]];
				}
				else {
					ids[j] = i;
					break;
				}
			}
		}
	}
	for(int j = m - 1; j >= 0; j--) {
		if(ids[j] == -1) continue;
		for(int i = 0; i < n; i++) {
			if(i == ids[j]) continue;
			if(a[i] & (1LL << j)) {
				a[i] ^= a[ids[j]];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(a[i]) {
			base.push_back(a[i]);
		}
	}
	return base;
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

  	cin >> n >> m;
  	vector<ll> a(n);
  	for(i = 0; i < n; i++) {
  		cin >> a[i];
  	}

  	vector<ll> base = BuildLiniarBase(a, m);
  	int sz = (int)base.size();
  	vector<int> ans(m + 1);

  	if(sz <= 20) {
  		for(int mask = 0; mask < (1 << sz); mask++) {
  			ll cur = 0;
  			for(i = 0; i < sz; i++) {
  				if(mask & (1 << i)) {
  					cur ^= base[i];
  				}
  			}
  			ans[__builtin_popcountll(cur)]++;
  		}
  	}
  	else {
  		assert(m >= sz);

  		vector<bool> inBase(m);
  		for(auto it : base) {
  			for(i = m - 1; i >= 0; i--) {
  				if(it & (1LL << i)) {
  					inBase[i] = 1;
  					break;
  				}
  			}
  		}
  		vector<int> bits;
  		for(i = 0; i < m; i++) {
  			if(inBase[i] == 0) {
  				bits.push_back(i);
  			}
  		}

  		vector<vector<int>> dp(sz + 1, vector<int>(1 << (m - sz)));
  		dp[0][0] = 1;
  		for(int t = 0; t < sz; t++) {
  			int cur_mask = 0;
			for(int j = 0; j < m - sz; j++) {
				if(base[t] & (1LL << bits[j])) {
					cur_mask ^= (1 << j);
				}
			}
	  		for(i = sz - 1; i >= 0; i--) {
	  			for(int mask = 0; mask < (1 << (m - sz)); mask++) {
	  				if(dp[i][mask] == 0) continue;
	  				dp[i + 1][mask ^ cur_mask] = (dp[i + 1][mask ^ cur_mask] + dp[i][mask]) % MOD;
	  			}
	  		}
  		}
  		for(i = 0; i <= sz; i++) {
	  		for(int mask = 0; mask < (1 << (m - sz)); mask++) {
	  			int cur = __builtin_popcountll(mask);
	  			ans[cur + i] = (ans[cur + i] + dp[i][mask]) % MOD;
	  		}
  		}
  	}

  	int coef = 1;
  	for(i = 0; i < n - sz; i++) {
  		coef = (coef * 2) % MOD;
  	}

  	for(i = 0; i <= m; i++) {
  		ans[i] = (1LL * ans[i] * coef) % MOD;
  		cout << ans[i] << " ";
  	}

    return 0;
}