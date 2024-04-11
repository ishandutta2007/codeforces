#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1e5 + 3, log_n = 20;

int n;
int a[max_n];

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];


	int res = inf;


	// a[i] - 2 * i    + t
	// a[i]            - t



	// a[i] - i        + t
	// a[i] + i        - t

	vector<vector<int>> sp_l(n, vector<int>(log_n)), sp_r(n, vector<int>(log_n));
	for(int i = 0;i < n;i++)
		sp_l[i][0] = a[i] - i, sp_r[i][0] = a[i] + i;
	for(int k = 1;k < log_n;k++) {
		for(int i = 0;i + (1 << k) < n;i++) {
			sp_l[i][k] = min(sp_l[i][k - 1], sp_l[i + (1 << (k - 1))][k - 1]);
			sp_r[i][k] = min(sp_r[i][k - 1], sp_r[i + (1 << (k - 1))][k - 1]);
		}
	}
	//cout << sp_r[3][0] << endl;

	function<int(int, int)> g1 = [&sp_l](int l, int r) {
		if (l > r) return inf;
		int ln = 0;
		while((1 << (ln + 1)) < r - l + 1) ln++;
		if (ln == 0) return sp_l[l][0];
		return min(sp_l[l][ln], sp_l[r - (1 << ln) + 1][ln]);
	};

	function<int(int, int)> g2 = [&sp_r](int l, int r) {
		if (l > r) return inf;
		int ln = 0;
		while((1 << (ln + 1)) < r - l + 1) ln++;
		if (ln == 0) return sp_r[l][0];
		return min(sp_r[l][ln], sp_r[r - (1 << ln) + 1][ln]);
	};

	//cout << sp_l[0][1] << " " << sp_l[1][1] << endl;
	//cout << g1(0, 2) << endl;


	function<int(int)> f1 = [](int v) {return a[v] - 2 * v;};
	function<int(int)> f2 = [](int v) {return a[v];};
	function<int(int)> f3 = [](int v) {return a[v] - v;};
	function<int(int)> f4 = [](int v) {return a[v] + v;};

	auto cmp1 = [f1](int v1, int v2) {
		if (f1(v1) == f1(v2)) return v1 < v2;
		return f1(v1) > f1(v2);
	};
	auto cmp2 = [f2](int v1, int v2) {
		if (f2(v1) == f2(v2)) return v1 < v2;
		return f2(v1) < f2(v2);
	};
	auto cmp3 = [f3](int v1, int v2) {
		if (f3(v1) == f3(v2)) return v1 < v2;
		return f3(v1) < f3(v2);
	};
	auto cmp4 = [f4](int v1, int v2) {
		if (f4(v1) == f4(v2)) return v1 < v2;
		return f4(v1) < f4(v2);
	};

	set<int, decltype(cmp1)> t_l(cmp1);
	set<int, decltype(cmp2)> t_r(cmp2);
	set<int, decltype(cmp3)> s_l(cmp3);
	set<int, decltype(cmp4)> s_r(cmp4);
	set<int> t_all;

	for(int i = 0;i < n;i++) {
		if (f2(i) > 0) t_r.emplace(i);
		else t_all.emplace(i), s_r.emplace(i);
	}


	for(int t = 0;t < n;t++) {
		while(sz(t_r) && f2(*t_r.begin()) - t <= 0) {
			if ((*t_r.begin()) > t) t_all.emplace(*t_r.begin()), s_r.emplace(*t_r.begin());
			t_r.erase(t_r.begin());
		}
		while(sz(t_l) && f1(*t_l.begin()) + t > 0) {
			t_all.erase(*t_l.begin());
			s_l.erase(*t_l.begin());
			t_l.erase(t_l.begin());
		}
		if (a[t] <= t) {
			s_l.emplace(t);
			s_r.erase(t);
			t_l.emplace(t);
			t_all.emplace(t);
		}

		/*for(int i : s_l)
			cout << i << " ";
		cout << endl;*/

		int nres = inf;	
		if (sz(s_l)) nres = f3(*s_l.begin()) + t;
		if (sz(s_r)) chkmin(nres, f4(*s_r.begin()) - t);

		int ri = (sz(t_all) ? (*t_all.begin()) : n);
		int r1 = g1(0, min(t - 1, ri - 1)) + t;
		//cout << t << " " << nres << " " << ri << " " << r1 << endl;
		chkmin(r1, g2(t, ri - 1) - t);


		/*for(int i = 0;i < ri;i++) {
			//if (a[i] + abs(t - i) <= i) break;
			chkmin(r1, a[i] + abs(t - i));
		}*/
		chkmin(res, max(r1, nres));
	}

	cout << (res == inf ? -1 : res) << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}