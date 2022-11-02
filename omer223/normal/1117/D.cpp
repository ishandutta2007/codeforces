#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> mat;

const ll mod = 1e9 + 7;
mat base, Id;

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
				res[i][j] %= mod;
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

int main() {
	fast;
	ll n, m;
	cin >> n >> m;
	Id.resize(m+1);
	base.resize(m+1);
	foru(i, 0, m+1) {
		Id[i].resize(m+1);
		base[i].resize(m+1);
		foru(j, 0, m + 1) {
			if (i <= 1) {
				if (!j or j == m)base[i][j] = 1;
			}
			else base[i][j] = (j == i - 1);
			Id[i][j] = (i == j);
		}
	}
	mat ret = matPow(n);
	cout << (ret[m][0] + ret[0][0]) % mod << '\n';
	return 0;
}