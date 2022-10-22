#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);

ll binPow(ll b, ll p, ll m) {
	ll res = 1;
	while(p) {if (p & 1) res = res * b % m; b = b * b % m; p >>= 1;}
	return res;
}

const int MOD[2] = {(int)1e9 + 7, (int)1e9 + 9};
const int P[2] = {37, 101};
ll p[2000000][2], ip[2000000][2];

vector<ar<ll, 2>> hsh(string& s) {
	int n = s.size();
	vector<ar<ll, 2>> res(n + 1, {0, 0});
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			res[i + 1][j] = (res[i][j] + s[i] * p[i][j]) % MOD[j];
		}
	}
	return res;
}

ar<ll, 2> get_range(int l, int r, vector<ar<ll, 2>>& h) { // [l, r] 0-indexed
	//assert(0 <= l && l <= r && r + 1 < h.size());
	ar<ll, 2> res;
	for (int i = 0; i < 2; ++i) {
		res[i] = (h[r + 1][i] - h[l][i] + MOD[i]) * ip[l][i] % MOD[i];
	}
	return res;
}

int n, q;
ll cnt[26], pre[100001][26];
ll two[100001], itwo[100001];
string s0, t;

void preprocess() {
	for (int j = 0; j < 2; ++j) {
		p[0][j] = ip[0][j] = 1;
		p[1][j] = P[j];
		ip[1][j] = binPow(P[j], MOD[j] - 2, MOD[j]);
		for (int i = 2; i < 2000000; ++i) {
			p[i][j] = p[i - 1][j] * p[1][j] % MOD[j];
			ip[i][j] = ip[i - 1][j] * ip[1][j] % MOD[j];
		}
	}
	two[0] = itwo[0] = 1;
	two[1] = 2;
	itwo[1] = binPow(2, MOD[0] - 2, MOD[0]);
	for (int i = 2; i <= 100000; ++i) {
		two[i] = two[i - 1] * 2 % MOD[0];
		itwo[i] = itwo[i - 1] * itwo[1] % MOD[0];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			pre[i + 1][j] = pre[i][j];
		}
		int c = t[i] - 'a';
		pre[i + 1][c] = (pre[i + 1][c] + two[n - i - 1]) % MOD[0];
	}
}

void solve(int k, string& w) {
	memset(cnt, 0, sizeof(cnt));
	string s = s0;
	int cur = 0;
	for (; cur < k && s.size() < w.size(); ++cur) {
		s = s + t[cur] + s;
	}
	if (s.size() < w.size()) {cout << "0\n"; return;}
	vector<ar<ll, 2>> hs = hsh(s);
	vector<ar<ll, 2>> hw = hsh(w);
	int base = 0;
	for (int i = 0; i + (int)w.size() - 1 < s.size(); ++i)
		base += get_range(i, i + w.size() - 1, hs) == hw.back();
	for (int i = 0; i < w.size(); ++i) {
		if (get_range(0, i - 1, hw) == get_range(s.size() - i, s.size() - 1, hs)
		 && get_range(i + 1, w.size() - 1, hw) == get_range(0, w.size() - i - 2, hs)) {
			++cnt[w[i] - 'a'];
		}
	}
	ll ans = base * two[k - cur];
	for (int i = 0; i < 26; ++i) {
		ans = (ans + cnt[i] * (pre[k][i] - pre[cur][i] + MOD[0]) % MOD[0] * itwo[n - k]) % MOD[0];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s0 >> t;
	preprocess();
	for (int i = 0; i < q; ++i) {
		int k; cin >> k;
		string w; cin >> w;
		solve(k, w);
	}
	return 0;
}