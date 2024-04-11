#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

const int N = 100005, K = 300;

ll dp[21][N];

int sieve[N];
int mu[N], ps[N];
int phi[N];
ll cop[N];

vector<int> divi[N];


int curl = md, curr = md;
ll curv = 0;

ll c(int l, int r) {
	if (curl == md) {
		curl = curr = r;
		curv = 1;
	}
	while (l < curl) {
		--curl;
		curv += cop[curr / curl];
	}
	while (curr < r) {
		++curr;
		for (const auto &i : divi[curr])
			if (curl <= i)
				curv += phi[curr / i];
	}
	while (curl < l) {
		curv -= cop[curr / curl];
		curl++;
	}
	while (r < curr) {
		for (const auto &i : divi[curr])
			if (curl <= i)
				curv -= phi[curr / i];
		curr--;
	}
	//cout << "c of " << l << " " << r << " = " << curv << '\n';
	return curv;
}

void calc(int k, int l, int r, int optl, int optr) {
	if (OO) {
		cout << "calc " << k << " " << l << " " << r << " " << optl << " " << optr << '\n';
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	if (OO) {
		cout << "finding for " << mid << '\n';
	}
	dp[k][mid] = inf;
	int at = -1;
	for (int i = min(optr, mid); i >= optl && i >= 1; i--) {
		ll x = dp[k - 1][i - 1] + c(i, mid);
		if (x < dp[k][mid]) {
			dp[k][mid] = x;
			at = i;
		}
	}
	calc(k, l, mid - 1, optl, at);
	calc(k, mid + 1, r, at, optr);
}


void init() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				divi[i].push_back(j);
				if (j != i / j)
					divi[i].push_back(i / j);
			}
		}
	}

	sieve[1] = 1;
	for (int i = 2; i < N; i++) {
		if (sieve[i] == 0) {
			for (int j = i; j < N; j += i)
				if (sieve[j] == 0)
					sieve[j] = i;
		}
	}
	mu[1] = 1;
	phi[1] = 1;
	for (int i = 2; i < N; i++) {
		int p = sieve[i];
		int cnt = 0, tmp = i;
		while (tmp % p == 0) {
			tmp /= p;
			cnt++;
		}
		if (cnt == 1)
			mu[i] = -mu[i / p];
		else
			mu[i] = 0;

		if (tmp == 1) phi[i] = i - i / p;
		else
			phi[i] = phi[tmp] * phi[i / tmp];
	}
	ps[0] = 0;
	for (int i = 1; i < N; i++)
		ps[i] = ps[i - 1] + mu[i];

	cop[1] = 1;
	for (int i = 2; i < N; i++)
		cop[i] = cop[i - 1] + phi[i];

	for (int i = 1; i < N; i++)
		dp[1][i] = (ll)i * (i + 1) / 2;
	for (int layer = 2; layer < 21; layer++) {
		calc(layer, layer, N - 1, layer, N - 1);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (k >= 21) {
		cout << n << '\n';
		return;
	}
	cout << dp[k][n] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	init();
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}