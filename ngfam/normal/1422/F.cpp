#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int block = 320;
const int bound = 450;
const int mod = 1e9 + 7;
const int bound2 = 22;
const int LOG = 17;

int n;
int a[maxn], b[maxn];
int f[block][maxn];
int mark[maxn*2];

vector<vector<int>> cnt[maxn];
vector<int> factor[maxn*2], pos[maxn*2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 2; i < maxn * 2; ++i) {
		if(factor[i].size()) continue;
		for(int j = i; j < maxn * 2; j += i) {
			factor[j].push_back(i);
		}
	}

	/// Prepare primes greater than sqrt(max A)

	for(int i = 0; i < n; ++i) {
		b[i] = 1;
		if(a[i] == 1 || factor[a[i]].back() < bound) continue;	
		b[i] = factor[a[i]].back();
		a[i] /= b[i];
		pos[b[i]].push_back(i);
	}

	for(int i = 0; i < n; i += block) {
		int v = i / block, cur = 1;
		for(int j = i; j < n; ++j) {
			f[v][j] = cur;
			if(mark[b[j]]) continue;
			mark[b[j]] = 1;
			cur = f[v][j] = 1LL * f[v][j] * b[j] % mod;
		}
		for(int j = 0; j < n; ++j) mark[b[j]] = 0;
	}

	vector<int> prime_pow, prime_list; 

	for(int i = 2; i < bound; ++i) {
		if(factor[i].back() == i) {
			prime_list.push_back(i);
			int x = 1;
			prime_pow.push_back(0);
			while(x * i < maxn * 2) {
				x *= i;
				prime_pow.back()++;
			} 
		}
	}

	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			cnt[i].resize(prime_pow.size());
			for(int j = 0; j < prime_pow.size(); ++j) {
				cnt[i][j].resize(prime_pow[j] + 1, 0);
			}
		}
		else {
			cnt[i] = cnt[i - 1];
		}

		for(int j = 0; j < prime_pow.size(); ++j){
			int p = prime_list[j], deg = 0;
			while(a[i] % p == 0) {
				deg++;
				a[i] /= p;
			}
			++cnt[i][j][deg];
		}
	}

	int q; cin >> q;
	int last = 0;

	while(q--) {
		int x, y; cin >> x >> y;

		int l = (last + x) % n, r = (last + y) % n;
		
		if (l > r) swap(l, r);

		int nxt = l + (block - l % block), ans = 1;
		if(nxt < r) {
			int v = nxt / block;
			ans = f[v][r];
			for(int j = nxt - 1; j >= l; --j) {
				if(b[j] == 1) continue;
				auto fpos = upper_bound(pos[b[j]].begin(), pos[b[j]].end(), j);
				if(fpos == pos[b[j]].end() || *fpos > r) {
					ans = 1LL * ans * b[j] % mod;
				}
			}
		}
		else {
			for(int j = r; j >= l; --j) {
				if(b[j] == 1) continue;
				auto fpos = upper_bound(pos[b[j]].begin(), pos[b[j]].end(), j);
				if(fpos == pos[b[j]].end() || *fpos > r) {
					ans = 1LL * ans * b[j] % mod;
				}
			}	
		}


		for(int j = 0; j < prime_list.size(); ++j) {
			int p = prime_list[j], final_deg = 0;
			for(int k = prime_pow[j]; k >= 0; --k) {
				int u = 0, v = cnt[r][j][k];
				if (l > 0) u = cnt[l - 1][j][k];
				if(v > u) {
					final_deg = k;
					break;
				}
			}
			for(int k = 0; k < final_deg; ++k) {
				ans = 1LL * ans * p % mod;
			}
		}
		cout << ans << "\n";
		last = ans;
	}

	return 0;
}