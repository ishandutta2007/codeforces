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

const int sz = 1e3 + 5;
int n;
vector<vector<bool>> a;
pii pos[sz];
vector<pair<int, pii>> ret;

void sortByRows(int mode) {
	vector<pii> rcnt(n);
	vector<int> rid(n), rpl(n);
	foru(i, 0, n) {
		rid[i] = rpl[i] = i;
		rcnt[i].ss = i;
		foru(j, 0, n)rcnt[i].ff += a[i][j];
	}
	sort(rcnt.begin(), rcnt.end());
	foru(i, 0, n) {
		if (rcnt[i].ss != rid[i]) {
			int x = i, y = rpl[rcnt[i].ss];
			ret.push_back({ mode,{ x + 1,y + 1 } });
			swap(rid[x], rid[y]);
			swap(rpl[rid[x]], rpl[rid[y]]);
			swap(a[x], a[y]);
		}
	}
}

void sortByCols(int mode) {
	vector<pii> rcnt(n);
	vector<int> rid(n), rpl(n);
	foru(i, 0, n) {
		rid[i] = rpl[i] = i;
		rcnt[i].ss = i;
		rcnt[i].ff = 1e9;
		ford(j, n - 1, 0) {
			if (a[i][j])rcnt[i].ff = j;
		}
	}
	sort(rcnt.begin(), rcnt.end());
	foru(i, 0, n) {
		if (rcnt[i].ss != rid[i]) {
			int x = i, y = rpl[rcnt[i].ss];
			ret.push_back({ mode,{ x + 1,y + 1 } });
			swap(rid[x], rid[y]);
			swap(rpl[rid[x]], rpl[rid[y]]);
			swap(a[x], a[y]);
		}
	}
}

void transpose() {
	vector<vector<bool>> na(n, vector<bool>(n, false));
	foru(i, 0, n) {
		foru(j, 0, n)na[i][j] = a[j][i];
	}
	swap(a, na);
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	foru(i, 0, n)a[i].resize(n);
	foru(i, 0, n - 1) {
		cin >> pos[i].ff >> pos[i].ss;
		a[--pos[i].ff][--pos[i].ss] = 1;
	}
	sortByRows(1);
	transpose();
	sortByCols(2);
	cout << ret.size() << '\n';
	for (auto ii : ret)cout << ii.ff << ' ' << ii.ss.ff << ' ' << ii.ss.ss << '\n';
	return 0;
}