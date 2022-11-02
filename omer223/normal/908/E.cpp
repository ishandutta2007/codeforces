#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7;

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

const int sz = 1e3;
int m;
bool a[sz][sz];
ll part[sz + 5];
int chs[sz + 1][sz + 1];
vector<int> adj[sz];
bitset<sz> vis;

int dfs(int src) {
	vis[src] = 1;
	int tot = 1;
	for (int x : adj[src]) {
		if (!vis[x])tot += dfs(x);
	}
	return tot;
}

void calcBell() {
	for (int i = 0; i <= sz; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j)chs[i][j] = 1;
			else chs[i][j] = add(chs[i - 1][j], chs[i - 1][j - 1]);
		}
	}
	part[0] = 1;
	for (int i = 1; i <= sz; i++) {
		foru(j, 0, i)iadd(part[i], mult(chs[i-1][j], part[j]));
	}
}

int main() {
	fast;
	int n;
	string s;
	cin >> m >> n;
	while (n--) {
		cin >> s;
		foru(i, 0, m) {
			foru(j, i + 1, m) {
				if (s[i] != s[j]) { a[i][j] = a[j][i] = 1; }
			}
		}
	}
	foru(i, 0, m) {
		foru(j, i + 1, m) {
			if (!a[i][j]) {
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	ll ret = 1;
	calcBell();
	foru(i, 0, m) {
		int tmp = dfs(i);
		imult(ret, part[tmp]);
	}
	cout << ret << '\n';
	return 0;
}