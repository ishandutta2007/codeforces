#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

const ll mod = 1e9 + 7;

void imult(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) + (rhs % mod)) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 225, psz = 15, gsz = 3;
ll dp[sz + 1][(1 << psz)][gsz + 1];
int n, T;
pii tg[psz];

int main() {
	fast;
	cin >> n >> T;
	foru(i, 0, n)cin >> tg[i].ff >> tg[i].ss;
    for (int i = 0; i < n; i++) {
        if (tg[i].ff > T)continue;
        iadd(dp[tg[i].ff][(1 << i)][tg[i].ss], 1);
    }
    for (int t = 1; t <= T; t++) {
        for (int msk = 0; msk < (1 << n); msk++) {
            for (int g = 1; g <= 3; g++) {
                for (int i = 0; i < n; i++) {
                    if ((msk >> i) & 1 || tg[i].ss == g || t + tg[i].ff > T)continue;
                    iadd(dp[t + tg[i].ff][msk | (1 << i)][tg[i].ss], dp[t][msk][g]);
                }
            }
        }
    }
    ll tot = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 1; j <= 3; j++)iadd(tot, dp[T][i][j]);
    }
    cout << tot;
	return 0;
}