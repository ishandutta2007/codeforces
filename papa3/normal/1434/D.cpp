#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

const int baza = 1 << 20;

vector<pair<int, int> > drogi[baza];
pair<int, int> kra[baza];
int n;

struct Algo {
	pair<int, int> drz[baza * 2];
	pair<int, int> zakres[baza * 2];
	int rotate[baza * 2];
	int ojciec[baza * 2];
	
	Algo(int root) {
		for (int i = 0; i < 2 * baza; i++) {
			drz[i] = {0, 0};
			rotate[i] = 0;
		}
		dfs(root);
		for (int i = baza - 1; i > 0; i--) {
			drz[i].first = max(drz[i * 2].first, drz[i * 2 + 1].first);
			drz[i].second = max(drz[i * 2].second, drz[i * 2 + 1].second);
		}
		if (debug) {
			cerr << " root = " << root << endl;
			for (int i = 1; i <= n; i++) {
				cerr << "z: " << zakres[i].first << " " << zakres[i].second << endl;
			}
		}
		cerr << "initilazied" << endl;
	}
	
	vector<int> run(const vector<int> &v) {
		vector<int> res;
		for (int i : v) {
			int a = kra[i].first;
			int b = kra[i].second;
			if (ojciec[a] != b) swap(a, b);
			cerr << " " << i << "   " << a << " " << b << endl;
			cerr << " a = " << a << "   " << zakres[a].first << " " << zakres[a].second << endl;
			zmien(zakres[a].first, zakres[a].second);
			res.push_back(drz[1].first);
		}
		return res;
	}
	
	int li = 0;
	void dfs(int gdzie, int skad = -1, int gl = 0, int xo = 0) {
		ojciec[gdzie] = skad;
		int id = li++;
		zakres[gdzie].first = id;
		if (xo == 0)
			drz[baza + id].first = gl;
		else
			drz[baza + id].second = gl;
		
		for (auto &[i, j] : drogi[gdzie]) {
			if (i == skad) continue;
			dfs(i, gdzie, gl + 1, xo ^ j);
		}
		
		zakres[gdzie].second = li;
	}
	
	void zmien(int pyt_pocz, int pyt_kon, int pocz = 0, int kon = baza, int gdzie = 1) {
		if (pyt_pocz <= pocz && kon <= pyt_kon) {
			swap(drz[gdzie].first, drz[gdzie].second);
			rotate[gdzie] ^= 1;
			return;
		}
		
		if (pyt_kon <= pocz || kon <= pyt_pocz) {
			return;
		}
		
		int sr = (pocz + kon) / 2;
		zmien(pyt_pocz, pyt_kon, pocz, sr, gdzie * 2);
		zmien(pyt_pocz, pyt_kon, sr, kon, gdzie * 2 + 1);
		
		drz[gdzie].first = max(drz[gdzie * 2].first, drz[gdzie * 2 + 1].first);
		drz[gdzie].second = max(drz[gdzie * 2].second, drz[gdzie * 2 + 1].second);
		if (rotate[gdzie]) swap(drz[gdzie].first, drz[gdzie].second);
	}
};

pair<int, int> dfs(int gdzie, int skad = -1) {
	pair<int, int> res = {-1, gdzie};
	
	for (auto &[i, _] : drogi[gdzie]) {
		if (i == skad) continue;
		maxi(res, dfs(i, gdzie));
	}
	
	res.first++;
	return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int a, b, c, i = 1; i < n; i++) {
		cin >> a >> b >> c;
		kra[i] = {a, b};
		drogi[a].push_back({b, c});
		drogi[b].push_back({a, c});
	}
	
	int a = dfs(1).second;
	int b = dfs(a).second;
	
	int m;
	cin >> m;
	vector<int> v(m);
	for (int &i : v) cin >> i;
	
	vector<int> x = Algo(a).run(v);
	vector<int> y = Algo(b).run(v);
	
	for (int i = 0; i < m; i++) {
		cout << max(x[i], y[i]) << "\n";
	}
	
    
    return 0;
}/*

*/