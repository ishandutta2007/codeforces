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

vector<int> z_func(string s) {
	int n = sz(s);
	vector<int> z(n);
	int mx_id = 0	;
	for(int i = 1;i < n;i++) {
		// [i, max_el)
		// [i - id, max_el - id)

		int num = min(z[i - mx_id], max(0ll, mx_id + z[mx_id] - i));
		int id = i + num;
		while(id < sz(s) && s[id] == s[id - i]) id++;
		z[i] = id - i;
		if (mx_id + z[mx_id] < id) mx_id = i;
	}

	return z;
}

vector<int> z_func(string s, string t) {
	string a = s + '#' + t;
	vector<int> r1 = z_func(a);
	vector<int> r2(sz(t));
	for(int i = 0;i < sz(t);i++)
		r2[i] = r1[i + sz(s) + 1];
	return r2;
}


int n, m, k;

vector<int> pos(string s, string t) {
	vector<int> z = z_func(s, t);
	for(int i = 0;i < m;i++)
		chkmin(z[i], k);

	vector<int> lpos(m, m);

	for(int i = m - 1;i >= 0;i--) {
		if (0 <= i + z[i] - k) chkmin(lpos[i + z[i] - k], i);
		if (i < m - 1) chkmin(lpos[i], lpos[i + 1]);
	}
	for(int i = 0;i < m;i++)
		lpos[i] = min(i + k - lpos[i], n);

	int mn = inf;
	for(int i = m - 1;i >= 0;i--) {
		if (z[i] == n) mn = i;
		if (mn <= i + k - n) lpos[i] = n;
	}

	return lpos;
}

void solve() {
	string s, t;
	cin >> n >> m >> k >> s >> t;
	swap(s, t);
	swap(n, m);
	//t += "..........";
	
	vector<int> z = z_func(s, t);
	for(int i = 0;i < m;i++)
		if (z[i] >= n) {
			cout << ("Yes") << endl;
			int L = min(i + 1, m - 2 * k + 1);
			int R = L + k;
			cout << L << " " << R << endl;
			return;
		}


	vector<int> lpos = pos(s, t);
	reverse(all(s)), reverse(all(t));
	vector<int> rev_z = z_func(s, t);
	reverse(all(rev_z));

	vector<int> kpos(k + 1);
	
	vector<int> nx(k + 2);
	iota(all(nx), 0);
	function<int(int)> _get = [&nx, &_get](int v)->int {
		return (nx[v] == v ? v : nx[v] = _get(nx[v]));
	};

	for(int j = m - 1;j >= 0;j--) {
		int v = _get(max(0ll, j - m + k + 1));
		while(v <= min(rev_z[j], k)) {
			kpos[v] = j + k - v;
			nx[v] = v + 1;
			v = _get(v);
		}
	}

	int r1 = -1, r2 = -1;
	for(int i = 0;i < m;i++) {
		int num = n - lpos[i];
		if (num <= k && kpos[num] >= i + 2 * k - 1) {
			r1 = i;
			r2 = kpos[num] - k + 1;
		}
	}

	if (r1 == -1) cout << "No";
	else {
		cout << "Yes" << endl << r1 + 1 << " " << r2 + 1 << endl;
	}	
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}