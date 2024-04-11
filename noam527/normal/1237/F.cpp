#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int mxn = 4000;

ll pw(ll b, ll e) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = (rtn * b) % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

ll F[mxn], FI[mxn];

ll choose(ll n, ll k) {
	if (n < k) return 0;
	return F[n] * FI[k] % md * FI[n - k] % md;
}

int tmp[mxn][mxn];

void work(const vector<int> &A, int D[mxn][mxn]) {

	int i1 = 0, i2 = 1;
	int sum = 0;
	for (int j = 0; j < mxn; j++)
		tmp[0][j] = 0;
	tmp[0][0] = 1;

	if (i2 == A[i1]) {
		i1++;
		i2 = 1;
	}
	else i2++;
	sum++;

	while (i1 < A.size()) {
		tmp[sum][0] = 1;
		for (int j = 1; j < mxn; j++) {
			tmp[sum][j] = 0;
			if (i2 >= 2) {
				if (sum == 1) {
					if (j == 1) tmp[1][j] = 1;
					else tmp[1][j] = 0;
				}
				else {
					tmp[sum][j] = (tmp[sum - 1][j] + tmp[sum - 2][j - 1]) % md;
				}
			}
			else {
				tmp[sum][j] = tmp[sum - 1][j];
			}
			//cout << "tmp " << sum << " " << j << " = " << tmp[sum][j] << '\n';
		}
		
		if (i2 == A[i1]) {
			i1++;
			i2 = 1;
		}
		else i2++;
		sum++;
	}
	for (int x = 0; x < mxn; x++) for (int y = 0; y < mxn; y++)
		D[x][y] = (ll)tmp[sum - 1][y] * choose(sum - 2 * y, x) % md;
}

int h, w, n;
int fr[mxn], fc[mxn];
vector<int> A, B;

int D[mxn][mxn], E[mxn][mxn];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++) fr[i] = 1;
	for (int i = 0; i < w; i++) fc[i] = 1;
	for (int i = 0, p[4]; i < n; i++) {
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		fr[p[0] - 1] = fr[p[2] - 1] = 0;
		fc[p[1] - 1] = fc[p[3] - 1] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		if (fr[i]) cnt++;
		else {
			if (cnt) A.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt) A.push_back(cnt);

	cnt = 0;
	for (int j = 0; j < w; j++) {
		if (fc[j]) cnt++;
		else {
			if (cnt) B.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt) B.push_back(cnt);

	if (A.size() == 0 || B.size() == 0) finish(1);

	F[0] = FI[0] = 1;
	for (int i = 1; i < mxn; i++) {
		F[i] = i;
		FI[i] = inv(i);
		F[i] = (F[i] * F[i - 1]) % md;
		FI[i] = (FI[i] * FI[i - 1]) % md;
	}
	if (OO) {
		for (const auto &i : A) cout << i << " "; cout << '\n';
	}
	work(A, D);
	work(B, E);
	if (OO) {
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
			cout << i << " " << j << " " << D[i][j] << '\n';
	}
	ll ans = 0;
	for (int x = 0; x < mxn; x++) for (int y = 0; y < mxn; y++) {
		ll add = F[x] * F[y] % md;
		add = add * (ll)D[x][y] % md;
		add = add * (ll)E[y][x] % md;
		ans = (ans + add) % md;
	}
	cout << ans << '\n';
}