#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef print
#define print(...)
#define trace(...)
// #define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod=998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

set<int> pos;
int a[5000];

int ask(set<int> ss) {
	cout << "? ";
	for (int aa : ss) {
		cout << aa + 1 << " ";
	}
	cout << endl;
	int po; cin >> po;
	int el; cin >> el;
	a[po - 1] = el;
	pos.insert(po - 1);
	return po - 1;
}

void askf() {
	cout << "? ";
	std::vector<int> v;
	for (int aa : pos) {
		cout << aa + 1 << " ";
		v.pb(aa);
	}
	cout << endl;
	int po; cin >> po;
	int el; cin >> el;
	a[po - 1] = el;
	po--;
	sort(v.begin(), v.end(), [](int i, int j) {
		return a[i] < a[j];
	});
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == po)
			cout << "! " << i + 1;
	cout << endl;
}

void deter(int n, int k) {
	set<int> ss;
	int ii = k;
	for (int i = 0; i < k; ++i) {
		ss.insert(i);
	}
	for (int i = 0; i < k; ++i) {
		ss.erase(ask(ss));
		ss.insert(ii++);
	}
	askf();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	if (k == 1) {
		cout << "! 1" << endl;
		return 0;
	}
	// if ((n + 1) / 2 >= k) {
	// 	deter();
	// } else {
		set<int> ss;
		int ii = k;
		for (int i = 0; i < k; ++i) {
			ss.insert(i);
		}
		for (int i = 0; i < n - k + 1; ++i) {
			ss.erase(ask(ss));
			ss.insert(ii++);
		}
		ss.erase(ii - 1);
		int i1 = *pos.begin();
		for (int i22 : pos) {
			// cout << a[i22] << endl;
			if (a[i22] < a[i1]) {
				i1 = i22; 
			}
		}
		pos.erase(i1);
		int i2 = *pos.begin();
		int m = 1;
		// cout << i1 << ' ' << i2 << endl;
		for (int u : ss) {
			set<int> y = ss;
			y.erase(u);
			y.insert(i1);
			y.insert(i2);
			// int yy = ask(y);
			// cout << yy << " " << i1 << " " << i2 << endl;
			if (ask(y) == i2) {
				m++;
			}
		}
		cout << "! " << m << endl;
	// }
}