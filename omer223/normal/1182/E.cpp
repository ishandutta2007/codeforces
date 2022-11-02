#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> mat;
const ll mod = 1e9 + 7, upmod = mod - 1;
const mat base{ {1,1,1},{1,0,0},{0,1,0} }, Id{ {1,0,0},{0,1,0},{0,0,1} };

mat mult(const mat& lhs, const mat& rhs) {
	int size = lhs.size();
	mat res;
	res.resize(size);
	foru(i, 0, size) {
		res[i].resize(size);
		fill(res[i].begin(), res[i].end(), 0);
	}
	foru(i, 0, size) {
		foru(j, 0, size) {
			foru(k, 0, size) {
				res[i][j] += lhs[i][k] * rhs[k][j];
				res[i][j] %= upmod;
			}
		}
	}
	return res;
}


mat matPow(ll k) {
	if (!k)return Id;
	mat tmp = matPow(k >> 1);
	tmp = mult(tmp, tmp);
	if (k & 1)tmp = mult(tmp, base);
	return tmp;
}

ll binPow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = binPow(a, b >> 1);
	tmp *= tmp;
	tmp %= mod;
	if (b & 1) {
		tmp *= a;
		tmp %= mod;
	}
	return tmp;
}

int main() {
	fast;
	ll n, c;
	ll f[3];
	cin >> n >> f[0] >> f[1] >> f[2] >> c;
	mat myMat = matPow(n - 3);
	ll ret = 1;
	foru(i, 0, 3) {
		ret *= binPow(f[2 - i], myMat[0][i]);
		ret %= mod;
	}
	ll tmp = 0;
	foru(i, 0, 3) {
		tmp += myMat[0][i] * (3 - i);
		tmp %= upmod;
	}
	tmp -= n;
	tmp %= upmod;
	if (tmp < 0)tmp += upmod;
	ret *= binPow(c, tmp);
	ret %= mod;
	cout << ret << endl;
	return 0;
}