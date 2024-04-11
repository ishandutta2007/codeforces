#define _CRT_SECURE_NO_WARNINGS
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


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using namespace std;
const ll mod = 998244353;

void imult(ll& lhs, const ll& rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
	lhs = ((lhs%mod) + (rhs%mod)) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll& x) {
	return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
	return ((lhs%mod) + (rhs%mod)) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll div(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}

const ll sz = 1e3 + 5;
string x[2];
int n[2];
ll dp[sz][sz][2];//can add both,only first,only second
int isvalid[sz][2];

void initvalid() {
	foru(i, 0, 2) {
		bool bad = 0;
		isvalid[n[i] - 1][i] = 1;
		ford(j, n[i] - 2, 0) {
			if (x[i][j] == x[i][j + 1])isvalid[j][i] = 1;
			else isvalid[j][i] = isvalid[j + 1][i] + 1;
		}
	}
}

int main() {
	fast;
	cin >> x[0] >> x[1];
	n[0] = x[0].length();
	n[1] = x[1].length();
	initvalid();
	ll tot = 0;
	ford(i, n[0] - 1, 0) {
		ford(j, n[1] - 1, 0) {
			iadd(dp[i][j][0], isvalid[j][1] * (x[0][i] != x[1][j]));
			iadd(dp[i][j][1], isvalid[i][0] * (x[0][i] != x[1][j]));
			if (i != n[0] - 1) {
				if (x[0][i] != x[0][i + 1])iadd(dp[i][j][0], dp[i + 1][j][0]);
				if (x[0][i] != x[1][j])iadd(dp[i][j][0], dp[i + 1][j][1]);
			}
			if (j != n[1] - 1) {
				if (x[1][j] != x[1][j + 1])iadd(dp[i][j][1], dp[i][j + 1][1]);
				if (x[0][i] != x[1][j])iadd(dp[i][j][1], dp[i][j + 1][0]);
			}
			iadd(tot, add(dp[i][j][0], dp[i][j][1]));
		}
	}
	cout << tot << '\n';
	return 0;
}