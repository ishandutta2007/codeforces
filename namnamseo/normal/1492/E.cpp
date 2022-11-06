#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

void fail() {
	cout << "No\n";
	exit(0);
}

const int maxn = int(2e5) + 10;

int n, m;
vector<vector<int>> mat;

int tmp[maxn];

void try_tmp() {
	rep(i, n) {
		int wc = 0;
		rep(j, m) if (mat[i][j] != tmp[j]) ++wc;
		if (wc > 2) return;
	}

	cout << "Yes\n";
	rep(j, m) {
		cout << tmp[j] << " \n"[j == m-1];
	}
	exit(0);
}

void try_wrong_column(int a, int b) {
	vector<int> wc;
	vector<pp> cand;

	copy(all(mat[0]), tmp);
	for (int i=1; i<n; ++i) {
		wc.clear();
		rep(j, m) if (j!=a && j!=b) {
			if (mat[0][j] != mat[i][j]) wc.pb(j);
		}

		if (wc.size() > 2u) return;
		if (wc.size() == 2u) {
			tmp[a] = mat[i][a];
			tmp[b] = mat[i][b];
			try_tmp();
			return;
		} else if (wc.size() == 1u) {
			cand.emplace_back(mat[i][a], mat[i][b]);
		} else {
			// 0 wrongs; redundant row
		}
	}

	if (cand.empty()) { try_tmp(); return; }
	pp cz = cand[0];

	// try left
	tmp[a] = cz.x; tmp[b] = mat[0][b];
	for (auto &c : cand) if (c.x != cz.x) {
		tmp[b] = c.y;
	}
	try_tmp();

	// try right
	tmp[a] = mat[0][a]; tmp[b] = cz.y;
	for (auto &c : cand) if (c.y != cz.y) {
		tmp[a] = c.x;
	}
	try_tmp();
}

int main()
{
	cppio();
	cin >> n >> m;
	mat.resize(n);

	for (auto &v : mat) {
		v.resize(m);
		for (int &x: v) cin >> x;
	}

	vector<int> wc;
	for (int i=1; i<n; ++i) {
		vector<int> twc;
		rep(j, m) if (mat[0][j] != mat[i][j]) twc.pb(j);
		if (twc.size() > 4u) fail();
		if (wc.size() < twc.size()) swap(wc, twc);
	}

	if (wc.size() <= 1u) {
		copy(all(mat[0]), tmp);
		try_tmp();
		fail();
	}

	int wcs = wc.size();
	rep(i, wcs) rep(j, i) {
		try_wrong_column(wc[j], wc[i]);
	}

	fail();

	return 0;
}