#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;

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

const int sz = 1e6 + 5;
set<int> rws0e[sz], rws1e[sz], cls0e[sz], cls1e[sz], rwscon, clscon, nerw, necl;
set<pii> zch, och;
map<pii, int> board;
int n, m, k;
ll cur;

void add0(int x, int y) {
	board[{x, y}] = 0;
	if ((x + y) & 1)och.insert({ x,y });
	else zch.insert({ x,y });
	if (x & 1)cls1e[y].insert(x);
	else cls0e[y].insert(x);
	if (y & 1)rws1e[x].insert(y);
	else rws0e[x].insert(y);
	if (!rws1e[x].empty() && !rws0e[x].empty())rwscon.insert(x);
	if (!cls1e[y].empty() && !cls0e[y].empty())clscon.insert(y);
	nerw.insert(x);
	necl.insert(y);
}

void add1(int x, int y) {
	board[{x, y}] = 1;
	if ((x + y) & 1)zch.insert({ x,y });
	else och.insert({ x,y });
	if (x & 1)cls0e[y].insert(x);
	else cls1e[y].insert(x);
	if (y & 1)rws0e[x].insert(y);
	else rws1e[x].insert(y);
	if (!rws1e[x].empty() && !rws0e[x].empty())rwscon.insert(x);
	if (!cls1e[y].empty() && !cls0e[y].empty())clscon.insert(y);
	nerw.insert(x);
	necl.insert(y);
}

void del0(int x, int y) {
	board.erase({ x,y });
	if ((x + y) & 1)och.erase({ x,y });
	else zch.erase({ x,y });
	if (x & 1)cls1e[y].erase(x);
	else cls0e[y].erase(x);
	if (y & 1)rws1e[x].erase(y);
	else rws0e[x].erase(y);
	if (rws1e[x].empty() || rws0e[x].empty())rwscon.erase(x);
	if (cls1e[y].empty() || cls0e[y].empty())clscon.erase(y);
	if (rws1e[x].empty() && rws0e[x].empty())nerw.erase(x);
	if (cls1e[y].empty() && cls0e[y].empty())necl.erase(y);
}

void del1(int x, int y) {
	board.erase({ x,y });
	if ((x + y) & 1)zch.erase({ x,y });
	else och.erase({ x,y });
	if (x & 1)cls0e[y].erase(x);
	else cls1e[y].erase(x);
	if (y & 1)rws0e[x].erase(y);
	else rws1e[x].erase(y);
	if (rws1e[x].empty() || rws0e[x].empty())rwscon.erase(x);
	if (cls1e[y].empty() || cls0e[y].empty())clscon.erase(y);
	if (rws1e[x].empty() && rws0e[x].empty())nerw.erase(x);
	if (cls1e[y].empty() && cls0e[y].empty())necl.erase(y);
}

void upd(int x, int y, int t) {
	if (t == -1 || (board.find({ x,y }) != board.end())) {
		if (board[{x, y}] == 0)del0(x, y);
		else del1(x, y);
	}
	if (t == 0) {
		add0(x, y);
	}
	else if (t == 1) {
		add1(x, y);
	}
	if (rwscon.empty() && clscon.empty()) {
		cur = add(bpw(2, m - necl.size()), bpw(2, n - nerw.size()));
		if (zch.empty())isubt(cur, 1);
		if (och.empty())isubt(cur, 1);
	}
	else {
		if (!rwscon.empty() && !clscon.empty())cur = 0;
		else if (!rwscon.empty()) {
			cur = bpw(2, m - necl.size());
		}
		else if (!clscon.empty()) {
			cur = bpw(2, n - nerw.size());
		}
	}
}

int main() {
	fast;
	cin >> n >> m >> k;
	cur = subt(add(bpw(2, n), bpw(2, m)), 2);
	while (k--) {
		int x, y, t;
		cin >> x >> y >> t;
		upd(--x, --y, t);
		cout << cur << '\n';
	}
	return 0;
}