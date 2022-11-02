#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <map>

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
	lhs = ret + (ret < 0);
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

const int sz = 26;
ll f[sz], a[sz], n, k, kk[sz];

void prec() {
	f[0] = 1;
	for (int i = 1; i < sz; i++) f[i] = mult(f[i - 1], i);
}

ll calc(const ll& x, ll tsm, int amt, int i) {
	if (i == n) {
		if (tsm == x)return mult(f[amt], f[n - amt]);
		else return 0;
	}
	else return calc(x, tsm, amt, i + 1) + calc(x, tsm + a[i], amt + 1, i + 1);
}

map<pll, map<pii, int>> mem[2];
int mysz[2], offset[2];

void calcmap(ll sma, ll smb, int amta, int amtb, const int& ind, int i) {
	if (i == mysz[ind]) {
		mem[ind][{sma, smb}][{ amta, amtb }]++;
	}
	else {
		calcmap(sma, smb, amta, amtb, ind, i + 1);
		calcmap(sma + a[offset[ind] + i], smb, amta + 1, amtb, ind, i + 1);
		calcmap(sma, smb + a[offset[ind] + i], amta, amtb + 1, ind, i + 1);
	}
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	cin >> k;
	foru(i, 0, k)cin >> kk[i];
	prec();
	if (k == 0) {
		cout << f[n] << '\n';
	}
	else if (k == 1 || kk[0] == kk[1]) {
		cout << subt(f[n], calc(kk[0], 0, 0, 0)) << '\n';
	}
	else {
		if (kk[0] > kk[1])swap(kk[0], kk[1]);
		mysz[0] = n / 2;
		mysz[1] = n - mysz[0];
		offset[1] = mysz[0];
		ll tmp = add(calc(kk[0], 0, 0, 0), calc(kk[1], 0, 0, 0));
		foru(i, 0, 2)calcmap(0, 0, 0, 0, i, 0);
		ll sect = 0; //array instead of map
		for (auto x : mem[0]) {
			auto mp1 = x.ss;
			pll p = x.ff;
			if (mem[1].find({ kk[0] - p.ff,kk[1] - kk[0] - p.ss }) != mem[1].end()) {
				auto mp2 = mem[1][{ kk[0] - p.ff, kk[1] - kk[0] - p.ss }];
				for (auto it1 : mp1) {
					for (auto it2 : mp2) {
						ll mytmp = mult(mult(f[it1.ff.ff + it2.ff.ff], f[it1.ff.ss + it2.ff.ss]), f[n - it1.ff.ff - it2.ff.ff - it1.ff.ss - it2.ff.ss]);
						iadd(sect, mult(mytmp, mult(it1.ss, it2.ss)));
					}
				}
			}
		}
		ll uni = subt(tmp, sect);
		cout << subt(f[n], uni) << '\n';
	}
	return 0;
}