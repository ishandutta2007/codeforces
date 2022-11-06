#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
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
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	bool rev = false;
	int onepos = -1;
	int siz = 1;
	std::vector<std::vector<int> > res;
	while (siz < n) {
		for (int i = 0; i < n; ++i) if (arr[i] == 1) onepos = i;
		int newpos = -1;
		for (int i = 0; i < n; ++i) if (arr[i] == siz + 1) newpos = i;
		vector<int> v;
		if (rev) {
			if (newpos < onepos) {
				if (onepos < n - 1)
					v.pb(n - 1 - onepos);
				for (int i = 0; i < siz; ++i)
					v.pb(1);
				int last = onepos - siz;
				v.pb(last - newpos + 1);
				if (newpos)
					v.pb(newpos);
				rev = !rev;
			} else {
				if (newpos < n - 1)
					v.pb(n - 1 - newpos);
				int first = onepos + 1;
				v.pb(newpos - first + 1);
				v.pb(siz);
				if (onepos - siz >= 0)
					v.pb(onepos - siz + 1);
			}
			reverse(all(v));
		} else {
			if (newpos < onepos) {
				if (onepos + siz < n)
					v.pb((n - 1) - (onepos + siz) + 1);
				v.pb(siz);
				int last = onepos - 1;
				v.pb(last - newpos + 1);
				if (newpos)
					v.pb(newpos);	
			} else {
				if (newpos < n - 1)
					v.pb((n - 1) - (newpos + 1) + 1);
				int first = onepos + siz;
				v.pb(newpos - first + 1);
				for (int i = 0; i < siz; ++i)
					v.pb(1);
				if (onepos - 1 >= 0)
					v.pb(onepos);
				rev = !rev;
			}
			reverse(all(v));
		}
		std::vector<std::vector<int> > a;
		int in = 0;
		for (int i = 0; i < v.size(); ++i) {
			vi aa;
			for (int j = 0; j < v[i]; ++j) {
				aa.pb(arr[in++]);
			}
			a.pb(aa);
		}
		print(a);
		reverse(all(a));
		print(a);
		in = 0;
		for (auto& vv: a)
			for (int& i: vv)
				arr[in++] = i;
		res.pb(v);
		siz++;
	}
	if (rev)
		cout << res.size() + 1 << ' ';
	else
		cout << res.size() << ' ';
	for (auto& vv : res) {
		cout << vv.size() << ' ';
		for (int rr : vv)
			cout << rr << ' ';
		cout << '\n';
	}
	if (rev) {
		cout << n << ' ';
		for (int i = 0; i < n; ++i)
			cout << 1 << ' ';
	}
	print(arr);
}